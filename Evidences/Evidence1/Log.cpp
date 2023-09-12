#include "Log.h"
#include <sstream>
#include <map>

Log::Log(std::string year, std::string month, std::string day, std::string time, std::string ip, std::string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
}

bool Log::operator<(const Log& log) const {
    // Crear un mapeo de los meses a números para ordenar alfabéticamente
    std::map<std::string, int> monthToNumber = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };

    // Comparación para ordenar por fecha y hora
    if (year != log.year) return year < log.year;
    if (monthToNumber[month] != monthToNumber[log.month]) return monthToNumber[month] < monthToNumber[log.month];
    if (day != log.day) return day < log.day;
    return time < log.time;
}

bool Log::isInTimeRange(const std::string& start_date, const std::string& start_time, const std::string& end_date, const std::string& end_time) const {
    // Verificar si el registro está en el rango de fechas y horas
    if (year < start_date || (year == start_date && (month < start_date || (month == start_date && (day < start_date || (day == start_date && time < start_time)))))) {
        return false;
    }
    if (year > end_date || (year == end_date && (month > end_date || (month == end_date && (day > end_date || (day == end_date && time > end_time)))))) {
        return false;
    }
    return true;
}

std::string Log::toCustomFormat() const {
    std::stringstream ss;
    ss << month << " " << day << " " << year << " " << time << " " << ip << " " << message;
    return ss.str();
}
