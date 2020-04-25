#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) 
{
	long seconds_remainder = seconds%60;
	long minutes = seconds / 60;
	long minutes_remainder = minutes%60;
	long hours = minutes/60;

	string elapsed_time{""};
	if(hours < 10)
	{
		elapsed_time += "0";
	}
	elapsed_time += std::to_string(hours);
	elapsed_time += ":";
	if(minutes_remainder < 10)
	{
		elapsed_time += "0";
	}
	elapsed_time += std::to_string(minutes_remainder);
	elapsed_time += ":";
	if(seconds_remainder < 10)
	{
		elapsed_time += "0";
	}
	elapsed_time += std::to_string(seconds_remainder);

	return elapsed_time;
}