//write the dna.h include statement here
#include"dna.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//call the dna functions from dna.h and display output
	//Use the function arguments from the test cases in dna_test.cpp
	//Example:
	/*
	auto point_mutation = get_point_mutations("GAGCCTACTAACGGGAT", "CATCGTAATGACGG")
	cout<<point_mutation;
	*/
	//auto point_mutation1 = get_point_mutations("GAGCCTACTAACGGGAT", "CATCGTAATGACGG");
		//cout << point_mutation1;

	auto point_mutation2 = get_point_mutations("GAGCCTACTAACGGGAT", "GAGCCTACTAACGGGAT");
		cout << point_mutation2;

	auto point_mutation3 = get_point_mutations("GAGCCTACTAACGGGAT", "GATCGTAATGACGGCAT");
		cout << point_mutation3;

	auto point_mutation4 = get_point_mutations("GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT");
		cout << point_mutation4;

	auto dna_complement1 = get_dna_complement("AAAACCCGGT");
		cout << dna_complement1;

	auto dna_complement2 = get_dna_complement("CCCGGAAAAT");
		cout << dna_complement2;

	auto rna1 = transcribe_dna_into_rna("GATGGAACTTGACTACGTAAATT");
		cout << rna1;

	auto rna2 = transcribe_dna_into_rna("AAATTGATCTTGACTACGTGGAA");
		cout << rna2;

	auto gc_content = get_gc_content("CCACCCTCGTGGTATGGCTAGGCATTCAGGAACCGGAGAACGCTTCAGACCAGCCCGGACTGGGAACCTGCGGGCAGTAGGTGGAAT");
		cout << gc_content;

	return 0;
}