/*********
 *  	 1
 *      2  2
 *    3  3  3
 *   4  4  4  4
 *    3  3   3
 *      2  2
 *     	 1
 *    	*/
/*
#include <stdio.h>

int main() {
    int n = 4;  // height of the top half (largest number)

    // Top half including middle
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int s = 0; s < n - i; s++) {
            printf(" ");
        }
        // Print numbers with spaces
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");



    }

    // Bottom half
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int s = 0; s < n - i; s++) {
            printf(" ");
        }
        // Print numbers with spaces
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}
*/



#include <stdio.h>

int main() {
    int n = 4;  // height of the top half

    for (int i = 1; i <= 2 * n - 1; i++) {

        int row = (i <= n) ? i : 2 * n - i;   // mirror row

        for (int j = 1; j <= n - row; j++)
	{ 
		printf(" ");
	}	// spaces
        for (int j = 1; j <= row; j++){
	       	printf("%d ", row); // numbers
	}
        printf("\n");
    }

    return 0;
}





