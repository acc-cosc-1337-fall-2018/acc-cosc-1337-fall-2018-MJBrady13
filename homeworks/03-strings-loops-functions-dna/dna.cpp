#include<math.h>
#include<iostream>
#include<algorithm>
#include "dna.h"

using namespace std;

int get_point_mutations(std::string dna1, std::string dna2)
{	//write the function code 
	int H_dist = 0;
	int index = 0;

	auto size1 = dna1.size();
	auto size2 = dna2.size();
	if (size1 = !size2) {
		return -1;
	}
	for (auto letter : dna1)
	{
		if (dna1[index] != dna2[index]) {
			H_dist += 1;
		}
		index += 1;
			
	}
	
	return H_dist;
}


//write function code for std::string get_dna_complement(std::string dna)
std::string get_dna_complement(std::string dna)
{
	std::string dna_string = dna;
	reverse(dna_string.begin(), dna_string.end());

	std::string comp_string = "";

	for (auto letter : dna_string)
	{
		if (letter == 'A') {
			comp_string += 'T';
		}
		else if (letter == 'T'){
			comp_string += 'A';
		}
		else if (letter == 'C') {
			comp_string += 'G';
		}
		else {
			comp_string += 'C';
		}
	}

	return comp_string;
}


//write function code for std::string transcribe_dna_into_rna(std::string dna);
std::string transcribe_dna_into_rna(std::string dna)
{
	std::string rna = dna;
	replace(rna.begin(), rna.end(), 'T', 'U');
	return rna;
}


double get_gc_content(std::string dna)
{
	auto size = dna.size(); //get the size of string let auto handle the data type
	auto gc_count{ 0 }; //initialize to 0 (int) let auto handle data type

	//for ranged loop, for each character in loop, s holds one char
	//auto determines data type in this case s is a char data type
	for (auto s : dna)
	{
		//in C++ logical and is && and logical or is ||
		//usage (and) condition1 && condition2 --- usage (or) condition1 || condition2 
		//write code to determine if s is 'C' or 'G' then increment gc_count by 1
		if (s == 'C' || s == 'G') 
		{
			gc_count += 1;
		}

	}

	//dividing two integers nets an integer
	//here we need to convert one of the integers to double to get double division
	//that is a result with decimal values
	//static_cast converts a data type from one to another
	//here temporarily convert size to double
	auto gc_content = (gc_count / static_cast<double>(size))*100;

	//custom function to round to a desired precision
	return round_to_precision(gc_content, 2);
}


double round_to_precision(double number, int precision)
{
	return (std::round(number * std::pow(10, precision))) / std::pow(10, precision);
}
