#ifndef BINARY_H
#define BINARY_H
#include <string>
#include <map>


template<class C>
class Serializable;


namespace ser
{
    template<class T>
    inline void Serialize(const char* _key, T& _val, char*& _node, ...)
    {
        memcpy(_node, &_val, sizeof(_val));
        _node += sizeof(_val);
    }


    inline void Serialize(const char* _key, std::string& _val, char*& _node, ...)
    {
        unsigned int size = _val.size();
        (char*)memcpy(_node, &size, sizeof(size));
        _node += sizeof(size);
        (char*)memcpy(_node, _val.c_str(), size);
        _node += size;
    }

    template<class T>
    inline void Serialize(const char* _key, T& _val, char*& _node, Serializable<char*>*)
    {
        _val.Serialize(_node);
    }

    template<class T>
    inline void Deserialize(const char* _key, T& _val, char*& _node, ...)
    {
        memcpy(&_val, _node, sizeof(_val));
        _node += sizeof(_val);
    }

    template<class T>
    inline void Deserialize(const char* _key, T& _val, char*& _node, Serializable<char*>*)
    {
        _val.Deserialize(_node);
    }

    inline void Deserialize(const char* _key, std::string& _val, char*& _node, ...)
    {
        unsigned int size;
        memcpy(&size, _node, sizeof(size));
        _node += sizeof(size);
        _val = std::string(_node, size);
        _node += size;
    }

}

#endif //BINARY_H
