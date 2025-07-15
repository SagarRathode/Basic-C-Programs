#include<stdio.h>

double add(double no1,double no2){
	return no1+no2;
}


int main(){
  
    double no1,no2;
    scanf("%lf%lf",&no1,&no2);
    double no3 = add(no1,no2);
    printf("Addition is: %lf",add(no1,no2));
 
}
