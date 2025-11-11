#include "Favorite.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
Favorite::Favorite(std::string user_id, std::string listing_id)
    : user_id_(user_id),
      listing_id_(listing_id),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "用户 " << user_id_
              << " 对商品 " << listing_id_ << " 的收藏已创建。" << std::endl;
}

// Default constructor
Favorite::Favorite()
    : user_id_(""),
      listing_id_(""),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "默认收藏已创建。" << std::endl;
}

// Destructor
Favorite::~Favorite() {
    std::cout << "用户 " << user_id_
              << " 对商品 " << listing_id_ << " 的收藏已销毁。" << std::endl;
}

}  // namespace domain
