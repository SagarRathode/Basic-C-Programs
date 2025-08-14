<<<<<<< HEAD
w 
=======

>>>>>>> fc97c49 (pattern)
/*
 *   1 1 1 1 1
 *   A B C D E
 *   * * * * *
 *   A B C D E
 *   1 1 1 1 1
 *
 *
<<<<<<< HEAD
 * below program have two function pattern1 and pattern 
 * both function print same pattern 
=======
 *
>>>>>>> fc97c49 (pattern)
 *
 *
 *
 */







#include<stdio.h>
<<<<<<< HEAD
void pattern1(int iRow,int iCol)
=======
/*void pattern(int iRow,int iCol)
>>>>>>> fc97c49 (pattern)
{
	char Ch = 'A';
	int i = 1,j = 1;
	for(i=1;i<=iRow;i++)
	{
		Ch='A';
		for(j=1;j<=iCol;j++)
		{
			if(i/2 != 0)
			{
				if(i==3)
				{
					printf("*");
				}else if(i==5)
				{
					printf("1");
				}
				else
				{
					printf("%c",Ch);
					Ch++;
				}
					
			}else
			{
				printf("1");
			}

		
		}
		printf("\n");

	}

	printf("\n");
}
<<<<<<< HEAD
=======
*/
>>>>>>> fc97c49 (pattern)


void pattern(int iRow, int iCol)
{
    int i = 1,j = 1;
    for (int i = 1; i <= iRow; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= iCol; j++)
        {
            if (i == 1 || i == iRow)           // first or last row
                printf("1 ");
            else if (i == (iRow + 1) / 2)      // middle row
                printf("* ");
            else
                printf("%c ", ch++);
        }
        printf("\n");
    }
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
