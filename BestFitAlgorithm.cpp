/*
2018-CS-31
Ghulam Ghous
Section A
*/

#include <iostream>
using namespace std;

//Declaring a structure to store data
struct process{
	
	int* blockSize;		//Array to store size of blocks
	int* processSize;	//Array to store size of process
	int* allocated;		//Array to store information about allocated blocks
	int noOfProcess;	//Total number of process
	int noOfBlocks;		//Total number of blocks
	
	//Parameterized constructor to intilize values
	process(int p, int b){
		blockSize = new int [b];	//Allocating dynamic memort to block size
		processSize = new int [p];	//Allocating dynamic memory to process size
		noOfBlocks = b;
		noOfProcess = p;
		allocated = new int [p];	//Allocating dynamic memory to allocated array
		for(int i = 0; i < p; i++){	//Initilizing allocated array with default values of -1
			allocated[i] = -1;
		}
	}
};

void bestFit(process p); //Prototype of function best fit which allocates memory blocks to different process
void print(process p);	  //Prototype of function which prints the allocated blocks and process size

int main(){
	
	//Taking no of process and blocks from user
	int processCount, blocksCount, pSize, bSize;
	cout << "This program allocates memory to process using best fit algorithm\n";
	cout << "Enter the total no of process: ";
	cin >> processCount;
	cout << "Enter the total no of blocks: ";
	cin >> blocksCount;
	
	//Declaring a instance of process data structure and calling its parameterized constructor
	process p(processCount, blocksCount);
	
	//Taking block sizes from user
	cout << "\n\nInput the Block Size\n";
	for(int i = 0; i < blocksCount; i++){
		cout << "Size of Block " << i + 1 <<" : ";
		cin >> bSize;
		p.blockSize[i] = bSize;
	}
	
	//Taking process sizes from user
	cout << "\n\nInput the Process Size\n";
	for(int i = 0; i < processCount; i++){
		cout << "Size of Process " << i + 1 <<" : ";
		cin >> pSize;
		p.processSize[i] = pSize;
	}
	
	
	bestFit(p); 
	print(p);
	
	return 0;
}

//This function allocates memory to process using best fit approach
void bestFit(process p){
	int temp;
	for(int i = 0; i < p.noOfProcess; i++){
		temp = -1;
		for(int j = 0; j < p.noOfBlocks; j++){
			if(p.processSize[i] <= p.blockSize[j]){ //If size of process is less than or equal to block size allocate then allocate that block to the process
				
				if(temp == -1){
					temp = j;
				}
				else if(p.blockSize[j] < p.blockSize[temp]){
					temp = j;
				}
			}
		}
		//If the suitable memory block for the process is found
		if(temp != -1){
			p.allocated[i] = temp + 1;
			p.blockSize[temp] = p.blockSize[temp] - p.processSize[i]; //Resetting the size of the block
		}
	}
}


//Function to print process id, process Size and allocated block
void print(process p){
	cout << "\nProcess No.\tProcess Size\tAllocated Block No.\n";
	for(int i = 0; i < p.noOfProcess; i++){
		cout << " " << i + 1 << "\t\t" << p.processSize[i] << "\t\t";
		if (p.allocated[i] == -1)
			cout << "No Block Allocated" << "\n";
		else
			cout << p.allocated[i] <<"\n";
	}
}
