//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//AbstractFactory: //Provide an interface for creating families of related or dependent objects without
//specifying their concrete classes.
#include "StdAfx.h"
#include "Factories.h"
namespace abstractfactory
{

	void Client::Test()
	{
	
		// Abstract factory #1
	
		AbstractFactory *factory1 = new ConcreteFactory1();
	
		Client *client1 = new Client(factory1);
	
		client1->Run();
	
	
	
		// Abstract factory #2
	
		AbstractFactory *factory2 = new ConcreteFactory2();
	
		Client *client2 = new Client(factory2);
	
		client2->Run();
	
	
	
		// Wait for user input
	
		// Console.ReadKey();
	
	}

	Client::Client(AbstractFactory *factory)
	{
	
		_AbstractProductB = factory->CreateProductB();
	
		_AbstractProductA = factory->CreateProductA();
	
	}

	void Client::Run()
	{
	
		_AbstractProductB->Interact(_AbstractProductA);
	
	}

	AbstractProductA *ConcreteFactory1::CreateProductA()
	
	{
	
	  return new ProductA1();
	
	}

	AbstractProductB *ConcreteFactory1::CreateProductB()
	
	{
	
	  return new ProductB1();
	
	}

	AbstractProductA *ConcreteFactory2::CreateProductA()
	
	{
	
	  return new ProductA2();
	
	}

	AbstractProductB *ConcreteFactory2::CreateProductB()
	
	{
	
	  return new ProductB2();
	
	}
}