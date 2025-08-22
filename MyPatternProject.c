#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void makeExe(char *programName);

int main() {
    int number;
    do {
        printf("***************""Welcome To Pattern""************* \n");
        printf("\t1. pattern17_1    2. pattern17_2\n");
        printf("\t3. pattern17_3    4. pattern17_4\n");
        printf("\t\t5. Exit\n");
        printf("Enter Your Choice for pattern => ");
        scanf("%d", &number);

        switch(number) {
            case 1:
                makeExe("pattern17_1");
                break;
            case 2:
                makeExe("pattern17_2");
                break;
            case 3:
                makeExe("pattern17_3");
                break;
            case 4:
                makeExe("pattern17_4");
                break;
            case 5:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice, try again!\n\n");
        }
    } while(number != 5);

    return 0;
}

void makeExe(char *programName) {
    char command[256];

    // Compile
    snprintf(command, sizeof(command), "gcc -Wall -g %s.c -o %s", programName, programName);
    int result = system(command);

    if(result == 0) {
        printf("Compiled successfully, Exe is %s\n", programName);
        // Run the program and return back to menu
        snprintf(command, sizeof(command), "./%s", programName);
        system(command);

	//remove executable file
	snprintf(command,sizeof(command),"rm %s",programName);
	system(command);
    } else {
        printf("Compilation Failed\n");
    }
}

