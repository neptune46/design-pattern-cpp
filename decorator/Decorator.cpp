//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Attach additional responsibilities to an object dynamically. Decorators provide
//a flexible alternative to subclassing for extending functionality.
#include "stdafx.h"
#include "decorator.h"
namespace decorator
{

	void ConcreteComponent::Operation()
	{
		std::cout << "ConcreteComponent.Operation()" << std::endl;
	}

	void Decorator::Test()
	{
		// Create a ConcreteComponent and Decorators
		ConcreteComponent *c = new ConcreteComponent();
		ConcreteDecoratorA *da = new ConcreteDecoratorA();
		ConcreteDecoratorB *db = new ConcreteDecoratorB();
	
		//set decorators
		da->setcomponent(c);
		db->setcomponent(c);
		std::cout << "use ConcreteDecoratorA...." << std::endl;
		da->Operation();
		std::cout << "use ConcreteDecoratorB..." << std::endl;
		db->Operation();
		std::cout << "Chained decorators..." << std::endl;
		db->setcomponent(da);
		db->Operation();
	}

	Component *Decorator::getcomponent()
	{
		return _component;
	}

	void Decorator::setcomponent(Component *value)
	{
		_component = value;
	}

	void Decorator::Operation()
	{
		if (getcomponent() != NULL)
		{
			getcomponent()->Operation();
		}
	}

	void ConcreteDecoratorA::Operation()
	{
		__super::Operation();
		std::cout << "ConcreteDecoratorA.Operation()" << std::endl;
	}

	void ConcreteDecoratorB::Operation()
	{
		__super::Operation();
		AddedBehavior();
		std::cout << "ConcreteDecoratorB.Operation()" << std::endl;
	}

	void ConcreteDecoratorB::AddedBehavior()
	{
		std::cout << "ConcreteDecoratorA.AddedBehavior()" << std::endl;
	}
}