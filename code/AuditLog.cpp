#include "AuditLog.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
AuditLog::AuditLog(std::string id, std::string actor_id, std::string action,
                   std::string target_type, std::string target_id,
                   std::string metadata, std::string ip)
    : id_(id),
      actor_id_(actor_id),
      action_(action),
      target_type_(target_type),
      target_id_(target_id),
      metadata_(metadata),
      created_at_(GetCurrentTimestamp()),
      ip_(ip) {
    std::cout << "审计日志 " << id_ << ": 操作者 " << actor_id_ << " 对 "
              << target_type_ << " " << target_id_ << " 执行了 " << action_ << " 操作。" << std::endl;
}

// Default constructor
AuditLog::AuditLog()
    : id_(""),
      actor_id_(""),
      action_(""),
      target_type_(""),
      target_id_(""),
      metadata_(""),
      created_at_(GetCurrentTimestamp()),
      ip_("") {
    std::cout << "默认审计日志已创建。" << std::endl;
}

// Destructor
AuditLog::~AuditLog() {
    std::cout << "审计日志 " << id_ << " 已销毁。" << std::endl;
}

}  // namespace domain
