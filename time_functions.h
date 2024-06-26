/*
Note: This is trying to replace C-Style time processing (timesepc from time.h) to
chrono introduced in C++ 11 which is modern and safer. Unlike timespec which can
stand for both a time point and duration, in std::chrono they are different.

-Yazhou 2024/6/25
*/

#ifndef RT_GOMP_TIME_FUNCTIONS_H
#define RT_GOMP_TIME_FUNCTIONS_H

#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>

using namespace std::chrono;
using Clock = system_clock;                 // More clocks in std::chrono.
using TimePoint = time_point<Clock>;
using Duration = Clock::duration;

const long int nanosec_in_sec = 1000000000;
const long int millisec_in_sec = 1000;
const long int nanosec_in_millisec = 1000000;

inline void get_time( TimePoint* tp ){
    *tp = Clock::now();
}

std::ostream& operator<<(std::ostream & stream, const TimePoint & tp);
TimePoint operator+(const TimePoint & tp, const Duration & dur);
TimePoint operator+(const Duration & dur, const TimePoint & tp);
Duration operator*(const Duration & dur, double scalar);
Duration operator*(double scalar, const Duration & dur);
Duration operator/(const Duration & dur, double scalar);
double operator/(const Duration & dur1, const Duration & dur2);

void tp_diff(const TimePoint& tp1, const TimePoint& tp2, Duration& result);
void sleep_until_tp(const TimePoint& end_time);
void sleep_for_dur(const Duration& sleep_time);
void busy_work(const Duration& length);
/*
The original function in timespec_functions.h didn't use &. Why?
*/

#endif /* RT_GOMP_TIME_FUNCTIONS_H */
