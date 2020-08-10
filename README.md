# CPU Scheduling Algorithms

<img src="https://img.shields.io/badge/Operating Systems-CPU Scheduling Algorithm-<green>"> <img src="https://img.shields.io/static/v1?label=Language&message=CPP&color=blue">
<br>


<br>

## Implemented Algorithm <br>

Implemented following CPU scheduling algorithms in C++ with same and different arrival time <br>
<br>
- First Come First Served <br>
- Shortest Job First <br>
- Round Robin <br>
- Priority Scheduling <br>
- Best Fit <br>
- First Fit <br>
- Bankers Algorithm <br>

<br>

## Features
Some of the features included are, <br>
- Concept of Arrival Time <br>
- Representation of individual process data like, Turn Around Time, Waiting Time etc. <br>
- Calculation of Average Turn Around Time and Waiting Time <br>
<br>

## First Come First Served <br>

As the name suggests, the process which arrives first, will be served first.This scheduling algorithm is <b> non- preemptive </b>. 
Here, processes are sorted by their respective arrival time and then are executed. The process with lowest arrival time will 
get priority in execution.<br>
<br>

## Shortest Job First <br>

Processes have their respective burst time, which suggests how much CPU time a process requires in order to get executed. 
This scheduling algorithm in <b> Non- Preemptive </b>. Here, the processes are first sorted with their respective arrival 
time. As soon the process arrives, it gets enqueued in a queue of arrived processes. The processes are executed in ascending 
order of their burst time in from the queue of arrived process. <br>
<br>

## Round Robin <br>

Here, the process starvation is least as every process is executed in round robin fashion for a certain specified time quantum.
Once a process is executed for the given time quantum, it leaves the CPU and gives turn to next process.
<br>

## Priority Schedulig <br>
Priority scheduling is a non-preemptive algorithm and one of the most common scheduling algorithms in batch systems. Each process is 
assigned a priority. Process with highest priority is to be executed first and so on. Processes with same priority are executed on 
first come first served basis.
<br>

## Best Fit <br>

The best fit deals with allocating the smallest free partition which meets the requirement of the requesting process. 
This algorithm first searches the entire list of free partitions and considers the smallest hole that is adequate. It then 
tries to find a hole which is close to actual process size needed.
<br>
## First Fit <br>

It is an memory allocation algorithm to different processes. First Fit Algorithm is the simplest technique of allocating the
memory block to the processes amongst all. In this algorithm, the pointer keeps track of all the free blocks in the memory 
and accepts the request of allocating a memory block to the coming process
<br>

## Bankers Algorithm

The banker’s algorithm is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating 
the allocation for predetermined maximum possible amounts of all resources, then makes an “s-state” check to test for 
possible activities, before deciding whether allocation should be allowed to continue.
<br>
