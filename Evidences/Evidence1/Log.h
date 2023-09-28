#ifndef LOG_H
#define LOG_H

#include <string>

class Log {
public:
    Log(std::string year, std::string month, std::string day, std::string time, std::string ip, std::string message);
    bool operator<(const Log& log) const; // Comparación para ordenar por fecha y hora
    bool isInTimeRange(const std::string& start_date, const std::string& start_time, const std::string& end_date, const std::string& end_time) const;
    std::string toCustomFormat() const;

private:
    std::string year;
    std::string month;
    std::string day;
    std::string time;
    std::string ip;
    std::string message;
};

#endif // LOG_H
