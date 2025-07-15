#include<stdio.h>
#include<stdlib.h>
#define size 100

typedef struct node
{
	int id,salary;
	char name[20],designation[20];
	struct node *next;
}node;

// create node
node *createnode()
{
	node* newnode = (node*)malloc(sizeof(node));
	printf("Enter Employee Name:");
	scanf("%c",&newnode->name);
	printf("\nEnter Employee id:");
	scanf("%d",&newnode->id);
        printf("\n Enter Salary:");
        scanf("%d",&newnode->salary);
	printf("\n Enter Designation:");
	scanf("%c",&newnode->designation);
        newnode->next = NULL;
	return newnode;
}


//insert data

node *insertEmployeeData(node *head,node *last)
{
	node *ptr = head;
	node *qtr = last;
	if(ptr->next==NULL)
	{
		 ptr->next = createnode();
                 printf("Data saved succesfully !\n");
                 last = ptr->next;
        }
    	else
    	{
        	while (ptr->next != NULL)
        	{
            		ptr = ptr->next;
            		last = ptr;
        	}
        	ptr->next = createnode();
        	printf("Data saved succesfully !\n");

    	}
    	return last;
}

//delete Employee data
node *deleteEmployeeData(node *head, int idd)
{
    node *temp, *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->id == idd)
        {
            temp = ptr;
            ptr->next = ptr->next->next;
            free(temp);
            printf(" employee with id. %d Deleted Successfully\n", idd);
        }
        else
            ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("We don't have any employee with id. %d", idd);
    }
    return head;
}

node *deleteLastEmployeeData(node *head)
{
    node *ptr = head;
    node *last;

    while (ptr->next != NULL)
    {
        last = ptr;
        ptr = ptr->next;
    }

    if (head->next == NULL)
    {
        printf("There is no employee to be deleted : \n");
    }
    else
    {
        node *temp = last->next;
        last->next = NULL;
        free(temp);
        printf("Last Employee Deleted Successfully\n");
    }
    return head;
}


void updateEmployeeData(node *head)
{
    int id1;
    node *ptr = head;
    if (ptr->next == NULL)
    {
        printf("There is no employee to be Updated : \n");
    }
    else
    {

        printf("Enter the emp id. whose data is to be updated : ");
        scanf("%d", &id1);

        while (ptr->id1 != idd && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->id1 == idd)
        {
            printf("Enter data to be updated :");
            printf("\nEnter Employee's name : ");
            scanf("%s", &ptr->name);
            printf("Enter  Employee id. : ");
            scanf("%d", &ptr->id1);
            printf("\nEnter Employee Salary : ");
            scanf("%d", &ptr->salary);
	    printf("\nEnter Employee Designation");
	    scanf("%s",&ptr->designation);
            printf("Data Updated Successfully !\n");
        }
        else
        {
            printf("\nemployee id. did not match");
        }
    }
}

void displayEmployeeData(node *head)
{
    node *ptr = head;
    if (head->next == NULL)
    {
        printf("There is noting to display .");
    }
    else
    {
        printf("\nAvailable data in list is :");
        printf("\nName \tId \tSalary \tDesignation.");
        while (ptr != NULL)
        {
            ptr = ptr->next;
            printf("\n%s \t%d \t%d \t%s.", ptr->name, ptr->id, ptr->salary, ptr->designation);
        }
    }
}

int main()
{
    node *head, *last;

    int choice, pick;
    head->next = NULL;
    last = head;
    ;
    int empId, i = 0;

    while (i < size)
    {
        printf("\nEmployee Database Menu:\n");
        printf("1. Insert Employee data \t\t2. Delete Employee data\n");
        printf("3. Update Employee data \t\t4. Display all Employee data\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            last = insertEmployeeData(head, last);
            i++;
            break;
        case 2:
            printf("1. Delete by id. \t\t2. Delete last added student\n");
            printf("Enter your choice: ");

            scanf("%d", &pick);
            switch (pick)
            {
            case 1:
                printf("Enter the Roll No of the student to delete: ");
                scanf("%d", &empId);
                head = deleteEmployeeData(head, empId);
                break;
            case 2:
                head = deleteLastEmployeeData(head);
                break;
            default:
                printf("Only 1 & 2 are accepted ");
            }
            i--;
            break;
        case 3:
            updateEmployeeData(head);
            break;
        case 4:

            displayEmployeeData(head);
            break;
        default:    
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


