//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//FactoryMethod: //Define an interface for creating an object, but let subclasses decide which class
//to instantiate. Factory Method lets a class defer instantiation to subclasses.
#include "stdafx.h"
#include "FactoryMethod.h"
#include <string>


namespace factorymethod
{

	std::string DefaultProduct::GetProductName()
	{
		return "default";
	}

	IProduct *ConcreteDefaultCreator::FactoryMethod()
	{
		return new DefaultProduct();
	
	}

	void Creator::AnOperation()
	{
		IProduct *product = FactoryMethod();
		std::cout << "In Creator.AnOperation(): created " + product->GetProductName() << std::endl;
	
	}

	void Creator::Test()
	{

	Creator* creators[3];


		creators[0] = new ConcreteCreator1();
		creators[1] = new ConcreteCreator2();
		creators[2] = new ConcreteDefaultCreator();
		for (int i =0; i < 3; i++)
		{
			creators[i]->AnOperation();
			IProduct *product = creators[i]->FactoryMethod();
			std::cout << "In Creator.Main() Name= " + product->GetProductName() << std::endl;
			 delete creators[i];
		}
	
	}

	std::string Product1::GetProductName()
	{
		return "Product1";
	}

	IProduct *ConcreteCreator1::FactoryMethod()
	{
		return new Product1();
	
	}

	std::string Product2::GetProductName()
	{
		return "Product2";
	}

	IProduct *ConcreteCreator2::FactoryMethod()
	{
		   return new Product2();
	
	}
}