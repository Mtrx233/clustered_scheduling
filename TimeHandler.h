/*
A general time handler interface, you can use either timespec
from ctime, or time_point and duration from chrono. The
implementation can be found in TimeHandlerTimespec.cpp or
TimeHandlerChrono.cpp.
*/

#ifndef TIMEHANDLER_H
#define TIMEHANDLER_H

#include <iostream>
#include <ctime>

constexpr long int nanosec_in_sec = 1000000000;
constexpr long int millisec_in_sec = 1000;
constexpr long int nanosec_in_millisec = 1000000;

template<typename TimeType>
class TimeHandler {
public:
    static inline void get_time(TimeType* time);
    static void ts_diff (TimeType& ts1, TimeType& ts2, TimeType& result);
    static void sleep_until_ts (TimeType& end_time);
    static void sleep_for_ts (TimeType& sleep_time);
    static void busy_work(TimeType length);
    static TimeType create_time(long sec, long nsec);
    
    // template <typename T>
    // friend std::ostream& operator<<(std::ostream& stream, const T& ts);
    // friend TimeType operator+(const TimeType& ts1, const TimeType& ts2);
    // friend TimeType operator*(const TimeType& ts, double scalar);
    // friend TimeType operator*(double scalar, const TimeType& ts);
    // friend TimeType operator/(const TimeType& ts, double scalar);
    // friend double operator/(const TimeType& ts1, const TimeType& ts2);
    
    // friend bool operator>(const TimeType& lhs, const TimeType& rhs);
    // friend bool operator<(const TimeType& lhs, const TimeType& rhs);
    // friend bool operator==(const TimeType& lhs, const TimeType& rhs);
    // friend bool operator<=(const TimeType& lhs, const TimeType& rhs);
    // friend bool operator>=(const TimeType& lhs, const TimeType& rhs);
    // friend bool operator!=(const TimeType& lhs, const TimeType& rhs);

    static TimeType add(const TimeType& ts1, const TimeType& ts2);
    static TimeType multiply(const TimeType& ts, double scalar);
    static TimeType divided_by(const TimeType& ts, double scalar);
    static bool larger_than(const TimeType& lhs, const TimeType& rhs);
    static bool less_than(const TimeType& lhs, const TimeType& rhs);
    static bool equal(const TimeType& lhs, const TimeType& rhs);
    static bool not_equal(const TimeType& lhs, const TimeType& rhs);
};

std::ostream& operator<<(std::ostream & stream, const timespec & ts);
timespec operator+(const timespec & ts1, const timespec & ts2);
bool operator<(const timespec& lhs, const timespec& rhs);

#endif // TIMEHANDLER_H
