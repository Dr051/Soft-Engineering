#include "Category.h"
#include <iostream>

namespace domain {

// Parameterized constructor
Category::Category(std::string id, std::string name, std::string parent_id)
    : id_(id), name_(name), parent_id_(parent_id) {
    std::cout << "类别 '" << name_ << "' 已创建。" << std::endl;
}

// Default constructor
Category::Category() : id_(""), name_(""), parent_id_("") {
    std::cout << "默认类别已创建。" << std::endl;
}

// Destructor
Category::~Category() {
    std::cout << "类别 '" << name_ << "' 已销毁。" << std::endl;
}

}  // namespace domain
