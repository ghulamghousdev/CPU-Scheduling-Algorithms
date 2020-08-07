#include <iostream>
using namespace std;

/* Note
I have used a multiDimensional array to store the
process id, priority of each process and 
burst time, arrival time of each process.
These values are stored in the following manner in the table:
column 1: Process ID
column 2: Burst Time
column 3: burst time remaining
*/
int remainingBurstTimeCol = 2;
int burstTimeCol = 1;
int pIDCol = 0;

int timeSlice = 2;

struct process {
	int noOfProcess; //Total number of process
	int** processList; //List to store process ID's,brust Time of each process
	int* waitingTime; //List to sotre waiting Time of each process
	int* completionTime; //List to sotre completion Time of each process
	int* turnAroundTime; //List to store turnaround time for each process
	
	process(int processCount){ //parameterized constructor to initilize arrays dynamically
		//Setting total no of process
		noOfProcess = processCount;
    	// Dynamically allocate memory 
    	processList = new int* [processCount];
		for (int i = 0; i < processCount; i++)
			processList[i] = new int[3];
		
		for(int i = 0; i < processCount; i++){
			for(int j=0; j < 3; j++){
				processList[i][j] =0;
			}
		}
		
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
	int pID;
	for(int i = 0; i < p.noOfProcess; ++i){
		pID= i + 1;
		cout<<"Enter Brust time for process-"<< pID <<": "; //User prompt to enter burst time
		cin >> burstTime;	//Taking input from user
		p.processList[i][0] = pID;
		p.processList[i][1] = burstTime;
		p.processList[i][2]= burstTime;
	} 

}

//Print all the process
void print(process p){
      for (int i = 0; i < p.noOfProcess; ++i) {
        cout << "\nProcess ID: " << p.processList[i][0]
          << " Burst Time: " << p.processList[i][burstTimeCol]
          << " Waiting Time: " << p.waitingTime[i]
          << " turn around time: "<< p.turnAroundTime[i]
          << " completion time: "<< p.completionTime[i];
      }
}

////Functionto calclate waiting time for each process
void waitingTime(process p){
	int t =0;
	while (1){ 
        bool done = true; 
        for (int i = 0 ; i < p.noOfProcess; i++){ 
            // If burst time of a process is greater than 0 then only need to process further 
            if (p.processList[i][2] > 0) { 
                done = false; //pending process 
  				if (p.processList[i][2] > timeSlice) { 
                    t += timeSlice; 
                    p.processList[i][2] -= timeSlice; 
                } 
  				// If burst time is smaller than or equal to time slice. Last cycle for this process 
                else{ 
                    t = t + p.processList[i][2];
                    p.waitingTime[i] = t - p.processList[i][1]; 
                    p.processList[i][2] = 0; 
                } 
            } 
        } 
        // If all processes are done 
        if (done == true) 
          break; 
    }
}

//Completion time of each process
void completionTime(process p){
    p.completionTime[0] = p.processList[0][2];
    for(int i = 1; i < p.noOfProcess; i++){
    	p.completionTime[i] = p.completionTime[i - 1] + p.processList[i][1];
    }
}
	
//Turn around time for each process
void turnAroundTime(process p) { 
	for (int i = 0; i < p.noOfProcess; i++) {
		p.turnAroundTime[i] = p.waitingTime[i] + p.processList[i][1];}
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
