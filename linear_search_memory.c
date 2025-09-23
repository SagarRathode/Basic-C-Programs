#include <stdio.h> 
#define SIZE 20 
int main() { 
	int memory[SIZE] = {10, 0, 20, 0, 30, 40, 0, 50, 60, 0, 70, 80, 0, 90, 100, 0, 0, 0, 0, 0}; 
	int key, flag = 0, offset = -1; 
	printf("Memory block:\n"); 
	for (int i = 0; i < SIZE; i++) 
		printf("%d ", memory[i]); 
	printf("\n\n"); 
	printf("Enter key to search: "); 
	scanf("%d", &key); 
	for (int i = 0; i < SIZE; i++) 
	{ 
		if (memory[i] == key) 
		{ 
			flag = 1; 
			offset = i; 
			break; 
		} 
	} 
	if (flag) 
		printf(" Key %d found at offset %d.\n", key, offset); 
	else 
		printf(" Key %d not found.\n", key); 
	return 0; 
}



/*
 
Memory block:
10 0 20 0 30 40 0 50 60 0 70 80 0 90 100 0 0 0 0 0

Enter key to search: 70
Key 70 found at offset 10.

*/
