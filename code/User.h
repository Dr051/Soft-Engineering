#ifndef DOMAIN_USER_H_
#define DOMAIN_USER_H_

#include <string>
#include <vector>
#include "Types.h"

namespace domain {

class User {
 public:
  // Constructors
  User(std::string id, std::string phone, std::string nickname,
       std::string campus, std::string department, RoleType role);

  // Default constructor
  User();

  // Destructor
  ~User();

  // Member functions as per UML
  bool VerifySmsCode(const std::string& code);
  void SetPassword(const std::string& pw);

  // Getters
  std::string id() const { return id_; }
  std::string phone() const { return phone_; }
  std::string email() const { return email_; }
  std::string password_hash() const { return password_hash_; }
  std::string nickname() const { return nickname_; }
  std::string avatar() const { return avatar_; }
  std::string campus() const { return campus_; }
  std::string department() const { return department_; }
  std::string grade() const { return grade_; }
  RoleType role() const { return role_; }
  UserStatus status() const { return status_; }
  std::string created_at() const { return created_at_; }

  // Setters
  void set_email(const std::string& email) { email_ = email; }
  void set_password_hash(const std::string& hash) { password_hash_ = hash; }
  void set_nickname(const std::string& nickname) { nickname_ = nickname; }
  void set_avatar(const std::string& avatar) { avatar_ = avatar; }
  void set_grade(const std::string& grade) { grade_ = grade; }
  void set_status(UserStatus status) { status_ = status; }


 private:
  std::string id_;
  std::string phone_;
  std::string email_;
  std::string password_hash_;
  std::string nickname_;
  std::string avatar_;
  std::string campus_;
  std::string department_;
  std::string grade_;
  RoleType role_;
  UserStatus status_;
  std::string created_at_;
};

}  // namespace domain

#endif  // DOMAIN_USER_H_
