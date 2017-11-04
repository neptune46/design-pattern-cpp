//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//TemplateMethod: //Define the skeleton of an algorithm in an operation, deferring some steps to subclasses.
//Template Method lets subclasses redefine certain steps of an algorithm without changing
//the algorithm's structure.
#include "stdafx.h"
#include <iostream>
#include "templatemethod.h"
namespace templatemethod
{

	void AbstractClass::TemplateMethod()
	{
		PrimitiveOperation1();
		PrimitiveOperation2();
	}

	void AbstractClass::Test()
	{
		ConcreteClass *algorithm = new ConcreteClass();
		algorithm->TemplateMethod();
	}

	void ConcreteClass::PrimitiveOperation1()
	{
		std::cout << "PrimitiveOperation1 in ConcreteClass" << std::endl;
	}

	void ConcreteClass::PrimitiveOperation2()
	{
		std::cout << "PrimitiveOperation2 in ConcreteClass" << std::endl;
	}
}