#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"

#define MAX_TASKS 5

class Scheduler {
  
  int nTasks;
  Task* taskList[MAX_TASKS];  
public:
  void init();  
  virtual bool addTask(Task* task);  
  virtual void schedule();
};

#endif
