#include "recursion.h"

void call_myself(int num)
{
	if (num == 0)
	{
		std::cout << "base case 0 \n";
		return;
	}
	std::cout << "load...\n" << num<<"...\n";
	call_myself(num-1);
	std::cout << "unload "<< num<<"..\n";
}

int factorial(int num)
{
	int temp;

	if (num = 1)
	{
		std::cout << num <<" base case\n";
		return 1;
	}
	std::cout << num << " load\n";
	temp = num * factorial(num - 1);
	std::cout << temp << " " << num << " unload\n";
	return temp;
}
