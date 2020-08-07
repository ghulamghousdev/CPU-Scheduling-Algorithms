#include <iostream>
using namespace std;

struct process {
	int noOfProcess; //Total number of process
	int* processList; //List to store process ID's
	int* burstTime; //List to sotre brust Time of each process
	int* waitingTime; //List to sotre waiting Time of each process
	int* completionTime; //List to sotre completion Time of each process
	int* turnAroundTime; //List to store turnaround time for each process
	
	process(int processCount){ //parameterized constructor to initilize arrays dynamically
		//Setting total no of process
		noOfProcess = processCount;
    	// Dynamically allocate memory 
    	processList =  new int [processCount];
    	burstTime = new int [processCount];
    	waitingTime = new int [processCount];
    	turnAroundTime = new int [processCount];
    	completionTime = new int [processCount];
	}
};

void userPrompt(process p); //Function prototype to ask user for input
void print(process p); //Function prototype to print all the outputs
void waitingTime(process p); //Function prototype to calclate waiting time for each process
void completionTime(process p); //Function prototype to calclate completion time for each process
void turnAroundTime(process p);//Function prototype to calclate turn around time for each process
void avgWaitingAndTurnAroundTime(process p); //Function prototype to calclate avg waiting time and avg turn around time

int main(){
	
	//User prompt for number of process
	cout<<"ENter the total number of process: ";
	int noOfProcess;
  	cin >> noOfProcess;
  	
	process p(noOfProcess); //Declaring instance of struct process
	
	userPrompt(p); //Calling function to take iput from user
	completionTime(p); // calling function to calculate completion time of each process
	waitingTime(p);  //calling function to calclate waiting time for each process
	turnAroundTime(p);// calling function  to calclate turn around time for each process
	print(p); //Printing results
	avgWaitingAndTurnAroundTime(p); //callinf function to calclate avg waiting time and turn around time 
}
void userPrompt(process p){
	int burstTime;
	for(int i = 0; i < p.noOfProcess; ++i){
		p.processList[i] = i + 1;
		cout<<"Enter Brust time for process "<< i + 1<<"		"; //User prompt to enter burst time
		cin>>burstTime;	//Taking input from user
		p.burstTime[i] = burstTime;
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

////Functionto calclate waiting time for each process
void waitingTime(process p){
	p.waitingTime[0] = 0; 
	for (int i = 1; i < p.noOfProcess; i++ ) {
		p.waitingTime[i] = p.burstTime[i-1] + p.waitingTime[i-1];
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
		p.turnAroundTime[i] = p.waitingTime[i] + p.burstTime[i];}
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
