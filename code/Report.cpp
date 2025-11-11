#include "Report.h"
#include <iostream>
#include "Utils.h"

namespace domain {

// Parameterized constructor
Report::Report(std::string id, std::string reporter_id, std::string target_type,
               std::string target_id, std::string reason)
    : id_(id),
      reporter_id_(reporter_id),
      target_type_(target_type),
      target_id_(target_id),
      reason_(reason),
      status_(ReportStatus::NEW),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "举报 " << id_ << " 已由 " << reporter_id_
              << " 为 " << target_type_ << " " << target_id_ << " 创建。" << std::endl;
}

// Default constructor
Report::Report()
    : id_(""),
      reporter_id_(""),
      target_type_(""),
      target_id_(""),
      reason_(""),
      status_(ReportStatus::NEW),
      created_at_(GetCurrentTimestamp()) {
    std::cout << "默认举报已创建。" << std::endl;
}

// Destructor
Report::~Report() {
    std::cout << "举报 " << id_ << " 已销毁。" << std::endl;
}

}  // namespace domain
