#ifndef DOMAIN_CONTACTEXCHANGE_H_
#define DOMAIN_CONTACTEXCHANGE_H_

#include <string>

namespace domain {

class ContactExchange {
 public:
  // Constructor
  explicit ContactExchange(std::string conversation_id);

  // Default constructor
  ContactExchange();

  // Destructor
  ~ContactExchange();

  // Member functions
  void ProvideBuyerContact(const std::string& contact);
  void ProvideSellerContact(const std::string& contact);
  void ConfirmBuyer();
  void ConfirmSeller();
  bool IsExchangeComplete() const;

  // Getters
  std::string conversation_id() const { return conversation_id_; }
  std::string buyer_contact() const;
  std::string seller_contact() const;
  bool buyer_confirmed() const { return buyer_confirmed_; }
  bool seller_confirmed() const { return seller_confirmed_; }
  std::string exchanged_at() const { return exchanged_at_; }

 private:
  std::string conversation_id_;
  std::string buyer_contact_;
  std::string seller_contact_;
  bool buyer_confirmed_;
  bool seller_confirmed_;
  std::string exchanged_at_;
};

}  // namespace domain

#endif  // DOMAIN_CONTACTEXCHANGE_H_
