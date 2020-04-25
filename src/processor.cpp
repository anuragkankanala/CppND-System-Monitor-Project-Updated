#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() 
{
	long total_system_jiffies{LinuxParser::Jiffies()};
	long active_system_jiffies{LinuxParser::ActiveJiffies()};

	if(total_system_jiffies > 0)
	{
		return ((active_system_jiffies)/total_system_jiffies);
	}

	return 0;
}