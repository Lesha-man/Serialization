#pragma once
#include "Float3.h"

class Transform 
	: public Serializable<pugi::xml_node>
{
public:
	Transform();
	Transform(int);
private:
	serialize(Float3, Position);
	serialize(Float3, Rotation);
	serialize(Float3, Scale);
};

//template<>
//inline void ser::Serialize<Transform>(const std::string& _key, Transform& _val, pugi::xml_node& _node, Serializable<pugi::xml_node>*)
//{
//	int a = 0;
//}