#include <iostream>
using namespace std;

/* Note
I have used a multiDimensional array to store the
process id, priority of each process and 
burst time, arrival time of each process.
These values are stored in the following manner in the table:
column 1: Process ID
column 2: Burst Time
column 3: Burst time remaining
column 4: Arrival Time
*/
int burstTimeCol = 1;
int pIDCol = 0;
int arrivalTimeCol=2;

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



void sortingProcesses(process p);
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
	sortingProcesses(p);
	completionTime(p); //Calculate Completion Time
	turnAroundTime(p);// calling function  to calclate turn around time for each process
	waitingTime(p);  //calling function to calclate waiting time for each process
	print(p); //Printing results
	avgWaitingAndTurnAroundTime(p); //callinf function to calclate avg waiting time and turn around time 
	
	
return 0;
}
void userPrompt(process p){
	int burstTime;
	int arrivalTime;
	int pID;
	for(int i = 0; i < p.noOfProcess; ++i){
		pID= i + 1;
		cout<<"Enter Brust time for process-"<< pID <<":  "; //User prompt to enter burst time
		cin >> burstTime;	//Taking input from user
		cout <<"Enter ArrivalTime of process-"<<pID<<": ";
		cin>>arrivalTime;
		p.processList[i][pIDCol] = pID; //Storing process Id
		p.processList[i][burstTimeCol] = burstTime; //Storing Burst Time
		p.processList[i][arrivalTimeCol] = arrivalTime;
	}  

}

void sortingProcesses(process p){
	//Sorting Processes According to Arrival Time
	int temp=0,burst=0,arri=0;
	for(int i=0;i<p.noOfProcess;i++){
		for(int j=i+1;j<p.noOfProcess;j++){
			if(p.processList[j][2]<p.processList[i][2]){
				arri=p.processList[i][2];
				p.processList[i][2]=p.processList[j][2];
				p.processList[j][2]=arri;
				temp=p.processList[i][0];
				p.processList[i][0]=p.processList[j][0];
				p.processList[j][0]=temp;


				burst=p.processList[i][1];
				p.processList[i][1]=p.processList[j][1];
				p.processList[j][1]=burst;
			}
		}
	}
	//if arrival time is same Now sorting according to burst Time
	for(int i=1;i<p.noOfProcess-1;i++){
		if(p.processList[i][1]>p.processList[i+1][1]){
			arri=p.processList[i][2];
			p.processList[i][2]=p.processList[i+1][2];
			p.processList[i+1][2]=arri;
				temp=p.processList[i][0];
				p.processList[i][0]=p.processList[i+1][0];
				p.processList[i+1][0]=temp;
				burst=p.processList[i][1];
				p.processList[i][1]=p.processList[i+1][1];
				p.processList[i+1][1]=burst;
		}
	}
}

//Function to calculate Waiting Time
void waitingTime(process p){
	for(int i=0;i<p.noOfProcess;i++){
		int time=p.turnAroundTime[i]-p.processList[i][1];
		if(time>=0){
			p.waitingTime[i]=time;
		}
		else
			p.waitingTime[i]=0;
	}
}

//Function To calculate TurnAround Time
void turnAroundTime(process p){
	for(int i=0;i<p.noOfProcess;i++){
		p.turnAroundTime[i]=p.completionTime[i]-p.processList[i][2];
	}
}

//Function to calculate Completion time
void completionTime(process p){
	p.completionTime[0]=p.processList[0][1];
	for(int i=1;i<p.noOfProcess;i++){
		p.completionTime[i]=p.processList[i][1]+p.completionTime[i-1];
	}
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

