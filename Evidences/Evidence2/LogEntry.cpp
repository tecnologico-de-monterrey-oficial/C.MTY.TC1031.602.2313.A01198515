#include "LogEntry.h"

LogEntry::LogEntry(const std::string& date, const std::string& time, const std::string& ip, const std::string& message)
    : date_(date), time_(time), ip_(ip), message_(message) {}

bool operator<(const LogEntry& lhs, const LogEntry& rhs) {
    return lhs.date_ < rhs.date_ || (lhs.date_ == rhs.date_ && lhs.time_ < rhs.time_);
}

std::string LogEntry::getDate() const {
    return date_;
}

std::string LogEntry::getTime() const {
    return time_;
}

std::string LogEntry::getIP() const {
    return ip_;
}

std::string LogEntry::getMessage() const {
    return message_;
}
