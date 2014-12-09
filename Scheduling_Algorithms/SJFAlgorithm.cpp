#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

const int NUMBEROFPROCESS = 3;
using namespace std;


struct ProcessBlocks{
        string processName;
        int processArrivalTime;
        int processBurstTime;
        int processPriority;
        int processExecStart;
        int processExecEnd;
        int processWaitingTime;
};

int main() {
        fstream file;
        char ch;
        file.open( "process.txt");

        ProcessBlocks newProcessArray[NUMBEROFPROCESS];
        for ( int i=0; i< NUMBEROFPROCESS; i++ ) {
                file>>newProcessArray[i].processName;
                file>>newProcessArray[i].processArrivalTime;
                file>>newProcessArray[i].processBurstTime;
                file>>newProcessArray[i].processPriority;
        }
        file.close();

        vector<int> burstTime,arrivalTime;
        for( int i = 0; i< NUMBEROFPROCESS; i++ ) {
                burstTime.push_back( newProcessArray[i].processBurstTime );
                arrivalTime.push_back( newProcessArray[i].processArrivalTime );
        }
        // Now sort the vector according to Burst Time
        //sort( arrivalTime.begin(), arrivalTime.end() );
        sort( burstTime.begin(), burstTime.end() );
        // Now print according to arrival Time vector
        int timer= 1;
        for( int i = 0; i<NUMBEROFPROCESS; i++ ) {
                int shortestJob = burstTime.front();
                int firstCameJob = arrivalTime.front();
                for( int k=0; k<NUMBEROFPROCESS; k++ ) {
                              if( shortestJob == newProcessArray[k].processBurstTime ) {
                                      newProcessArray[k].processExecStart = timer;
                                      timer += newProcessArray[k].processBurstTime;
                                      newProcessArray[k].processExecEnd = timer;
                                      newProcessArray[k].processWaitingTime = newProcessArray[k].processExecStart - newProcessArray[k].processArrivalTime;
                                      if ( newProcessArray[k].processWaitingTime < 0 ) {
                                          newProcessArray[k].processWaitingTime = -1*newProcessArray[k].processWaitingTime;
                                      }
                                      cout<<" Process Name :"<<newProcessArray[k].processName<<"\n";
                                      cout<<" Arrival Time :"<<newProcessArray[k].processArrivalTime<<"\n";
                                      cout<<" Burst Time:"<<newProcessArray[k].processBurstTime<<"\n";
                                      cout<<" Exec start:"<<newProcessArray[k].processExecStart<<"\n";
                                      cout<<" Exec end:"<<newProcessArray[k].processExecEnd<<"\n";
                                      cout<<" Waiting Time:"<<newProcessArray[k].processWaitingTime<<"\n";
                              }
                }
                burstTime.erase( burstTime.begin() );
        }

        return 0;
}
