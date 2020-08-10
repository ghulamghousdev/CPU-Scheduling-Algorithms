//2018-CS-31
//Ghous
//Section-A


#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char output;
    char nameOfInputFile[20];
    
    //Taking name of input file from user
    printf("Enter name of input file: ");
    scanf("%s", nameOfInputFile);
    
    
    // file descriptor
    int fd = open(nameOfInputFile, O_RDWR);
    
    if(fd == -1){
        printf("Error opening input file\n");
        exit(0);
    }
    
    printf("File opened successfully\n"); 
    
    // To keep count of total bytes read
    int bytesRead = 0;

    // Reading from file
	printf("The text read from file is:\n");
    while (read(fd, &output, 1) == 1){
    	//Writing each byte
        write(1, &output, 1);
        bytesRead++;
    }

    printf("\nTotal number of Bytes read are: %d\n", bytesRead);
    return 0;
}
