#ifndef DOMAIN_MESSAGE_H_
#define DOMAIN_MESSAGE_H_

#include <string>

namespace domain {

class Message {
 public:
  // Constructor
  Message(std::string id, std::string conversation_id, std::string sender_id,
          std::string body);

  // Default constructor
  Message();

  // Destructor
  ~Message();

  // Getters
  std::string id() const { return id_; }
  std::string conversation_id() const { return conversation_id_; }
  std::string sender_id() const { return sender_id_; }
  std::string body() const { return body_; }
  std::string created_at() const { return created_at_; }

 private:
  std::string id_;
  std::string conversation_id_;
  std::string sender_id_;
  std::string body_;
  std::string created_at_;
};

}  // namespace domain

#endif  // DOMAIN_MESSAGE_H_
