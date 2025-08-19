/////////////////////////////////////////////////////////////
// this program accept input rows and columns from user
// and print the below pattern
//
// Output:-
// Enter The Number of Rows => 5
// Enter The Number of Columns=> 5
// 12345
// 67891
// 23456
// 78912
// 34567
//////////////////////////////////////////////////////////////
#include<stdio.h>

void Pattern(int iRow,int iCol)
{
    int iNo1=1,iNo2=1,Cnt=1;

    for(iNo1=1;iNo1<=iRow;iNo1++)
    {
        //for(iNo2=1;iNo2<=iCol;iNo2++,Cnt=(Cnt==9)?1:Cnt+1) // we add here our if else condition using ternary
	for(iNo2=1;iNo2<=iCol;iNo2++)
        {
            printf(" %d ",Cnt);
	    if(Cnt == 9)
	    {
		    Cnt = 1;
	    }
	    else
	    {
		    Cnt++;
	    }
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
