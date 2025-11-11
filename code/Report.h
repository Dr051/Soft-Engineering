#ifndef DOMAIN_REPORT_H_
#define DOMAIN_REPORT_H_

#include <string>
#include "Types.h"

namespace domain {

class Report {
 public:
  // Constructor
  Report(std::string id, std::string reporter_id, std::string target_type,
         std::string target_id, std::string reason);

  // Default constructor
  Report();

  // Destructor
  ~Report();

  // Getters
  std::string id() const { return id_; }
  std::string reporter_id() const { return reporter_id_; }
  std::string target_type() const { return target_type_; }
  std::string target_id() const { return target_id_; }
  std::string reason() const { return reason_; }
  std::string evidence_url() const { return evidence_url_; }
  ReportStatus status() const { return status_; }
  std::string created_at() const { return created_at_; }

  // Setters
  void set_evidence_url(const std::string& url) { evidence_url_ = url; }
  void set_status(ReportStatus status) { status_ = status; }

 private:
  std::string id_;
  std::string reporter_id_;
  std::string target_type_; // e.g., "User", "Listing"
  std::string target_id_;
  std::string reason_;
  std::string evidence_url_;
  ReportStatus status_;
  std::string created_at_;
};

}  // namespace domain

#endif  // DOMAIN_REPORT_H_
