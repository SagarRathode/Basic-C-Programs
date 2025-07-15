//Function overloading
//constructor
//destructutor
//copy consturctor,default,parameterized

#include <iostream>
using namespace std;
int add(int no1,int no2) 
{
        cout<<"Addition of no1 + no2 ="<<no1+no2<<endl;
        return no1+no2;
}
int add(double no3,int no2) //function overloadiong
{
        cout<<"Addition of type double and int no3 + no2 ="<<no3+no2<<endl;
        return no3+no2;
}
class Abc{
         
	      
              int no1;
              int no2;
	      int *ptr;
	      int *p;
              public:
	      static int x;
              Abc(){ //constructor
		  cout<<endl;
		  cout<<"constructor called"<<endl;
                  cout<<endl;

                  no1=502;
	          no2=501;

                  ptr = new int[5]; //new operator use for allocate memory
		  cout<<"Enter 5 numbers"<<endl;
		  for(int i=0;i<5;i++){
		  	cin>>ptr[i];
		  }
                  cout<<"your number is:"<<endl;
                  for(int i=0;i<5;i++){
			cout<<ptr[i]<<endl;
		  }
                  cout<<endl;
		  delete(ptr);
              }
	      Abc(string s1){ // parameterized constructor
                 cout<<s1<<endl;
		}

              void display(){
                     cout<<"no1+no2 is:"<<no1+no2<<endl;
	      }

	      Abc(Abc &a){ //deep copy constructor
		no1 = a.no1;
		no2 = a.no2;
		p = new int[1];
                *p = *(a.p);
		}
		
		void setData(int n1,int n2,int n3=50){ // shallow copy & default parameter
		        no1=n1;
                        no2=n2;
			*p=n3;
		}
		void showData(){
			cout<<"no1 is:"<<no1<<endl;
			cout<<"no2 is:"<<no2<<endl;
			cout<<"p is:"<<*p<<endl;
		}
	      ~Abc(){
		cout<<"Destructor called"<<endl;
		delete(p); // delete operator for use free memory
		
		}
};

int Abc::x = 500; //scope resolution operator

int main() {
    
	Abc obj;
        obj.display();
        obj.setData(1,2,3);
	Abc obj1 = obj;//copy constructor called (obj to obj1)
        obj1.showData();
        cout<<"class abc object size is:"<<sizeof(obj)<<"byte"<<endl;
        Abc obj2("parameterized constructor");

        cout<<endl;
        cout<<"static variable Abc::x="<<Abc::x<<endl;

    // Write C++ code here
    std::cout << "Addition of 2 Numbers"<<endl;
    int no1,no2;
    double no3;
    cout<<"Enter no1 type int"<<endl;
    cin>>no1;
    cout<<"Enter no2 type int"<<endl;
    cin>>no2;
    cout<<"Enter no3 type double"<<endl;
    cin>>no3;
    add(no1,no2);
    add(no3,no2);
    return 0;
}
