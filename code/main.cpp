#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

#include "User.h"
#include "Listing.h"
#include "Category.h"
#include "Conversation.h"
#include "Message.h"
#include "ContactExchange.h"
#include "Favorite.h"
#include "Report.h"
#include "AuditLog.h"
#include "Utils.h" // For GetCurrentTimestamp()

// Function to generate a simple UUID-like string for demonstration
std::string generate_uuid() {
    static int counter = 0;
    return "uuid-" + std::to_string(++counter);
}

int main() {
    std::cout << "--- 演示网络商城系统类 ---" << std::endl << std::endl;

    // 1. 创建用户
    std::cout << "正在创建用户..." << std::endl;
    domain::User user1(generate_uuid(), "13800000001", "Alice", "CampusA", "CS", domain::RoleType::USER);
    domain::User user2(generate_uuid(), "13900000002", "Bob", "CampusB", "EE", domain::RoleType::USER);
    domain::User admin_user(generate_uuid(), "13000000000", "Admin", "Main", "Admin", domain::RoleType::ADMIN);
    std::cout << std::endl;

    // 演示用户方法
    user1.SetPassword("password123");
    user1.VerifySmsCode("123456");
    user1.set_email("alice@example.com");
    std::cout << "用户 1 状态: " << (user1.status() == domain::UserStatus::ACTIVE ? "活跃" : "待验证") << std::endl;
    std::cout << std::endl;

    // 2. 创建类别
    std::cout << "正在创建类别..." << std::endl;
    domain::Category electronics_cat(generate_uuid(), "电子产品");
    domain::Category phones_cat(generate_uuid(), "手机", electronics_cat.id());
    domain::Category books_cat(generate_uuid(), "书籍");
    std::cout << std::endl;

    // 3. 创建商品
    std::cout << "正在创建商品..." << std::endl;
    domain::Listing listing1(generate_uuid(), user1.id(), "iPhone 13 Pro", "九成新，使用 6 个月。",
                             800.00, domain::Condition::LIKE_NEW, phones_cat.id(), user1.campus(), domain::DeliveryType::BOTH);
    listing1.AddImage("http://example.com/iphone1.jpg");
    listing1.AddImage("http://example.com/iphone2.jpg");
    listing1.Publish();
    std::cout << "商品 1 状态: " << (listing1.status() == domain::ListingStatus::PUBLISHED ? "已发布" : "草稿") << std::endl;
    std::cout << std::endl;

    domain::Listing listing2(generate_uuid(), user2.id(), "C++ 编程书籍", "状况良好，有少量划线。",
                             25.50, domain::Condition::GOOD, books_cat.id(), user2.campus(), domain::DeliveryType::PICKUP);
    listing2.Publish();
    std::cout << std::endl;

    // 4. 用户 2 收藏商品 1
    std::cout << "用户 2 正在收藏商品 1..." << std::endl;
    domain::Favorite fav1(user2.id(), listing1.id());
    std::cout << std::endl;

    // 5. 创建会话
    std::cout << "正在为商品 1 创建用户 2 (买家) 和用户 1 (卖家) 之间的会话..." << std::endl;
    domain::Conversation conv1(generate_uuid(), user2.id(), user1.id(), listing1.id());
    std::cout << std::endl;

    // 6. 会话中交换消息
    std::cout << "正在交换消息..." << std::endl;
    domain::Message msg1(generate_uuid(), conv1.id(), user2.id(), "你好，iPhone 还在吗？");
    domain::Message msg2(generate_uuid(), conv1.id(), user1.id(), "是的，还在！你感兴趣吗？");
    std::cout << std::endl;

    // 7. 联系方式交换
    std::cout << "正在启动联系方式交换..." << std::endl;
    domain::ContactExchange ce1(conv1.id());
    ce1.ProvideBuyerContact("user2_wechat_id");
    ce1.ProvideSellerContact("user1_phone_number");
    std::cout << "买家联系方式 (确认前): " << ce1.buyer_contact() << std::endl;
    std::cout << "卖家联系方式 (确认前): " << ce1.seller_contact() << std::endl;
    ce1.ConfirmBuyer();
    ce1.ConfirmSeller();
    std::cout << "联系方式交换完成: " << (ce1.IsExchangeComplete() ? "是" : "否") << std::endl;
    std::cout << "买家联系方式 (确认后): " << ce1.buyer_contact() << std::endl;
    std::cout << "卖家联系方式 (确认后): " << ce1.seller_contact() << std::endl;
    std::cout << std::endl;

    // 8. 举报商品
    std::cout << "正在举报商品 2..." << std::endl;
    domain::Report report1(generate_uuid(), user1.id(), "商品", listing2.id(), "内容不当。");
    report1.set_evidence_url("http://example.com/report_evidence.jpg");
    admin_user.set_status(domain::UserStatus::ACTIVE); // 管理员用户处于活跃状态
    report1.set_status(domain::ReportStatus::IN_REVIEW);
    std::cout << "举报 1 状态: " << (report1.status() == domain::ReportStatus::IN_REVIEW ? "审核中" : "新建") << std::endl;
    std::cout << std::endl;

    // 9. 审计日志
    std::cout << "正在记录审计事件..." << std::endl;
    domain::AuditLog log1(generate_uuid(), admin_user.id(), "更新商品状态", "商品", listing2.id(),
                          R"({"old_status": "PUBLISHED", "new_status": "OFFSHELF"})", "192.168.1.1");
    std::cout << std::endl;

    // 演示商品下架
    listing2.OffShelf();
    std::cout << "商品 2 状态: " << (listing2.status() == domain::ListingStatus::OFFSHELF ? "已下架" : "已发布") << std::endl;
    std::cout << std::endl;

    std::cout << "--- 演示完成 ---" << std::endl;

    return 0;
}