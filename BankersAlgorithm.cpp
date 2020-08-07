//2018-CS-31
//Section A

#include <iostream>
using namespace std;

void BankerAlgorithm();
int main()
{
	BankerAlgorithm();
    return 0;
}

void BankerAlgorithm(){
	    int noOfProcesses, noOfResources, i, j, k;
    noOfProcesses = 5; 
    noOfResources = 3; 
    // To store result
    int safeSequence[noOfProcesses];
	int index = 0;

    // Maximum instances that can be requested by a process
    int maxInstances[5][3] = {{8, 6, 4}, 
                     {4, 3, 3},
                     {10, 1, 2},
                     {3, 3, 3},
                     {5, 4, 4}};

    // Allocated instances of a process
    int allocatedInstances[5][3] = {{1, 2, 1}, 
                       {3, 1, 1},
                       {4, 1, 3},
                       {3, 2, 2},
                       {1, 1, 3}};
    int availableInstances[3] = {4, 4, 3}; // Number of instances of each resource type

    bool finish[noOfProcesses];
    for (k = 0; k < noOfProcesses; k++) 
    {
        finish[k] = 0;
    }

    // Remaining resource need of a process ie subtracts the allocated to find un allocated
    int need[noOfProcesses][noOfResources]; 
    for (i = 0; i < noOfProcesses; i++)
    {
        for (j = 0; j < noOfResources; j++)
            need[i][j] = maxInstances[i][j] - allocatedInstances[i][j];
    }

    int y = 0;
    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < noOfProcesses; i++)
        {
            if (finish[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < noOfResources; j++)
                {
                    if (need[i][j] > availableInstances[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    safeSequence[index++] = i;
                    for (y = 0; y < noOfResources; y++)
                        availableInstances[y] += allocatedInstances[i][y];
                    finish[i] = 1;
                }
            }
        }
    }

    cout << "\n\nSafe Sequence is: \n";
    for (i = 0; i < noOfProcesses - 1; i++)
        cout << " Process #" << safeSequence[i] << " ->";
    cout << " Process #" << safeSequence[noOfProcesses - 1] << endl;

}
