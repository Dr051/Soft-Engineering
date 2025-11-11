#include "ContactExchange.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
ContactExchange::ContactExchange(std::string conversation_id)
    : conversation_id_(conversation_id),
      buyer_confirmed_(false),
      seller_confirmed_(false) {
    std::cout << "联系方式交换已为会话 " << conversation_id_
              << " 启动。" << std::endl;
}

// Default constructor
ContactExchange::ContactExchange()
    : conversation_id_(""),
      buyer_confirmed_(false),
      seller_confirmed_(false) {
    std::cout << "默认联系方式交换已创建。" << std::endl;
}

// Destructor
ContactExchange::~ContactExchange() {
    std::cout << "会话 " << conversation_id_
              << " 的联系方式交换已销毁。" << std::endl;
}

void ContactExchange::ProvideBuyerContact(const std::string& contact) {
    buyer_contact_ = contact;
    std::cout << "买家联系方式已提供。" << std::endl;
}

void ContactExchange::ProvideSellerContact(const std::string& contact) {
    seller_contact_ = contact;
    std::cout << "卖家联系方式已提供。" << std::endl;
}

void ContactExchange::ConfirmBuyer() {
    if (!buyer_contact_.empty()) {
        buyer_confirmed_ = true;
        std::cout << "买家已确认联系方式交换。" << std::endl;
        if (IsExchangeComplete()) {
            exchanged_at_ = GetCurrentTimestamp();
            std::cout << "联系方式交换已于 " << exchanged_at_ << " 完成。" << std::endl;
        }
    } else {
        std::cout << "无法确认：买家联系方式未提供。" << std::endl;
    }
}

void ContactExchange::ConfirmSeller() {
    if (!seller_contact_.empty()) {
        seller_confirmed_ = true;
        std::cout << "卖家已确认联系方式交换。" << std::endl;
        if (IsExchangeComplete()) {
            exchanged_at_ = GetCurrentTimestamp();
            std::cout << "联系方式交换已于 " << exchanged_at_ << " 完成。" << std::endl;
        }
        } else {
        std::cout << "无法确认：卖家联系方式未提供。" << std::endl;
    }
}

bool ContactExchange::IsExchangeComplete() const {
    return buyer_confirmed_ && seller_confirmed_;
}

std::string ContactExchange::buyer_contact() const {
    if (IsExchangeComplete()) {
        return buyer_contact_;
    }
    return "未公开";
}

std::string ContactExchange::seller_contact() const {
    if (IsExchangeComplete()) {
        return seller_contact_;
    }
    return "未公开";
}

}  // namespace domain
