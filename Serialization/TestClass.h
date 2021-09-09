#pragma once
#include "Transform.h"
#include <map>

class TestClass
	: public Serializable<pugi::xml_node>
{

public:

	TestClass();
	TestClass(int);

private:
	int someInt = 0;

	serialize(float, X);
	serialize(std::string, ObjectName);
	serialize(Transform*, Transf);
	serialize(Transform, Trans);
	serialize(SINGLE_ARG(std::map<std::string, float>), NamedPoints);
};
