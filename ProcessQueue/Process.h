#include<iostream>
using namespace std;

class Process
{
	private :
		int PID;
		int execTime; // for how long it wait in queue
		int cpuTime; // for how long cpu will be allocated
		int waitTime; 
		int remainingExecTime;
		int priority;
	public:
		Process(int PID,int execTime,int priority=0,int cpuTime=2)
		{
			this->PID=PID;
			this->execTime=execTime;
			this->waitTime=0;
			this->cpuTime=cpuTime;
			this->remainingExecTime=execTime;
			this->priority=priority;
		}
		// Setters
		void setPID(int pid);
		void setExecTime(int time);
		void setWaitTime(int time);
		void setCpuTime(int time);
		void setRemainingExecTime(int time);
		void setPriority(int priority);
        int getPriority();

		// Getters
		int getPID();
		 int getPriority();
		int getExecTime();
		int getWaitTime();
		int getCpuTime();
		int getRemainingExecTime();
};
// Setters
void Process::setPID(int pid) 
{
    this->PID = pid;
}

void Process::setExecTime(int time) 
{
    this->execTime = time;
}

void Process::setWaitTime(int time) 
{
    this->waitTime = time;
}
void Process::setCpuTime(int time) 
{
    this->cpuTime = time;
}

void Process::setRemainingExecTime(int time) 
{
    this->remainingExecTime = time;
}
// Getters
int Process:: getPID() 
{
    return PID;
}
int Process:: getExecTime() 
{
    return execTime;
}
int Process::getWaitTime() 
{
    return waitTime;
}

int Process::getCpuTime() 
{
    return cpuTime;
}

int Process::getRemainingExecTime() 
{
    return remainingExecTime;
}
void Process::setPriority(int priority) {
    this->priority = priority;
}

int Process::getPriority() {
    return priority;
}
