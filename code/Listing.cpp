#include "Listing.h"
#include <iostream>
#include <algorithm>
#include "Utils.h"

namespace domain {

// Parameterized constructor
Listing::Listing(std::string id, std::string seller_id, std::string title,
                 std::string description, double price, Condition condition,
                 std::string category_id, std::string campus, DeliveryType delivery_type)
    : id_(id),
      seller_id_(seller_id),
      title_(title),
      description_(description),
      price_(price),
      condition_(condition),
      category_id_(category_id),
      campus_(campus),
      delivery_type_(delivery_type),
      status_(ListingStatus::DRAFT),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "商品 '" << title_ << "' 已创建为草稿。" << std::endl;
}

// Default constructor
Listing::Listing()
    : id_(""),
      seller_id_(""),
      title_(""),
      description_(""),
      price_(0.0),
      condition_(Condition::NEW),
      category_id_(""),
      campus_(""),
      delivery_type_(DeliveryType::PICKUP),
      status_(ListingStatus::DRAFT),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "默认商品已创建为草稿。" << std::endl;
}


// Destructor
Listing::~Listing() {
    std::cout << "商品 '" << title_ << "' 已销毁。" << std::endl;
}

// Member function implementations
void Listing::Publish() {
    std::cout << "发布商品 '" << title_ << "'。" << std::endl;
    if (status_ == ListingStatus::DRAFT || status_ == ListingStatus::OFFSHELF) {
        status_ = ListingStatus::PUBLISHED;
        std::cout << "商品现在是 PUBLISHED 状态。" << std::endl;
    } else {
        std::cout << "商品无法从当前状态发布。" << std::endl;
    }
}

void Listing::OffShelf() {
    std::cout << "将商品 '" << title_ << "' 下架。" << std::endl;
    if (status_ == ListingStatus::PUBLISHED) {
        status_ = ListingStatus::OFFSHELF;
        std::cout << "商品现在是 OFFSHELF 状态。" << std::endl;
    } else {
        std::cout << "商品当前未发布。" << std::endl;
    }
}

void Listing::Delete() {
    std::cout << "删除商品 '" << title_ << "'。" << std::endl;
    status_ = ListingStatus::DELETED;
    std::cout << "商品已被标记为 DELETED。" << std::endl;
}

void Listing::AddImage(const std::string& image_url) {
    std::cout << "添加图片: " << image_url << std::endl;
    if (images_.size() < 9) {
        images_.push_back(image_url);
        std::cout << "图片已添加。总图片数: " << images_.size() << std::endl;
    } else {
        std::cout << "无法添加更多图片。已达到最大数量 9 张。" << std::endl;
    }
}

void Listing::RemoveImage(const std::string& image_url) {
    std::cout << "尝试移除图片: " << image_url << std::endl;
    auto it = std::find(images_.begin(), images_.end(), image_url);
    if (it != images_.end()) {
        images_.erase(it);
        std::cout << "图片已移除。总图片数: " << images_.size() << std::endl;
    } else {
        std::cout << "未找到图片。" << std::endl;
    }
}

}  // namespace domain
