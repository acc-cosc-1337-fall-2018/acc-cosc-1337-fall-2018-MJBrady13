#include "basics.h"
#include<vector>
#include<iostream>
#include<string>

using std::cout; using std::vector; using std::endl; using std::string;

int sum_numbers(int num1, int num2)
{
	return num1 + num2;
}

int multiply_numbers(int num1, int num2)
{
	return num1 * num2;
}

void pass_by_val_by_ref(int val, int & ref)
{
	val = 99;
	ref = 99;
}

void const_pass_by_val_by_ref(int val, const int & ref)
{
	val = 99;
	//ref = 99; ref can't be modified because it's a const parameter
}

void pass_by_pointer(int * ptr)
{
	//ptr we're using the address
	*ptr = 99; //*ptr get the value of address pointed to
}

void initialize_vector_of_ints()
{
	vector<int> numbers = {5,7,9,4,6,8};
	numbers.push_back(1);

	for (auto n : numbers)
	{
		cout << n << '\n';
	}

	cout << numbers[1];
}

void initialize_vector_of_strings()
{
	vector<string> philosophers = {"Kant", "Plato", "Hume", "Kierkegaard"};
	philosophers.push_back("Socrates");

	for (auto p : philosophers)
	{
		cout << p << endl;
	}

	//vector<int> numbers(10);  initializes an empty vector of size 10.
}

MyClass::MyClass()
{
	std::cout << "Constructor...\n";
}

MyClass::MyClass(const MyClass& my_class)
{
	ptr_num = new int(*my_class.ptr_num);
}

void MyClass::set_ptr_num(int val)
{
	*ptr_num = val;
}

MyClass & MyClass::operator=(MyClass& other)
{
	delete other.ptr_num;
	ptr_num = new int(*other.ptr_num);
	return *this;
}

MyClass::~MyClass()
{
	std::cout << "Num: " << num << " Ptr num: " << *ptr_num << " Address: " << ptr_num << "Destructor...\n";
	delete ptr_num;
	ptr_num = nullptr;
}

DynamicPtr::DynamicPtr()
{
	ptr_num = new int(10);
	std::cout << "Constructor!";
}

DynamicPtr::~DynamicPtr()
{
	std::cout << "Destructor!";
	delete ptr_num;
	ptr_num = nullptr;
}
