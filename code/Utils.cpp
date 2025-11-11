#include "Utils.h"
#include <chrono>
#include <iomanip>
#include <sstream>

namespace domain {

// Helper to get current timestamp
std::string GetCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

}  // namespace domain
