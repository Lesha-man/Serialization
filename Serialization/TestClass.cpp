#include "TestClass.h"

TestClass::TestClass()
	: Transf(new Transform())
{
}

TestClass::TestClass(int)
	: X(0)
	, ObjectName("Heloo my litle pony")
	, Transf(new Transform(1))
	, Trans(1)
{
	NamedPoints["one"] = 1;
	NamedPoints["two"] = 2;
	NamedPoints["three"] = 3;
	NamedPoints["PI"] = 3.1415;
}