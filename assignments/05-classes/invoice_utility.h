#ifndef INVOICE_UTILITY_H
#define INVOICE_UTILITY_H
#include"invoice.h"


class InvoiceUtility : public Invoice
{
public:
	InvoiceUtility(double fc): fixed_costs(fc){}
	double get_total() const;
	
private:
	double fixed_costs;
};

#endif //INVOICE_UTILITY_H