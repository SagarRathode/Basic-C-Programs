#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//this example demonstrates the Operator in C,C++,Swift 
//types of operator

struct Operator{
	int x;
	int y;
};


int main()
{
	printf("***** 1.ArithMatic Operators: *****\n");
	int no1 = 10;
	int no2 = 20;

	printf("no1 + no2 = %d \n",no1 + no2);
    	printf("no1 - no2 = %d\n", no1 - no2 );
    	printf("no1 * no2 = %d\n", no1 * no2);
    	printf("no1 / no2 = %d\n", no1 / no2);
    	printf("no1 %% no2 = %d\n",no1 % no2);


	// 2. Assignment Operators
   	 int x = 5;
    	printf("\n***** 2.Assignment Operators: *****\n");
    	printf("x = %d\n", x);
    	x += 3;
   	printf("x += 3 -> %d\n", x);
    	x -= 2;
    	printf("x -= 2 -> %d\n", x);
    	x *= 4;
    	printf("x *= 4 -> %d\n", x);
    	x /= 6;
    	printf("x /= 6 -> %d\n", x);
    	x %= 3;
    	printf("x %%= 3 -> %d\n", x);

    	// 3. Relational Operators
    	printf("\n***** 3.Relational Operators: *****\n");
    	printf("no1 == no2: %d\n", no1 == no2);
    	printf("no1 != no2: %d\n", no1 != no2);
    	printf("no1 > no2: %d\n", no1 > no2);
    	printf("no1 < no2b: %d\n", no1 < no2);
    	printf("no1 >= no2: %d\n", no1 >= no2);
    	printf("no1 <= no2: %d\n", no1 <= no2);

    	// 4. Logical Operators
    	bool p = true; 
	bool q = false;
    	printf("\n***** 4.Logical Operators: *****\n");
    	printf("p && q: %d\n", p && q);
    	printf("p || q: %d\n", p || q);
    	printf("!p: %d\n", !p);

    	// 5. Bitwise Operators
    	printf("\n***** 5.Bitwise Operators: ****** \n");
    	printf("no1 & no2: %d\n", no1 & no2);
    	printf("no1 | no2: %d\n", no1 | no2);
    	printf("no1 ^ no2: %d\n", no1 ^ no2);
    	printf("~no1: %d\n", ~no1);
    	printf("no1 << 1: %d\n", no1 << 1);
    	printf("no1 >> 1: %d\n", no1 >> 1);

    	// 6. Increment and Decrement
    	printf("\n***** 6.Increment and Decrement: *****\n");
    	int inc = 5;
    	printf("inc: %d\n", inc);
    	printf("inc++: %d\n", inc++); // Post-increment
    	printf("After inc++: %d\n", inc);
    	printf("++inc: %d\n", ++inc); // Pre-increment
    	printf("inc--: %d\n", inc--); // Post-decrement
    	printf("After inc--: %d\n", inc);
    	printf("--inc: %d\n", --inc); // Pre-decrement

    	// 7. Conditional (Ternary)
    	printf("\n***** 7.Conditional (Ternary) Operator: *****\n");
    	int max = (no1 > no2) ? no1 : no2;
    	printf("Max of %d and %d is %d\n", no1, no2, max);

    	// 8. Special Operators
    	printf("\n *****8.Special Operators: *****\n");
    	printf("sizeof(int): %zu bytes\n", sizeof(int));

    	struct Operator pt = {5, 10};
    	struct Operator *ptr = &pt;

    	printf("pt.x: %d, pt.y: %d\n", pt.x, pt.y);
    	printf("ptr->x: %d, ptr->y: %d\n", ptr->x, ptr->y);

    return 0;

}


Notes for Swift

✅ Swift doesn’t support ++ or --. Use += 1 and -= 1 instead.
✅ Swift uses MemoryLayout<T>.size instead of sizeof.
✅ Swift doesn’t have pointers like C, so there’s no -> operator. Use . for structs and classes.
✅ The syntax is safe and modern — it uses Bool for logical results.
