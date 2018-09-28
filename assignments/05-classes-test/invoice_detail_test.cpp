#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "invoice_detail.h"

TEST_CASE("Test get extended cost")
{
	InvoiceDetail inv(10, 10);
	REQUIRE(inv.get_extended_cost() == 100);
}