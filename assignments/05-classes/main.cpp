#include "invoice.h"
#include"invoice_utility.h"
#include"invoice_progress.h"
#include <iostream>
#include<vector>

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
	
	InvoiceProgress invp(250);
	invp.add_invoice_detail(InvoiceDetail(100, 1));

	InvoiceUtility invu(25);
	invu.add_invoice_detail(InvoiceDetail(100, 1));

	std::cout<<invu.get_total()<<"\n";
	std::cout<<invp.get_total() << "\n";

	Invoice& u = invu;
	Invoice& p = invp;

	std::cout<<u.get_total() << "\n";
	std::cout<<p.get_total() << "\n";


	return 0;
}

/*class Shape
{
public:
	virtual void draw() { std::cout << "Shape\n"; }
};

class Line : public Shape
{
public:
	void draw() { std::cout << "Line\n"; }
};

class Circle : public Shape
{
public:
	void draw() { std::cout << "Circle\n"; }
};

int main()
{
	std::vector<std::reference_wrapper<Shape>> shapes;	
	Line line;	
	Circle c;
	shapes.push_back(line);
	shapes.push_back(c);

	for (auto w_r_shape : shapes)
	{
		w_r_shape.get().draw();
	}
	

	return 0;
}*/