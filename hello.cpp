#include<iostream>
using namespace std;

class MyClass {       
   public:             
      int myNum;        
      string myString; 
	void displayBase()
        {
		cout<<"BASE CLASS"<<endl;
	} 
virtual void display(int number)
   	{
            cout<<"base class number"<<number<<endl;
	}
};
class child : public MyClass
{
   	        public:
                int num;
              	void display(int number)
		{
                        num = number + 5;
			cout<<"child number is"<<num<<endl;
			
                } 
};

int main() {

     MyClass myObj;  
  
  // myObj.myNum = 123; 
  // myObj.myString = "Hello";

  // cout << myObj.myNum << "\n";
  // cout << myObj.myString<<"\n";
  


     child cobj;
 //  cobj.display(10);
//   myObj.display(10);
//   cobj.displayBase();
   


     MyClass *ptr;      // base class pointer
     ptr = &cobj;      //base class pointer pointing to child object
     ptr->display(20);

   return 0;
}
