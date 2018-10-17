#include<iostream>
#include "basics.h"

using std::cout;

void func() 
{
	//dynamic memory allocation-allocated on the heap
	int* ptr_n = new int(5);
	cout << ptr_n<<std::endl;
	//WE ARE RESPONSIBBLE FOR RELEASING IT!!!!
	delete ptr_n;
}

int main()
{	

	func();
		
	
	/*int num{ 5 };
	int& num_ref = num;
	cout << "Address of num: " << &num << std::endl;
	cout << "Value at address stored by num_ref: " << num_ref << std::endl;
	cout << "Address stored at num_ref: " << &num_ref<<std::endl;

	int* ptr_num = &num_ref;
	cout << "Value pointed to by ptr_num: " << *ptr_num << std::endl;
	cout << "Address of num: " << ptr_num << std::endl;
	cout << "Address of the ptr_num: " << &ptr_num << std::endl;*/
	
	
	
	//const int read_only = 10;
	//read_only = 15;
	//cout << sum_numbers(5, 5);
	//initialize_vector_of_ints();

	//initialize_vector_of_strings();

	return 0;
}
