#include "User.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
User::User(std::string id, std::string phone, std::string nickname,
           std::string campus, std::string department, RoleType role)
    : id_(id),
      phone_(phone),
      nickname_(nickname),
      campus_(campus),
      department_(department),
      role_(role),
      status_(UserStatus::PENDING_VERIFICATION),
      created_at_(GetCurrentTimestamp()) {
  std::cout << "用户 " << nickname_ << " 已创建。" << std::endl;
}

// Default constructor
User::User()
    : id_(""),
      phone_(""),
      nickname_(""),
      campus_(""),
      department_(""),
      role_(RoleType::USER),
      status_(UserStatus::PENDING_VERIFICATION),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "默认用户已创建。" << std::endl;
}


// Destructor
User::~User() {
  std::cout << "用户 " << nickname_ << " 已销毁。" << std::endl;
}

// Member function implementations
bool User::VerifySmsCode(const std::string& code) {
  std::cout << "正在验证用户 " << nickname_ << " 的短信验证码: " << code << std::endl;
  // In a real application, this would involve a check against a sent code.
  // For this simulation, we'll assume any 6-digit code is valid.
  if (code.length() == 6) {
    status_ = UserStatus::ACTIVE;
    std::cout << "短信验证码已验证。用户状态设置为 ACTIVE。" << std::endl;
    return true;
  }
  std::cout << "无效的短信验证码。" << std::endl;
  return false;
}

void User::SetPassword(const std::string& pw) {
  std::cout << "正在为用户 " << nickname_ << " 设置密码。" << std::endl;
  // In a real application, we would hash the password.
  // Here, we'll store a "hashed" version.
  password_hash_ = "hashed_" + pw;
  std::cout << "密码已设置。" << std::endl;
}

}  // namespace domain
