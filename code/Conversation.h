#ifndef DOMAIN_CONVERSATION_H_
#define DOMAIN_CONVERSATION_H_

#include <string>
#include <vector>
#include "Types.h"

namespace domain {

class Message; // Forward declaration

class Conversation {
 public:
  // Constructor
  Conversation(std::string id, std::string buyer_id, std::string seller_id,
               std::string listing_id);

  // Default constructor
  Conversation();

  // Destructor
  ~Conversation();

  // Getters
  std::string id() const { return id_; }
  std::string buyer_id() const { return buyer_id_; }
  std::string seller_id() const { return seller_id_; }
  std::string listing_id() const { return listing_id_; }
  ConversationStatus status() const { return status_; }
  std::string created_at() const { return created_at_; }
  
  // Setters
  void set_status(ConversationStatus status) { status_ = status; }

 private:
  std::string id_;
  std::string buyer_id_;
  std::string seller_id_;
  std::string listing_id_;
  ConversationStatus status_;
  std::string created_at_;
};

}  // namespace domain

#endif  // DOMAIN_CONVERSATION_H_
