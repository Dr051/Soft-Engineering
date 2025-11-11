#include "Message.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
Message::Message(std::string id, std::string conversation_id,
                 std::string sender_id, std::string body)
    : id_(id),
      conversation_id_(conversation_id),
      sender_id_(sender_id),
      body_(body),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "消息 " << id_ << " 已在会话 "
              << conversation_id_ << " 中由发送者 " << sender_id_ << " 创建。" << std::endl;
}

// Default constructor
Message::Message()
    : id_(""),
      conversation_id_(""),
      sender_id_(""),
      body_(""),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "默认消息已创建。" << std::endl;
}

// Destructor
Message::~Message() {
    std::cout << "消息 " << id_ << " 已销毁。" << std::endl;
}

}  // namespace domain
