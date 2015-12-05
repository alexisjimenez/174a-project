#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0

int main()
{
    bool moreInputs = true;

	while (moreInputs)
    {
        printf("Inside of part5.c\n");
    	//make char array that will store the user input 
    	char commArray[256], backUp[256];

    	//ask user what they want to do 
    	printf("Please enter the task you would like to perform: ");
	    fgets(commArray, 256, stdin);
	    int len = strlen(commArray);
	    printf("Length of input without splitting: %i\n", len);
        printf("The User Input: %s\n", commArray);

        strncpy(backUp, commArray, len);
        printf("This is in backUp: %s\n", backUp);

        int exitLC = strcmp(commArray,"exit\n");
        printf("exitLC: %i\n", exitLC);
        int EXITUC = strcmp(commArray,"EXIT\n");
        printf("EXITUC: %i\n", EXITUC);

        //printf("This is in commArray: %s\n", commArray);
        char *splitInput = strtok(commArray," ");
        //printf("This is in commArray: %s\n", commArray);
        int splitLen = 0;
        while(splitInput!=NULL)
        {
            printf("%s\n", splitInput);
            splitLen++;
            splitInput = strtok(NULL, " ");
        }

        //the length of the split one  
        printf("This is the length of splitInput: %i\n", splitLen);

        if (splitLen <= 1)
        {
            printf("Incorrect number of arguments. ");
            moreInputs = true;
        }
        else 
        {
            if (exitLC == 0 || EXITUC == 0)
            {
                break;
            }
            else
            {
                FILE *f; 
                f = fopen ("userInput.txt", "w");
                fscanf(f,"%s\n",backUp);
                fputs(backUp,f);
                fclose(f);
                printf("File write was successful\n"); 
                printf("Done with part5.c\n");  
                system("python part5.py");
            }
        }
    }
}
