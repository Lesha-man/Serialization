#pragma once
#include "pugi_xml/pugixml.hpp"
#include <string>
#include <map>

template<class C>
class Serializable;

namespace ser
{
	template<class T>
	inline void Serialize(const std::string& _key, T& _val, pugi::xml_node& _node, ...)
	{
		//int a = 0;
		_node.append_attribute(_key.c_str()) = _val;
	}

	template<class T>
	inline void Serialize(const std::string& _key, T& _val, pugi::xml_node& _node, Serializable<pugi::xml_node>*)
	{
		_val.Serialize(_node.append_child(_key.c_str()));
	}

	template<class T>
	inline void Serialize(const std::string& _key, std::map<std::string, T>& _val, pugi::xml_node& _node, ...)
	{
		auto lv_Node = _node.append_child(_key.c_str());
		for (auto lv_Val : _val)
		{
			Serialize(lv_Val.first, lv_Val.second, lv_Node);
		}
	}

	inline void Serialize(const std::string& _key, std::string& _val, pugi::xml_node& _node, ...)
	{
		_node.append_attribute(_key.c_str()) = _val.c_str();
	}


	template<class T>
	inline void Deserialize(const std::string& _key, T& _val, const pugi::xml_node& _node, ...)
	{
		//static_assert(false, "No Deserialize");
	}

	template<class T>
	inline void Deserialize(const std::string& _key, T& _val, const pugi::xml_node& _node, Serializable<pugi::xml_node>*)
	{
		_val.Deserialize(_node.child(_key.c_str()));
	}

	template<class T>
	inline void Deserialize(const std::string& _key, std::map<std::string, T>& _val, pugi::xml_node& _node, ...)
	{
		auto lv_Node = _node.child(_key.c_str());
		for (auto lv_Val : lv_Node)
		{
			Deserialize(lv_Val.name(), _val[lv_Val.name()], lv_Node);
		}
	}

	inline void Deserialize(const std::string& _key, float& _val, const pugi::xml_node& _node, ...)
	{
		_val = _node.attribute(_key.c_str()).as_float();
	}

	inline void Deserialize(const std::string& _key, std::string& _val, const pugi::xml_node& _node, ...)
	{
		_val = _node.attribute(_key.c_str()).as_string();
	}
}