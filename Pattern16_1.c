
/* input -> Row = 5,Columns = 5
A B C D E
A B C D E
A B C D E
A B C D E
*/

//Sagar Rathode
#include<stdio.h>

void Pattern(int iRow,int iCol)
{
    int iNo1=1,iNo2=1;
    char Ch='A';
    for(iNo1=1;iNo1<=iRow;iNo1++)
    {
        for(iNo2=1,Ch='A';iNo2<=iCol;iNo2++,Ch++)
        {
            printf(" %c ",Ch);
        }
        printf("\n");
    }
}
int main()
{
    int iValue1=0,iValue2=0;

    printf("Enter The Number Of Rows => ");
    scanf("%d",&iValue1);
    printf("Enter The Number of Columns =>");
    scanf("%d",&iValue2);

    Pattern(iValue1,iValue2);

    return 0;
}
