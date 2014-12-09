#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

const int NUMBEROFPROCESS = 2;
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

        vector<int> arrivalTime;
        for( int i = 0; i< NUMBEROFPROCESS; i++ ) {
                arrivalTime.push_back(newProcessArray[i].processArrivalTime);
        }
        // Now sort the vector
        sort( arrivalTime.begin(), arrivalTime.end() );
        // Now print according to arrival Time vector
        int timer= 1;
        for( int i = 0; i<NUMBEROFPROCESS; i++ ) {
                int j = arrivalTime.front();
                for( int k=0; k<NUMBEROFPROCESS; k++ ) {
                        if( j == newProcessArray[k].processArrivalTime ) {
                                newProcessArray[k].processExecStart = timer;
                                timer += newProcessArray[k].processBurstTime;
                                newProcessArray[k].processExecEnd = timer;
                                newProcessArray[k].processWaitingTime = newProcessArray[k].processExecStart - newProcessArray[k].processArrivalTime;
                                cout<<" Process Name :"<<newProcessArray[k].processName<<"\n";
                                cout<<" Arrival Time :"<<newProcessArray[k].processArrivalTime<<"\n";
                                cout<<" Burst Time:"<<newProcessArray[k].processBurstTime<<"\n";
                                cout<<" Exec start:"<<newProcessArray[k].processExecStart<<"\n";
                                cout<<" Exec end:"<<newProcessArray[k].processExecEnd<<"\n";
                                cout<<" Waiting Time:"<<newProcessArray[k].processWaitingTime<<"\n";
                        }
                }
                arrivalTime.erase( arrivalTime.begin() );
        }

        return 0;
}
