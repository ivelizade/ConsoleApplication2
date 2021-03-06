#include "stdafx.h"
#include <iostream>
#include<string>
class Sofa;
class Table;
class armChair;
class FurnitureFactory
{
	virtual Sofa*createSofa() = 0;
	virtual Table*createTable() = 0;
	virtual armChair*createArmChair() = 0;
};
class Sofa
{

public:
	std::string Model;
	std::string getModel() { return Model; }
	Sofa(std::string model)
	{
		Model = model;
	}
	Sofa() {}
};
class armChair
{
public:
	std::string Model;
	std::string getModel() { return Model; }
	armChair(std::string model)
	{
		Model = model;
	}
	armChair() {}
};
class Table
{
public:
	std::string Model;
	std::string getModel() { return Model; }
	Table(std::string model)
	{
		Model = model;
	}
	Table() {}
};
class ArDeco :FurnitureFactory
{

public:
	ArDeco()
	{
		
	}
	armChair*createArmChair()override
	{
		armChair ArmChair("ArDeco Armchair");
		return &ArmChair;
	}
	Sofa*createSofa()override
	{
		Sofa sofa("ArDeco Sofa");
		return &sofa;
	}
	Table*createTable()override
	{
		Table table("ArDeco Table");
		return &table;
	}
};
class Modern :FurnitureFactory
{
public:
	armChair * createArmChair()override
	{
		armChair ArmChair("Modern Armchair");
		return &ArmChair;
	}
	Sofa*createSofa()override
	{
		Sofa sofa("Modern Sofa");
		return &sofa;
	}
	Table*createTable()override
	{
		Table table("Modern Table");
		return &table;
	}
};
class Victorian:FurnitureFactory
{
public:
	armChair*createArmChair()override
	{
		armChair ArmChair("Victorian Armchair");
		return &ArmChair;
	}
	Sofa*createSofa()override
	{
		Sofa sofa("Victorian Sofa");
		return &sofa;
	}
	Table*createTable()override
	{
		Table table("Victorian Table");
		return &table;
	}
};
int main()
{
	std::string complect;
	std::cin >> complect;
	if (complect=="virtorian")
	{
		Victorian v;
		auto arm = v.createArmChair();
		auto sofa = v.createSofa();
		auto table = v.createTable();
		std::cout << "Components : ";
		std::cout << arm->getModel()<<'\n';
		std::cout << table->getModel()<<'\n';
        std::cout << sofa->getModel()<<'\n';
	}
	else if (complect=="modern")
	{
		Modern v;
		auto arm = v.createArmChair();
		auto sofa = v.createSofa();
		auto table = v.createTable();
		std::cout << "Components : ";
		std::cout << arm->getModel() << '\n';
		std::cout << sofa->getModel() << '\n';
		std::cout << table->getModel() << '\n';
	}
	system("pause");
}
