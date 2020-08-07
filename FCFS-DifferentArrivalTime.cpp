#include <iostream>
using namespace std;

struct process {
	int noOfProcess;
	int* processList;
	int* burstTime;
	int* arrivalTime;
	int* waitingTime;
	int* completionTime;
	int* turnAroundTime;
	
	process(int processCount){
		//Setting total no of process
		noOfProcess = processCount;
    	// Dynamically allocate memory 
    	processList =  new int [processCount];
    	burstTime = new int [processCount];
    	arrivalTime = new int [processCount];
    	waitingTime = new int [processCount];
    	turnAroundTime = new int [processCount];
    	completionTime = new int [processCount];
	}
};

void userPrompt(process p);
void print(process p);
void waitingTime(process p);
void completionTime(process p);
void turnAroundTime(process p);
void avgWaitingAndTurnAroundTime(process p);

int main(){
	
	//User prompt for number of process
	cout<<"ENter the total number of process	";
	int noOfProcess;
  	cin >> noOfProcess;
	process p(noOfProcess);
	userPrompt(p);
	completionTime(p);
	turnAroundTime(p);
	waitingTime(p);
	print(p);
	avgWaitingAndTurnAroundTime(p);
}

void userPrompt(process p){
	
	for(int i = 0; i < p.noOfProcess; ++i){
		p.processList[i] = i + 1;
		cout<<"Enter Brust time for process "<< i + 1<<"		"; //User prompt to enter burst time
		int burstTime;
		cin>>burstTime;	//Taking input from user
		p.burstTime[i] = burstTime;
		cout <<"Enter Arrival time for process "<<i + 1<<"	";
		int arrivalTime;
        cin >> arrivalTime;
		p.arrivalTime[i] = arrivalTime;
	} 
}

//Print all the process
void print(process p){
      for (int i = 0; i < p.noOfProcess; ++i) {
        cout << "\nProcess ID: " << p.processList[i]
          << " Burst Time: " << p.burstTime[i]
          << " Waiting Time: " << p.waitingTime[i]
          << " turn around time: "<< p.turnAroundTime[i]
          << " completion time: "<< p.completionTime[i];
      }
}

void waitingTime(process p){
	p.waitingTime[0] = 0; 
	for (int i = 1; i < p.noOfProcess; i++ ) {
		p.waitingTime[i] = p.turnAroundTime[i]-p.burstTime[i];
	}
}

//COmpletion time of each process
void completionTime(process p){
    p.completionTime[0] = p.burstTime[0];
    for(int i = 1; i < p.noOfProcess; i++){
    	p.completionTime[i] = p.completionTime[i - 1] + p.burstTime[i];
    }
}
	
//Turn around time for each process
void turnAroundTime(struct process p) { 
	for (int i = 0; i < p.noOfProcess; i++) {
		p.turnAroundTime[i] = p.completionTime[i]-p.arrivalTime[i];}
}

//Avg waiting and Turn around Time
void avgWaitingAndTurnAroundTime(process p){
	int totalWaitingTime=0;
	int totalTurnAroundTime=0;
	
	for(int i = 0; i<p.noOfProcess; i++){
		totalWaitingTime += p.waitingTime[i];
		totalTurnAroundTime += p.turnAroundTime[i];
	}
	
	int avgWaiting = (float)totalWaitingTime/(float)p.noOfProcess; 
	int avgTurnAround = (float)totalTurnAroundTime / (float)p.noOfProcess; 
	cout << "\n\nAverage waiting time = "<< avgWaiting <<endl;
	cout<<"Average turn around time =  "<< avgTurnAround <<endl;
}
