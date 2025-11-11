#ifndef DOMAIN_CATEGORY_H_
#define DOMAIN_CATEGORY_H_

#include <string>

namespace domain {

class Category {
 public:
  // Constructor
  Category(std::string id, std::string name, std::string parent_id = "");

  // Default constructor
  Category();

  // Destructor
  ~Category();

  // Getters
  std::string id() const { return id_; }
  std::string name() const { return name_; }
  std::string parent_id() const { return parent_id_; }

  // Setters
  void set_name(const std::string& name) { name_ = name; }
  void set_parent_id(const std::string& parent_id) { parent_id_ = parent_id; }

 private:
  std::string id_;
  std::string name_;
  std::string parent_id_; // Optional, can be empty
};

}  // namespace domain

#endif  // DOMAIN_CATEGORY_H_
