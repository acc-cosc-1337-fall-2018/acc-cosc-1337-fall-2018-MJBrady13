#include "vectors.h"
#include<algorithm>
#include<iostream>

int get_max_from_vector(vector<int>& numbers)
{
	//write your code here
	auto max_num = max_element(std::begin(numbers), std::end(numbers));

	return *max_num;
}

//write the code for sum_of_squares function here
int sum_of_squares(vector<int>& numbers)
{
	int square_sum{ 0 };
	for (auto n : numbers)
	{
		square_sum += n * n;
	}
	return square_sum;
}


//write the code for function replace here
void replace(vector<string>& strings, const string& old, const string& new_val)
{
	//write code here. 
	//Remember passing by reference without keyword const makes the string vector
	//read/write meaning you can modify strings in the vector
	//Also there is no need to return the strings vector because a reference
	//points to a previously declared vector of strings variable(see test case 
	//in vectors_test.cp)


}

//write is_prime function code here
bool is_prime(int num)
{
	for (int i = 2; i <= num / 2; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}


//write vector_of_primes function code here
vector<int> vector_of_primes(int num)
{
	vector<int> primes;
	for (int i = 2; i <= num; i++)
	{
		if (is_prime(i))
		{
			primes.push_back(i);
		}
	}
	return primes;
}
