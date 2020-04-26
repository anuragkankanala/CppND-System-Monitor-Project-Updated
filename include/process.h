#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
 Process(int pid);
  int Pid() const;                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a);  // TODO: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
 int pid_{-1};
 float process_active_seconds_prev_{0.0f};
 float time_elapsed_process_start_prev_{0.0f};
};

#endif