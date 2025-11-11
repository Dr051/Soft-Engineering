#ifndef DOMAIN_FAVORITE_H_
#define DOMAIN_FAVORITE_H_

#include <string>

namespace domain {

class Favorite {
 public:
  // Constructor
  Favorite(std::string user_id, std::string listing_id);

  // Default constructor
  Favorite();

  // Destructor
  ~Favorite();

  // Getters
  std::string user_id() const { return user_id_; }
  std::string listing_id() const { return listing_id_; }
  std::string created_at() const { return created_at_; }

 private:
  std::string user_id_;
  std::string listing_id_;
  std::string created_at_;
};

}  // namespace domain

#endif  // DOMAIN_FAVORITE_H_
