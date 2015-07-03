#include <iostream>
#include <vector>

using namespace std;

class Common
{

};

class Supra
{
private:
	vector<Common *> commons;

public:
	template <typename T>
	void Instantiate();
	void AddCommon(Common *common);
};

template <typename T>
void Supra::Instantiate()
{
	T *t = new T;
	commons.push_back(t);
	//T::Instantiate(*this);
}

void Supra::AddCommon(Common *common)
{
	commons.push_back(common);
}

template <typename TChild>
class Parent : public Common
{
public:
	static void Instantiate(Supra &supra);
};

template <typename TChild>
void Parent<TChild>::Instantiate(Supra &supra)
{
	TChild *child = new TChild();
	supra.AddCommon(child);
}

class Child : public Parent<Child>
{
public:
	Child();
};

Child::Child()
{
	cout << "Child created" << endl;
}

class Adder
{
private:
	int i;

public:
	Adder(int i);

	template <typename T>
	T Add(T i);
};

Adder::Adder(int pari) : i(pari) {}

template <typename T>
T Adder::Add(T i)
{
	return i + this->i;
}

class Component
{
protected:
	string name;

public:
	Component(string pname) : name(pname) {}
	
	void Echo()
	{
		cout << name << endl;
	}

	virtual void OnUpdate() {};
};

class InterComponent : public Component
{
public:
	InterComponent(string name) : Component(name) {}

	void InterStuff()
	{
		cout << "Inter stuff on " << name << endl;
	}
};

class Componenter
{
private:
	vector<Component *> components;

public:
	void AddComponent(Component *component);

	template <typename Derived>
	Derived *GetComponent();
};

void Componenter::AddComponent(Component *component)
{
	components.push_back(component);
}

template <typename Derived>
Derived *Componenter::GetComponent()
{
	for (unsigned int i = 0; i < components.size(); i++) {
		Derived *cast = dynamic_cast<Derived *>(components[i]);

		if (cast != 0)
			return cast;
	}

	return NULL;
}

class ComponentA : public Component
{
public:
	ComponentA() : Component("ComponentA") {}
};

class ComponentB : public InterComponent
{
public:
	ComponentB() : InterComponent("ComponentB") {}
};

class ComponentC : public Component
{
public:
	ComponentC() : Component("ComponentC") {}
};



struct coord
{
	int x, y;
};



class IntegerProperty
{
private:
	int *integer;

public:
	IntegerProperty(int *pinteger) : integer(pinteger) {}

	operator int()
	{
		return *integer;
	}
	
	IntegerProperty	&operator+=(int other)
	{
		*integer += other;
		return *this;
	}

	IntegerProperty &operator-=(int other)
	{
		*integer -= other;
		return *this;
	}

	IntegerProperty &operator*=(int other)
	{
		*integer *= other;
		return *this;
	}

	IntegerProperty &operator/=(int other)
	{
		*integer /= other;
		return *this;
	}

	IntegerProperty &operator%=(int other)
	{
		*integer %= other;
		return *this;
	}

	IntegerProperty &operator=(int other)
	{
		*integer = other;
		return *this;
	}
};


class Wrapper
{
private:
	coord wii;

public:
	IntegerProperty x;
	IntegerProperty y;
	
	Wrapper() : x(&wii.x), y(&wii.y) {
		wii.x = wii.y = 0;
	}

	void Echo()
	{
		cout << "(" << wii.x << ", " << wii.y << ")" << endl;
	}
};






int main(int argc, char const *argv[])
{
	vector<int> anal;
	anal.clear();

	return 0;
}

/*
FUCKING NOOB USE POINTERS FOR POLYMORPHISM
*/