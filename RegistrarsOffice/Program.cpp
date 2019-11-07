#include <iostream>
#include "GenQueue.h"
#include "Window.h"
#include "Student.h"
#include "DoubleLinkedList.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>


using namespace std;

int moment = 0;


//functionality methods
float averageStudentWaitTime(DoubleLinkedList<int>* times)
{
    float f = 0.0;
    ListNode<int>* curr = times->head;
    while (curr->next != NULL)
    {
        f += *curr->ele;
    }
    return f/times->size; //float/size
}

float averageWindowIdleTime(Window* office, int windows)
{
    float f = 0.0;
    for(int i = 0; i < windows; ++i)
    {
        f += (float)office[i].idleTime;
    }
    return f/windows; //float/size
}

int numberStudentsOverTen(DoubleLinkedList<int>* times)
{
    int n = 0;
    ListNode<int>* curr = times->head;

    while (curr->next != NULL)
    {
        if (*curr->ele > 10)
        {
            ++n;
        }
    }
    return n;
}

int numberWindowsOverFive(Window* office, int windows)
{
    int n = 0;
    for(int i = 0; i < windows; ++i)
    {
        if (office[i].idleTime > 5)
        {
            ++n;
        }
    }
    return n;
}
int medianStudentWaitTime(DoubleLinkedList<int>* times)
{
    int* nums = new int[times->size];
    ListNode<int>* curr = times->head;


    for (int i = 0; i < times->size; ++i)
    {
        nums[i] = *curr->ele;
        curr = curr->next;
    }

    int s = times->size;
    sort(nums, nums+s);

    if (s%2==0)
    {
        return (nums[s/2] + nums[s/2 - 1])/2;
    }
    else //s%2==1: true
    {
        return nums[s/2];
    }
}
int longestWindowIdleTime(Window* office, int windows)
{
    int max = office[0].maxIdle;
    for (int i = 1; i < windows; ++i)
    {
        if (office[i].maxIdle > max)
        {
            max = office[i].maxIdle;
        }
    }
    return max;
}

int longestStudentWaitTime(DoubleLinkedList<int>* times)
{
    ListNode<int>* curr = times->head;
    int max = *curr->ele;
    while (curr->next != NULL)
    {
        if (*curr->ele > max)
            max = *curr->ele;
    }
    return max;
}

bool consent()
{
  cout << "continue?" << endl;
  string c; //consent, continue, whatever
  cin >> c;
  if (c=="yes")
      return true;
  else if (c=="no")
      return false;
  else return consent();
}

void process()
{

    bool cont = true;
    string filename;
    while (cont)
    {
        cout << "enter filename including.txt" << endl;
        cin >> filename;
        ifstream myfile;
        myfile.open(filename);
        string row;
        if (myfile.is_open())
        {
              //set up integers
              getline (myfile,row);
              cout << "windows " << row << endl;
              int windows = stoi(row);


              DoubleLinkedList<int>* waitTimes = new DoubleLinkedList<int>();

              Window* office = new Window[windows];

              GenQueue<Student>* line = new GenQueue<Student>();


              //order is very important, window:once, time:each, numberstudents:each: minutes:perstudenteach

              while (!myfile.eof())
              {
                  getline (myfile,row);
                  cout << "time " << row << endl;
                  int time = stoi(row);
                  getline (myfile,row);
                  cout << "studentsAtTime " << row << endl;
                  int studentsAtTime = stoi(row); //students arriving at time 't'
                  int t;
                  while(moment != time)
                  {
                      //passage of time
                      ++moment;
                      for (int i = 0; i < windows; ++i)
                      {
                          if (office[i].isOpen())
                          {
                              ++office[i].idleTime;

                          }
                          if (!office[i].isOpen())
                          {
                              --office[i].timeLeft;
                              if (office[i].currentIdle >= office[i].maxIdle)
                                   office[i].maxIdle = office[i].currentIdle;
                              office[i].currentIdle = 0;
                          }
                      }
                  }
                  for(int i = 0; i < studentsAtTime; ++i)
                  {
                      getline(myfile,row);
                      cout << "timeAtWindow " << row << " for student " << i << endl;
                      int timeAtWindow = stoi(row);
                      cout << "create new student" << endl;
                      Student* s = new Student(timeAtWindow, moment);
                      cout << "insert student into queue" << endl;
                      line->insert(s);//help understand this
                      //figure out if windows are open
                      cout << "check each window" << endl;
                      for (int i = 0; i < windows; ++i)
                      {
                          if (office[i].isOpen())
                          {
                              //we remove the student from the queue
                              Student* add = line->remove();
                              //send the waitTime the student
                              add->waitTime = moment - add->instantiated;
                              int x = add->waitTime;
                              waitTimes->insertFront(&x);
                              //fill up window for x time
                              office[i].timeLeft = add->timeAtWindow;
                              add->~Student();
                          }
                      }
                  }
              }
              cout << "________________________\naverage student wait time: " << averageStudentWaitTime(waitTimes) << " minutes\naverage window idle time: " << averageWindowIdleTime(office, windows) << " minutes\nnumber of students waiting >10 minutes: " << numberStudentsOverTen(waitTimes) << " students\nnumber of windows idle for >5 minutes: " << numberWindowsOverFive(office, windows) << " windows\nmedian student wait time: " << medianStudentWaitTime(waitTimes) << " minutes\nlongest student wait time: " << longestStudentWaitTime(waitTimes) << " minutes\nlongest window idle time: " << longestWindowIdleTime(office, windows) << " minutes\n________________________" << endl;
              cont = consent();

            }
            myfile.close();
    }
}



int main()
{
    process();

}
