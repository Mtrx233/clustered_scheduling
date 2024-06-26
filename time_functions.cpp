#include "time_functions.h"

// Prints out the time_point as a single decimal number in seconds.
std::ostream& operator<<(std::ostream & stream, const TimePoint & tp){
    auto dur = tp.time_since_epoch();
    auto sec = duration_cast<seconds>(dur);
    auto nsec = duration_cast<nanoseconds>(dur) - sec;
    
	stream << sec.count() << ".";
    stream << std::setw(9) << std::setfill('0') << nsec.count();
	return stream;
}

TimePoint operator+(const TimePoint & tp, const Duration & dur){
  return tp + dur;
}

TimePoint operator+(const Duration & dur, const TimePoint & tp){
  return tp + dur;
}

Duration operator*(const Duration & dur, double scalar)
{
	return duration_cast<Duration>(dur * scalar);
}

Duration operator*(double scalar, const Duration & dur)
{
	return dur * scalar;
}

Duration operator/(const Duration & dur, double scalar)
{
	return duration_cast<Duration>(dur / scalar);
}

double operator/(const Duration & dur1, const Duration & dur2)
{
	return duration<double>(dur1).count() / duration<double>(dur2).count();
}

//Takes the difference between two time_point structs and stores the result in
//the specified duration. Does no bounds checking. The result is always
//a positive time value. 
void ts_diff (const TimePoint& tp1, const TimePoint& tp2, Duration& result){
  if (tp1 > tp2)
  {
    result = tp1 - tp2;
  }
  else{
    result = tp2 - tp1;
  }
}

//This function will take a time_point value and nanosleep until then
void sleep_until_tp (const TimePoint& end_time){
    // To be careful, need to check if end_time is before
    // the current time, but seems like sleep_until does
    // not need to check and will end directly.
    std::this_thread::sleep_until(end_time);
}

void sleep_for_dur (const Duration& sleep_time){
    std::this_thread::sleep_for(sleep_time);
}

void busy_work(const Duration& length)
{
	auto curr_time = Clock::now();
    auto target_time = curr_time + length;
    while(curr_time < target_time)
    {
        curr_time = Clock::now();
    }
}
