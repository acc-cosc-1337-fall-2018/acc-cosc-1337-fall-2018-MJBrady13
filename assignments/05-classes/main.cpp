#include "invoice.h"
#include"invoice_utility.h"
#include <iostream>

int main() 
{
	Invoice invoice;

	InvoiceDetail detail;
	std::cin >> detail;

	invoice.add_invoice_detail(detail);
	invoice.add_invoice_detail(InvoiceDetail(5, 5));
	invoice.add_invoice_detail(InvoiceDetail(100, 2));

	Invoice invoice1;
	invoice1.add_invoice_detail(InvoiceDetail(100, 2));

	Invoice result = invoice + invoice1;
	std::cout <<result.get_total()<< "\n";
	
	InvoiceUtility inv(25);
	inv.add_invoice_detail(InvoiceDetail(100, 1));
	std::cout << inv.get_total();
	



	return 0;
}