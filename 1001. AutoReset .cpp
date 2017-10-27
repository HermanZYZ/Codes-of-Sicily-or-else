#include <iostream>
 using namespace std; 

class AutoReset 
 {
  public:
          AutoReset(int *scoped_variable, int new_value);
         ~AutoReset();
 private:
         int *scoped_variable_;
         int original_value;
 }; 

AutoReset:: AutoReset(int *scoped_variable, int new_value)
{
	scoped_variable_=scoped_variable;
	original_value=*scoped_variable;
	*scoped_variable=new_value;	
}

AutoReset::~AutoReset()
{
	*scoped_variable_=original_value;
}

   


int main(int argc, char *argv[])
 {
          int value;
          int count = 0;

         while (cin >> value) {

               {
                       AutoReset auto_reset(&value, count);
                       value *= 2;
                       count++;
                       cout << value << " ";
                }

               cout << value << endl;
          }
          return 0;
 }

