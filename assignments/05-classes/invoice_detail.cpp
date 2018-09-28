#include "invoice_detail.h"
#include <iostream>

double InvoiceDetail::get_extended_cost()
{
	return cost*units;
}
