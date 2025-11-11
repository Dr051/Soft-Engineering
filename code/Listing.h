#ifndef DOMAIN_LISTING_H_
#define DOMAIN_LISTING_H_

#include <string>
#include <vector>
#include "Types.h"

namespace domain {

class Listing {
 public:
  // Constructors
  Listing(std::string id, std::string seller_id, std::string title,
          std::string description, double price, Condition condition,
          std::string category_id, std::string campus, DeliveryType delivery_type);
  
  // Default constructor
  Listing();

  // Destructor
  ~Listing();

  // Member functions from UML
  void Publish();
  void OffShelf();
  void Delete();

  // Getters
  std::string id() const { return id_; }
  std::string seller_id() const { return seller_id_; }
  std::string title() const { return title_; }
  std::string description() const { return description_; }
  double price() const { return price_; }
  Condition condition() const { return condition_; }
  std::string category_id() const { return category_id_; }
  std::string campus() const { return campus_; }
  DeliveryType delivery_type() const { return delivery_type_; }
  const std::vector<std::string>& images() const { return images_; }
  ListingStatus status() const { return status_; }
  std::string created_at() const { return created_at_; }

  // Setters
  void set_title(const std::string& title) { title_ = title; }
  void set_description(const std::string& description) { description_ = description; }
  void set_price(double price) { price_ = price; }
  void set_condition(Condition condition) { condition_ = condition; }
  void set_delivery_type(DeliveryType type) { delivery_type_ = type; }
  void AddImage(const std::string& image_url);
  void RemoveImage(const std::string& image_url);

 private:
  std::string id_;
  std::string seller_id_;
  std::string title_;
  std::string description_;
  double price_;
  Condition condition_;
  std::string category_id_;
  std::string campus_;
  DeliveryType delivery_type_;
  std::vector<std::string> images_; // Representing URL[0..9]
  ListingStatus status_;
  std::string created_at_;
};

}  // namespace domain

#endif  // DOMAIN_LISTING_H_
