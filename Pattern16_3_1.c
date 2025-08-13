
/*Accept Number of Rows=4 and Columns=4 from user and print below pattern
 A
 A B 
 A B C
 A B C D
*/
#include<stdio.h>
void pattern(int iRow,int iCol)
{
	int iNo1=1;
	int iNo2=1;
	for(iNo1=1;iNo1<=iRow;iNo1++)
	{
		char Ch = 'A';
		for(iNo2=1;iNo2<=iNo1 & iNo2<=iCol ;iNo2++)
		{
			printf("%c",Ch);
			printf(" ");
			Ch++;
		}
		printf("\n");
	}
}
int main()
{
	int iRow,iCol;
	printf("Enter Number Of Rows =>");
	scanf("%d",&iRow);
	printf("Enter Number of Columns =>");
	scanf("%d",&iCol);
	pattern(iRow,iCol);
	return 0;
}
