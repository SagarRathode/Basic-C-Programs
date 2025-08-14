#include<stdio.h>
void pattern(int iRow,int iCol)
{
	char Ch = 'E';
	int i = 1,j = 1;
	for(i=1;i<=iRow;i++,Ch--,printf("\n"))
	{
		for(j=1;j<=iCol;j++)
		{
			printf("%c ",Ch);
		
		}
	}

	printf("\n");
}
int main()
{
	int iRow=1,iCol=1;
	printf("Enter number of Rows=>");
	scanf("%d",&iRow);
	printf("Enter number of Columns=>");
	scanf("%d",&iCol);
	pattern(iRow,iCol);
}
