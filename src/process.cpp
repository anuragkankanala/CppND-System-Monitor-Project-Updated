#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid)
{
	if(pid > 0)
	{
		pid_ = pid;
	}
}
// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const
{
	//https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
	int pid = Pid();
	float cpu_usage{0};
	if(pid > 0)
	{
		long process_active_jiffies{LinuxParser::ActiveJiffies(pid)};
		long process_active_seconds = process_active_jiffies/sysconf(_SC_CLK_TCK);

		long system_uptime_seconds{LinuxParser::UpTime()};

		long process_uptime_jiffies{LinuxParser::UpTime(pid)};
		long process_uptime_seconds = process_uptime_jiffies/sysconf(_SC_CLK_TCK);

		long time_elapsed_process_start = system_uptime_seconds - process_uptime_seconds;

		if(time_elapsed_process_start != 0)
		{
			cpu_usage = ((process_active_seconds)/(time_elapsed_process_start));
		}

	}

	return cpu_usage;
}

// TODO: Return the command that generated this process
string Process::Command() 
{
	string command{""};
	int pid = Pid();
	if(pid > 0)
	{
		command = LinuxParser::Command(pid);
	}

	return command;
}

// TODO: Return this process's memory utilization
string Process::Ram() 
{
	string ram{""};
	int pid = Pid();
	if(pid > 0)
	{
		ram = LinuxParser::Ram(pid);
	}

	return ram;
}

// TODO: Return the user (name) that generated this process
string Process::User()
{
	string user{""};
	int pid = Pid();
	if(pid > 0)
	{
		user = LinuxParser::User(pid);
	}

	return user;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
	int pid = Pid();
	long int uptime{0};
	if(pid > 0)
	{
		uptime = LinuxParser::UpTime(pid);
	}

	return uptime;
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) 
{
	return (CpuUtilization() < a.CpuUtilization());
}