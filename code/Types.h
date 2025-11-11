#ifndef DOMAIN_TYPES_H_
#define DOMAIN_TYPES_H_

namespace domain {

// Enum for User roles
enum class RoleType {
    ADMIN,
    USER
};

// Enum for User status
enum class UserStatus {
    ACTIVE,
    BANNED,
    PENDING_VERIFICATION
};

// Enum for Listing condition
enum class Condition {
    NEW,
    LIKE_NEW,
    GOOD,
    FAIR,
    POOR
};

// Enum for delivery types
enum class DeliveryType {
    PICKUP,
    SHIPPING,
    BOTH
};

// Enum for Listing status
enum class ListingStatus {
    DRAFT,
    PUBLISHED,
    OFFSHELF,
    DELETED
};

// Enum for Conversation status
enum class ConversationStatus {
    NEW,
    ACTIVE,
    CLOSED
};

// Enum for Report status
enum class ReportStatus {
    NEW,
    IN_REVIEW,
    APPROVED,
    REJECTED,
    NEED_INFO
};

}  // namespace domain

#endif  // DOMAIN_TYPES_H_
