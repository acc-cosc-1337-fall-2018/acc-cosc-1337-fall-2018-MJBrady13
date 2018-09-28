#include "invoice_detail.h"
#include <iostream>

int main() 
{
	InvoiceDetail inv(10, 10);

	std::cout << inv.get_extended_cost();

	return 0;
}