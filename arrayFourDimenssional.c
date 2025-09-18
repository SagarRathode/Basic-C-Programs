

//this program demonstrates Four D memory allocation and free

#include <stdio.h>
#include <stdlib.h>

int main() {

    int first,second,third,fourth;
    printf("Enter dimensions(first, second, third, fourth):\n");
    scanf("%d %d %d %d", &first, &second, &third, &fourth);
    printf("your dimenssion is arr[%d][%d][%d][%d]\n",first,second,third,fourth);

    // allocate the 4D array arr[i][j][k][l]

    int ****arr = (int ****)malloc(first* sizeof(int ***));
    for (int i = 0; i < first; i++) {

        arr[i] = (int ***)malloc(second * sizeof(int **));

        for (int j = 0; j < second; j++) {

            arr[i][j] = (int **)malloc(third * sizeof(int *));
            
		for (int k = 0; k < third; k++) {
                	
			arr[i][j][k] = (int *)malloc(fourth * sizeof(int));
            }
        }
    }

    // Accept elements from the user
    printf("Enter the elements of the 4D array:\n");
    for (int i = 0; i < first; i++) {

        for (int j = 0; j < second; j++) {

            for (int k = 0; k < third; k++) {

                for (int l = 0; l < fourth; l++) {

                    scanf("%d", &arr[i][j][k][l]);
                }
            }
        }
    }

    // Display the elements
    printf("The elements of the 4D array are:\n");
    for (int i = 0; i < first; i++) {

        for (int j = 0; j < second; j++) {

            for (int k = 0; k < third; k++) {

                for (int l = 0; l < fourth; l++) {

                    printf("arr[%d][%d][%d][%d]=%d\n",i,j,k,l, arr[i][j][k][l]);
                }
		printf("\n");
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < first; i++) {

        for (int j = 0; j < second; j++) {

            for (int k = 0; k < third; k++) {

                free(arr[i][j][k]);
            }

            free(arr[i][j]);
        }

        free(arr[i]);
    }

    free(arr);


    return 0;
}
