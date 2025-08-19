/////////////////////////////////////////////////////////////
// this program accept input rows and columns from user
// and print the below pattern
//
// Output:-
// Enter The Number of Rows => 5
// Enter The Number of Columns=> 5
// 1  2  * 4  5
// 6  7  * 9  10
// 11 12 * 14 15
// 16 17 * 19 20
// 21 22 * 24 25
//////////////////////////////////////////////////////////////
#include<stdio.h>

void Pattern(int iRow,int iCol)
{
    int iNo1=1,iNo2=1,Cnt=11;

    for(iNo1=1;iNo1<=iRow;iNo1++)
    {
        //for(iNo2=1;iNo2<=iCol;iNo2++,Cnt=(Cnt==9)?1:Cnt+1) // we add here our if else condition using ternary
	for(iNo2=1;iNo2<=iCol;iNo2++)
        {
	
           // printf(" %d ",Cnt);
	    if(iNo2 == 3)
	    {
		    printf("  * ");
	    }
	    else
	    {
		    printf(" %d ",Cnt);
		   
	    }
	    Cnt++;
        }
        printf("\n");
    }
}
int main()
{
    int iValue1=0,iValue2=0;

    printf("Enter The Number Of Rows=> ");
    scanf("%d",&iValue1);
    printf("Enter The Number of Columns=> ");
    scanf("%d",&iValue2);
    Pattern(iValue1,iValue2);

    return 0;
}
