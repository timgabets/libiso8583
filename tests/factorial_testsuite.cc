#include "snow.h"
#include "factorial.hh"

describe(dummy_test, {
	it("factorial()", {
		asserteq_int( factorial(1), 1 );
		asserteq_int( factorial(2), 2 );
		asserteq_int( factorial(3), 6 );
		asserteq_int( factorial(10), 3628800 );
	});
});
