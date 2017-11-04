//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//AbstractFactory: //Provide an interface for creating families of related or dependent objects without
//specifying their concrete classes.
#include "StdAfx.h"
#include "Products.h"
namespace abstractfactory
{

	std::string ProductA1::GetName()
	{
		return "ProductA1";	
	}
	std::string ProductA2::GetName()
	{
		return "ProductA2";	
	}
	void ProductB1::Interact(AbstractProductA *a)
	{
		std::cout << "ProductB1 interacts with " << a->GetName().c_str() << std::endl;
	}

	void ProductB2::Interact(AbstractProductA *a)
	{
		std::cout << "ProductB1 interacts with " << a->GetName().c_str() << std::endl;
	}
}