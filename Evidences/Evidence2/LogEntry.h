#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

class LogEntry {
public:
    LogEntry(const std::string& date, const std::string& time, const std::string& ip, const std::string& message);

    friend bool operator<(const LogEntry& lhs, const LogEntry& rhs);

    std::string getDate() const;
    std::string getTime() const;
    std::string getIP() const;
    std::string getMessage() const;

private:
    std::string date_;
    std::string time_;
    std::string ip_;
    std::string message_;
};

#endif // LOGENTRY_H
