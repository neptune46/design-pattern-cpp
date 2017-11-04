//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Provide a unified interface to a set of interfaces in a subsystem. Facade defines
//a higher-level interface that makes the subsystem easier to use.
#include "stdafx.h"
#include "facade.h"


namespace facade
{

	SubsystemA* Facade::a = new SubsystemA();
	SubsystemB* Facade::b = new SubsystemB();
	void FacadeClient::Test()
	{
	
		Facade::Operation1();
		Facade::Operation2();
	
	}

	std::string SubsystemA::A1()
	{
		return "SubsystemA, Method A1\n";
	}

	std::string SubsystemA::A2()
	{
		return "SubsystemA, Method A2\n";
	}

	std::string SubsystemB::B1()
	{
		return "SubsystemB, Method B1\n";
	}

	std::string SubsystemB::B2()
	{
		return "SubsystemB, Method B2\n";
	}

	void Facade::Operation1()
	{
		std::cout << "Operation 1\n" << a->A1() << b->B1() << std::endl;
	}

	void Facade::Operation2()
	{
		std::cout << "Operation 2\n" << b->B2() << a->A2() << std::endl;
	}
}