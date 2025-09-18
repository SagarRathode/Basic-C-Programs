#include <stdio.h>
#include <stdlib.h>

int main() {

    int first,second,third,fourth,fifth;
    printf("Enter dimensions(first, second, third, fourth,fifth):\n");
    scanf("%d %d %d %d %d", &first, &second, &third, &fourth,&fifth );
    printf("your dimenssion is arr[%d][%d][%d][%d][%d]\n",first,second,third,fourth,fifth);

    // allocate the 5D array arr[i][j][k][l][m]

    int *****arr = (int *****)malloc(first* sizeof(int ****));
    for (int i = 0; i < first; i++) {

        arr[i] = (int ****)malloc(second * sizeof(int ***));

        for (int j = 0; j < second; j++) {

            arr[i][j] = (int ***)malloc(third * sizeof(int **));
            
		for (int k = 0; k < third; k++) {
                	
			arr[i][j][k] = (int **)malloc(fourth * sizeof(int *));

			for(int l = 0;l<fourth;l++)
			{
				arr[i][j][k][l] = (int *)malloc(fifth * sizeof(int));
			}
            	}
        }
    }

    // Accept elements from the user
    printf("Enter the elements of the 5D array:\n");
    for (int i = 0; i < first; i++) {

        for (int j = 0; j < second; j++) {

            for (int k = 0; k < third; k++) {

                for (int l = 0; l < fourth; l++) {

			for(int m = 0; m < fifth; m++){

                    		scanf("%d", &arr[i][j][k][l][m]);
			}
                }
            }
        }
    }

    // Display the elements
    printf("The elements of the 5D array are:\n");
    for (int i = 0; i < first; i++) {

        for (int j = 0; j < second; j++) {

            for (int k = 0; k < third; k++) {

                for (int l = 0; l < fourth; l++) {

			for (int m = 0; m < fifth; m++){

                    		printf("arr[%d][%d][%d][%d][%d]=%d\n",i,j,k,l,m, arr[i][j][k][l][m]);
			}
                }
		printf("\n");
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < first; i++) {

        for (int j = 0; j < second; j++) {

            for (int k = 0; k < third; k++) {

		    for( int l=0; l < fourth;l++) {

			    free(arr[i][j][k][l]);
		    }

                free(arr[i][j][k]);
            }

            free(arr[i][j]);
        }

        free(arr[i]);
    }

    free(arr);


    return 0;
}
