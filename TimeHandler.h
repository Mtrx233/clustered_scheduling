/*
A general time handler interface, you can use either timespec
from ctime, or time_point and duration from chrono. The
implementation can be found in TimeHandlerTimespec.cpp or
TimeHandlerChrono.cpp.
*/

#ifndef TIMEHANDLER_H
#define TIMEHANDLER_H

#include <iostream>

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

    // friend std::ostream& operator<<(std::ostream& stream, const TimeType& ts);
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

    riend std::ostream& operator<<(std::ostream& stream, const TimeType& ts);
    friend TimeType operator+(const TimeType& ts1, const TimeType& ts2);
    friend TimeType operator*(const TimeType& ts, double scalar);
    friend TimeType operator*(double scalar, const TimeType& ts);
    friend TimeType operator/(const TimeType& ts, double scalar);
    friend double operator/(const TimeType& ts1, const TimeType& ts2);
    
    friend bool operator>(const TimeType& lhs, const TimeType& rhs);
    friend bool operator<(const TimeType& lhs, const TimeType& rhs);
    friend bool operator==(const TimeType& lhs, const TimeType& rhs);
    friend bool operator<=(const TimeType& lhs, const TimeType& rhs);
    friend bool operator>=(const TimeType& lhs, const TimeType& rhs);
    friend bool operator!=(const TimeType& lhs, const TimeType& rhs);
};

// template<typename TimeType> 
// std::ostream& operator<<(std::ostream& stream, const TimeType& ts);

// template<typename TimeType>
// TimeType operator+(const TimeType& ts1, const TimeType& ts2);

// template<typename TimeType> 
// TimeType operator*(const TimeType& ts, double scalar);

// template<typename TimeType> 
// TimeType operator*(double scalar, const TimeType& ts);

// template<typename TimeType> 
// TimeType operator/(const TimeType& ts, double scalar);

// template<typename TimeType> 
// double operator/(const TimeType& ts1, const TimeType& ts2);

// template<typename TimeType>
// bool operator>(const TimeType& lhs, const TimeType& rhs);

// template<typename TimeType>
// bool operator<(const TimeType& lhs, const TimeType& rhs);

// template<typename TimeType>
// bool operator==(const TimeType& lhs, const TimeType& rhs);

// template<typename TimeType>
// bool operator<=(const TimeType& lhs, const TimeType& rhs);

// template<typename TimeType>
// bool operator>=(const TimeType& lhs, const TimeType& rhs);

// template<typename TimeType>
// bool operator!=(const TimeType& lhs, const TimeType& rhs);

#endif // TIMEHANDLER_H
