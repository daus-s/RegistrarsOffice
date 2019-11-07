#include "Student.h"

int waitTime = 0;
int timeAtWindow;
int instantiated;

Student::Student(int t, int i)
{
    timeAtWindow = t;
    instantiated = i;
}

Student::Student()
{}
  
Student::~Student()
{}

void timeInc()
{
    ++waitTime;
}
