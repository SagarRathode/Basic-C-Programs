#include<stdio.h>
#define TEN 10
int main()
{
  int Number1,Number2,Number3,Number4;
  printf("Enter two number\n");
  scanf("%d%d",&Number1,&Number2);
  Number3=Number1 + Number2;
  Number4 = Number1 + TEN ;
  printf("Macro Addition:%d",Number4);
  printf("Addition %d",Number3);	
  return 0;
}




//commands to execute toolchain
//1 way
//gcc -E demo.c -o demo.i
//gcc -S demo.i -o demo.s
//as -o demo.o demo.S
//gcc demo.o -o demo 
// ./demo

//2 way

//gcc -E demo.c -o demo.i
//gcc -S demo.i -o demo.s
//gcc -c demo.o demo.S
//gcc demo.o -o demo 
// ./demo
