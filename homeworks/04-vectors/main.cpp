//write include statement for vectors header
//write include statement for cout object
#include "vectors.h"
#include<iostream>

//dont forget using statement for cout object
using namespace std;

int main() 
{
	//Write code to call get_max_from_vector with argument
	//vector of values 4, 5, 1, 50, 6, 77, 0 and display max
	std::vector<int> vec1{ 4, 5, 1, 50, 6, 77, 0 };
	int max = get_max_from_vector(vec1);
	cout << max << endl;

	//write code to call the sum_of_square function with argument
	//vector of values 2, 3, 4 and display result
	std::vector<int> vec2{ 2, 3, 4 };
	int sum_sq = sum_of_squares(vec2);
	cout << sum_sq << endl;

	//write code to call the replace function with argument 
	//vector of strings "Joe", "joe", "mary", old argument "joe", new argument "John"
	std::vector<string> names{ "Joe", "joe", "mary" };
	replace(names, "joe", "John");

	
	//write code to call is_prime with value 3 output result
	bool prime = is_prime(3);
	cout << prime << endl;

	//write code to call vector_of_primes, save return value to a vector of ints
	//output each int in the return vector
	std::vector<int> primes = vector_of_primes(10);
	int vector_size = primes.size();
	for (int i = 0; i <= vector_size; i++)
	{
		cout << primes[i] << endl;
	}

	return 0;
}