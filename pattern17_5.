/////////////////////////////////////////////////////////////
// this program accept input rows and columns from user
// and print the below pattern
//
// Output:-
// Enter The Number of Rows => 5
// Enter The Number of Columns=> 5
// *      *   *  *
// *      *      
// *  *   *   *  *
//        *      *
// *  *   *      *
//////////////////////////////////////////////////////////////
#include<stdio.h>

void Pattern(int iRow, int iCol)
{
    for(int i=1; i<=iRow; i++)
    {
        for(int j=1; j<=iCol; j++)
        {
		// 1st way //here we check which position * required

           /* if((i==1 && (j==1 || j==3 || j==4||j==5)) ||       // Row 1
               (i==2 && (j==1 || j==3)) ||               // Row 2
               (i==3 && (j==1 || j==2 || j==3 || j==4 || j==5)) || // Row 3
               (i==4 && (j==3 || j==5)) ||               // Row 4
               (i==5 && (j==1 || j==2 || j==3 || j==5)))         // Row 5
            {
                printf(" * ");
            }else
	    {
		    printf("   ");
	    }
	    */

		// 2nd way
		// here we check condition which position space required
		
	    if((i == 1 && (j==2)) ||                   // row 1
	       (i == 2 && (j==2 || j==4 || j==5)) ||   // row 2
	       (i == 4 && (j==1 || j==2 || j==4)) ||   // row 4
	       (i == 5 && (j==4)))                     // row 5
		{
		      printf("   ");
	      	}
	    	else{
		    printf(" * ");
	    	}
        }
        printf("\n");
    }
}

int main()
{
    int iValue1 = 5, iValue2 = 5;  // 5 rows, 5 cols
    Pattern(iValue1, iValue2);
    return 0;
}
