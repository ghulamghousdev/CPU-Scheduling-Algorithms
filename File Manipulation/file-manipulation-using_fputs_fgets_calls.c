//2018-CS-31
//Ghous
//Section-A

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[80];
    
    char nameOfInputFile[20];
    char nameOfOutputFile[20];

    //Open text files and check that they open//
    FILE *fp1, *fp2;
    
    //Taking name of input file from user
    printf("Enter name of input file: ");
    scanf("%s", nameOfInputFile);
    
    //Taking name of output file from user
    printf("Enter name of input file: ");
    scanf("%s", nameOfOutputFile);
    
    //Opening input file
    fp1 = fopen(nameOfInputFile,"r");

    if(fp1 == NULL){
        printf("Error opening input file\n");
        exit(0);
    }
    
    //Opening outputfile
    fp2 = fopen(nameOfOutputFile,"w");
    
    if(fp2 == NULL) {
        printf("Error reading output file\n");
        exit(0);	
	}
	
    printf("Files opened correctly\n");

    //Read text from input file
    while(fgets(str, sizeof(str), fp1) !=NULL){
        // Printing to output file
        fputs(str, fp2);
    }

    printf("File created and text copied to it\n");

    //Closing both files and end program//
    fclose(fp1);
    fclose(fp2);
    return 0;
}
