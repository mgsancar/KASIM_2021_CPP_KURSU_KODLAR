#include <iostream>

// Constructor ve Destructor'ların cagrilma sirasi ile ilgili ornek
// Uyelerin elemanların ctor'lari bulundukları class'in ctor'undan once cagrilir.
// Base ctor -> Member ctor -> Der ctor -> Der dtor -> Member dtor -> Base dtor
// First in last out
class Base {
public:
	Base()
	{
		std::cout << "Base ctor\n";
	}

	~Base()
	{
		std::cout << "Base dtor\n";
	}

};

class Member {
public:
	Member()
	{
		std::cout << "Member ctor\n";
	}

	~Member()
	{
		std::cout << "Member dtor\n";
	}

};

class Der :public Base {
public:
	Der()
	{
		std::cout << "Der ctor\n";
	}

	~Der()
	{
		std::cout << "Der dtor\n";
	}
private:
	Member x;
};

int main()
{
	Der myder;
}