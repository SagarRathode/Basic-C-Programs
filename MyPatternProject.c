#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void makeExe(char *programName);

int main() {
    int number;
    do 
    {
	printf("\n");
        printf("***************""Welcome To Pattern""************* \n");
        printf("\t1. pattern17_1    2. pattern17_2\n");
        printf("\t3. pattern17_3    4. pattern17_4\n");
	printf("\t5. pattern16_1    6. pattern16_2\n");
	printf("\t6. pattern16_3    7. pattern16_3_1\n");
	printf("\t8. pattern16_4    9. pattern16_5\n");
	printf("\t10.pattern16_6    11.pattern16_7\n");

        printf("\t\t 100. Exit\n");
	printf("************************************************** \n");
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
		makeExe("pattern16_1");
		break;
	    case 6:
		makeExe("pattern16_2");
		break;
	    case 7:
		makeExe("pattern16_3");
		break;
	    case 8:
		makeExe("pattern16_3_1");
		break;
	    case 9:
		makeExe("pattern16_4");
		break;
	    case 10:
		makeExe("pattern16_5");
		break;
	    case 11:
		makeExe("pattern16_6");
		break;

            case 100:
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

