
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int roll;
    int reg;
    float per;
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
    printf("Enter student's name: ");
    scanf("%s", newnode->name);
    printf("Enter student's reg_no.: ");
    scanf("%d", &newnode->reg);
    printf("Enter student's roll_no.: ");
    scanf("%d", &newnode->roll);
    printf("Enter student's percentage: ");
    scanf("%f", &newnode->per);
    newnode->next = NULL;
    return newnode;
}

node *inputStudentData(node *head, node **last)
{
    node *newStudent = createnode();
    (*last)->next = newStudent;
    *last = newStudent;
    printf("Data saved successfully!\n");
    return *last;
}

node *deleteStudent(node *head, int rolll)
{
    node *ptr = head;
    node *prev = NULL;

    while (ptr != NULL && ptr->roll != rolll)
    {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Student with roll number %d not found.\n", rolll);
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
    printf("Student with Roll no. %d Deleted Successfully\n", rolll);
    return head;
}

node *deleteStudentl(node *head)
{
    if (head->next == NULL)
    {
        printf("No student to delete.\n");
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
    printf("Last student deleted successfully.\n");
    return head;
}

void updateStudent(node *head)
{
    int rolll;
    printf("Enter the roll number of the student to update: ");
    scanf("%d", &rolll);

    node *ptr = head->next;
    while (ptr != NULL && ptr->roll != rolll)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Student with roll number %d not found.\n", rolll);
        return;
    }

    printf("Enter updated data:\n");
    printf("Enter student's name: ");
    scanf("%s", ptr->name);
    printf("Enter student's reg_no.: ");
    scanf("%d", &ptr->reg);
    printf("Enter student's roll_no.: ");
    scanf("%d", &ptr->roll);
    printf("Enter student's percentage: ");
    scanf("%f", &ptr->per);
    printf("Data updated successfully!\n");
}

void displayStudent(node *head)
{
    node *ptr = head->next;
    if (ptr == NULL)
    {
        printf("No students to display.\n");
        return;
    }

    printf("********************************************************");
    printf("\n          Available Student Data               ");
    printf("\n| Name\t | Roll\t | Reg\t | Percentage |\n");

    while (ptr != NULL)
    {
        printf("| %s\t | %d\t | %d\t | %.2f %%     |  \n", ptr->name, ptr->roll, ptr->reg, ptr->per);
        ptr = ptr->next;
    }
    
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
    
    int choice, pick, rolll;

    while (1)
    { 
	printf("*********************************************************\n");
        printf("\n              Student Database Menu                   \n");
        printf("1. Insert student data\t2. Delete student data\n");
        printf("3. Update student data\t4. Display all student data\n");
        printf("5. Exit");
        printf("\n*********************************************************\n");
        printf("Enter Your Choice:");
	scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                last = inputStudentData(head, &last);
                break;
            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &rolll);
                head = deleteStudent(head, rolll);
                break;
            case 3:
                updateStudent(head);
                break;
            case 4:
                displayStudent(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

