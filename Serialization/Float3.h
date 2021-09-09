#pragma once
#include "Serialize.h"

struct Float3 : public Serializable<pugi::xml_node>
{
	serialize(float, X) = 0;
	serialize(float, Y) = 0;
	serialize(float, Z) = 0;
};
