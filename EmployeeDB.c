#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int employee;
    int reg;
    float salary;
    char name[30];
    struct node *next;
} node;

node *createnode()
{
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter employee's name: ");
    scanf("%s", newnode->name);
    printf("Enter employee's reg_no.: ");
    scanf("%d", &newnode->reg);
	if(newnode->reg<=0){
		printf("Please Enter valid Number\n");
		exit(1);
	}
		
    printf("Enter employee's employee_no.: ");
    scanf("%d", &newnode->employee);
    printf("Enter employee's salary: ");
    scanf("%f", &newnode->salary);
    newnode->next = NULL;
    return newnode;

}

node *inputEmployeeData(node *head, node **last)
{
    node *newEmployee = createnode();
    (*last)->next = newEmployee;
    *last = newEmployee;
    printf("Data saved successfully!\n");
    return *last;
}

node *deleteEmployee(node *head, int employeel)
{
    node *ptr = head;
    node *prev = NULL;

    while (ptr != NULL && ptr->employee != employeel)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("employee with employee number %d not found.\n", employeel);
        return head;
    }

    if (prev == NULL)
    {
        head = ptr->next;
    }
    else
    {
        prev->next = ptr->next;
    }

    free(ptr);
    printf("employee with employee no. %d Deleted Successfully\n", employeel);
    return head;
}

node *deleteEmployeel(node *head)
{
    if (head->next == NULL)
    {
        printf("No employee to delete.\n");
        return head;
    }

    node *ptr = head;
    node *prev = NULL;

    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next = NULL;
    free(ptr);
    printf("Last employee deleted successfully.\n");
    return head;
}

void updateEmployee(node *head)
{
    int employeel;
    printf("Enter the employee number of the employee to update: ");
    scanf("%d", &employeel);

    node *ptr = head->next;
    while (ptr != NULL && ptr->employee != employeel)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("employee with employee number %d not found.\n", employeel);
        return;
    }

    printf("Enter updated data:\n");
    printf("Enter employee's name: ");
    scanf("%s", ptr->name);
    printf("Enter employee's reg_no.: ");
    scanf("%d", &ptr->reg);
    printf("Enter employee's employee_no.: ");
    scanf("%d", &ptr->employee);
    printf("Enter employee's salary: ");
    scanf("%f", &ptr->salary);
    printf("Data updated successfully!\n");
}

void displayEmployee(node *head)
{
    node *ptr = head->next;
    if (ptr == NULL)
    {
        printf("No Employees to display.\n");
        return;
    }

    printf("\nAvailable employee data:");
    printf("\nName\temployee\tReg\tsalary\n");

    while (ptr != NULL)
    {
        printf("%s\t %d\t\t%d\t%.2f\n", ptr->name, ptr->employee, ptr->reg, ptr->salary);
        ptr = ptr->next;
    }
}
// Function to search for a Employee by reg_no
void searchStudent(node* head, int reg_no) {
    node* current = head;
    while (current != NULL) {
        if (current->reg == reg_no) {
            printf("\n--- Employee Found ---\n");
            printf("Name           : %s\n", current->name);
            printf("Reg No.        : %d\n", current->reg);
            printf("Employee No.   : %d\n", current->employee);
            printf("Salary         : %.2f\n", current->salary);
            return;
        }
        current = current->next;
    }
    printf("Employee with reg_no %d not found.\n", reg_no);
}





int main()
{
    node *head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    head->next = NULL;
    node *last = head;
    
    int choice, pick, employeel,reg_to_search;

    while (1)
    {
        printf("\nEmployee Database Menu:\n");
        printf("1. Insert employee data\t2. Delete employee data\n");
        printf("3. Update employee data\t4. Display all employee data\n");
        printf("5. Exit                \t6.Search Employee by reg no \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                last = inputEmployeeData(head, &last);
                break;
            case 2:
                printf("Enter employee number to delete: ");
                scanf("%d", &employeel);
                head = deleteEmployee(head, employeel);
                break;
            case 3:
                updateEmployee(head);
                break;
            case 4:
                displayEmployee(head);
                break;
            case 5:
                exit(0);
	    case 6:
		printf("\nEnter reg_no to search: ");
    		scanf("%d", &reg_to_search);
		searchStudent(head,reg_to_search);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
