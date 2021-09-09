#ifndef SERIAL_H
#define SERIAL_H

#include <forward_list>
#include "XML_Serialize.h"

template<class C>
class ISerializableField
{
public :
    virtual void Serialize(C& cont) = 0;
    virtual void Deserialize(C& cont) = 0;
};

template<class T, class C>
class SerializableField : public ISerializableField<C> {

public:
    SerializableField(const char* name, T& value)
        : value(value)
        , name(name)
    {
    }

    void Serialize(C& cont) override
    {
        ser::Serialize(name, value, cont, (T*)0);
    }
    void Deserialize(C& cont) override
    {
        ser::Deserialize(name, value, cont, (T*)0);
    }
private:
    const char* name;
    T& value;
};

template<class T, class C>
class SerializableField<T*, C> : public ISerializableField<C> {

public:
    SerializableField(const char* name, T*& value)
        : value(value)
        , name(name)
    {
    }

    void Serialize(C& cont) override
    {
        ser::Serialize(name, *value, cont, (T*)0);
    }
    void Deserialize(C& cont) override
    {
        ser::Deserialize(name, *value, cont, (T*)0);
    }
private:
    const char* name;
    T*& value;
};

template<class C>
class Serializable
{

public:
    virtual void Serialize(C& _cont)
    {
        for (auto& fild : filds)
            fild->Serialize(_cont);
    }

    virtual void Deserialize(C& _cont)
    {
        for (auto& fild : filds)
            fild->Deserialize(_cont);
    }

    virtual ~Serializable(){
        for (auto& fild : filds)
            delete fild;
    }
protected:
    template<typename T>
    char Add(const char* _key, T& field)
    {
        filds.push_front(new SerializableField<T, C>(_key, field));
        return 0;
    }



private:

    std::forward_list<ISerializableField<C>*> filds;
};

#define SINGLE_ARG(...) __VA_ARGS__
#define CAP_IMPL(x, y) CAP_##x##_##y
#define CAP_DECL(x, y) CAP_IMPL(x, y)
#define CAP CAP_DECL(__LINE__ , __COUNTER__)

#define serialize(t, var) char CAP = Add(#var, var); \
t var

#endif //SERIAL_H
