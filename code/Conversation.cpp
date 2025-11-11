#include "Conversation.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
Conversation::Conversation(std::string id, std::string buyer_id,
                           std::string seller_id, std::string listing_id)
    : id_(id),
      buyer_id_(buyer_id),
      seller_id_(seller_id),
      listing_id_(listing_id),
      status_(ConversationStatus::NEW),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "会话 " << id_ << " 已为买家 " << buyer_id_
              << " 和卖家 " << seller_id_ << " (商品 " << listing_id_ << ") 创建。"
              << std::endl;
}

// Default constructor
Conversation::Conversation()
    : id_(""),
      buyer_id_(""),
      seller_id_(""),
      listing_id_(""),
      status_(ConversationStatus::NEW),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "默认会话已创建。" << std::endl;
}

// Destructor
Conversation::~Conversation() {
    std::cout << "会话 " << id_ << " 已销毁。" << std::endl;
}

}  // namespace domain
