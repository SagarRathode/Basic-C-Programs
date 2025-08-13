



/*
 
This program demonstrate below pattern and accept number of rows and columns
 
Output:

Enter The Number Of Rows=>5
Enter The Number Of Columns=>5
 A  B  C  D  E 
 a  b  c  d  e 
 A  B  C  D  E 
 a  b  c  d  e 
 A  B  C  D  E 
 
*/

#include<stdio.h>

void Pattern(int iRow,int iCol)
{
    int iNo1=1,iNo2=1;
    int Ch=0;
    for(iNo1=1;iNo1<=iRow;iNo1++)
    {
        for(iNo2=1;iNo2<=iCol;iNo2++)
        {
            if(iNo1%2!=0)
            {
                Ch=64;
                printf(" %c ",Ch+iNo2);
            }
            else
            {
                Ch=96;
                printf(" %c ",Ch+iNo2);
            }

        }
        printf("\n");
    }
}

int main()
{
    int iValue1=0,iValue2=0;

    printf("Enter The Number Of Rows=>");
    scanf("%d",&iValue1);
    printf("Enter The Number Of Columns=>");
    scanf("%d",&iValue2);
    Pattern(iValue1,iValue2);

    return 0;
}
