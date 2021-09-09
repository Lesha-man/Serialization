#include <iostream>
#include "pugi_xml/pugixml.hpp"
#include <fstream>
#include "TestClass.h"

void SerializeTest()
{
	{
		TestClass lv_Test(1);
		pugi::xml_document doc;
		auto lv_Node = doc.append_child("Serialization");
		lv_Test.Serialize(lv_Node);
		doc.save_file(L"Test.xml");
		doc.save(std::cout);
		//std::ofstream of("output", std::ofstream::binary);
		//char* binary = new char[99999999];
		//char* start = binary;
		//lv_Test.Serialize(binary);
		//unsigned int l = binary - start;
		//of.write(start, l);
		//of.close();
	}

	{
		pugi::xml_document doc;
		doc.load_file(L"Test.xml");
		auto lv_Node = doc.child("Serialization");
		//std::ifstream is ("output", std::ifstream::binary);
		//is.seekg(0, is.end);
		//int length = is.tellg();
		//is.seekg(0, is.beg);
		//char* binary = new char[length];
		//is.read(binary, length);
		//TestClass lv_Test;
		//lv_Test.Deserialize(binary);
		//is.close();
	}
}

void main()
{
	SerializeTest();

	std::cin.ignore();
}