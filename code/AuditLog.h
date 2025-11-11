#ifndef DOMAIN_AUDITLOG_H_
#define DOMAIN_AUDITLOG_H_

#include <string>

namespace domain {

class AuditLog {
 public:
  // Constructor
  AuditLog(std::string id, std::string actor_id, std::string action,
           std::string target_type, std::string target_id,
           std::string metadata, std::string ip);

  // Default constructor
  AuditLog();

  // Destructor
  ~AuditLog();

  // Getters
  std::string id() const { return id_; }
  std::string actor_id() const { return actor_id_; }
  std::string action() const { return action_; }
  std::string target_type() const { return target_type_; }
  std::string target_id() const { return target_id_; }
  std::string metadata() const { return metadata_; }
  std::string created_at() const { return created_at_; }
  std::string ip() const { return ip_; }

 private:
  std::string id_;
  std::string actor_id_;
  std::string action_;
  std::string target_type_;
  std::string target_id_;
  std::string metadata_; // Representing JSON
  std::string created_at_;
  std::string ip_;
};

}  // namespace domain

#endif  // DOMAIN_AUDITLOG_H_
