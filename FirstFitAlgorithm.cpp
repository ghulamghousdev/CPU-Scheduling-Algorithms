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

void firstFit(process p); //Prototype of function first fit which allocates memory blocks to different process
void print(process p);	  //Prototype of function which prints the allocated blocks and process size

int main(){
	
	//Taking no of process and blocks from user
	int processCount, blocksCount, pSize, bSize;
	cout << "This program allocates memory to process using first fit algorithm\n";
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
	
	
	firstFit(p); 
	print(p);
	
	return 0;
}

//This function allocates memory to process using first fit approach
void firstFit(process p){
	for(int i = 0; i < p.noOfProcess; i++){
		for(int j = 0; j < p.noOfBlocks; j++){
			if(p.processSize[i] <= p.blockSize[j]){ //If size of process is less than or equal to block size allocate then allocate that block to the process
				p.allocated[i] = j + 1;
				p.blockSize[j] = p.blockSize[j] - p.processSize[i];
				break;
			}
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
