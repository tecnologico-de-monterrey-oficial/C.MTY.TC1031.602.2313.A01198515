#ifndef LOG_ENTRY_H
#define LOG_ENTRY_H

#include <string>

struct LogEntry {
    std::string month;
    int day;
    int year;
    std::string time;
    std::string ip;
    std::string message;
};

#endif // LOG_ENTRY_H





