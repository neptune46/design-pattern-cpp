//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Prototype: //Specify the kinds of objects to create using a prototypical instance, and create
//new objects by copying this prototype.
#include "stdafx.h"
#include "prototype.h"
namespace prototype
{

	void PrototypeClient::Test()
	{
		// Create some instances and clone each 
		Prototype *prototype = new ConcretePrototypeA("A");
		ConcretePrototypeA *c1 = static_cast<ConcretePrototypeA*>(prototype->Clone());
		std::cout << "Cloned: " << c1->getId() << std::endl;
	
		prototype = new ConcretePrototypeB("B");
		ConcretePrototypeB *c2 = static_cast<ConcretePrototypeB*>(prototype->Clone());
		std::cout << "Cloned: " << c2->getId() << std::endl;
	}

	Prototype::Prototype(std::string id)
	{
		setId(id);
	}

	std::string Prototype::getId()
	{
		return privateId;
	}

	void Prototype::setId(std::string value)
	{
		privateId = value;
	}

	ConcretePrototypeA::ConcretePrototypeA(std::string id) : Prototype(id)
	{
	}

	Prototype *ConcretePrototypeA::Clone()
	{
		// Shallow copy 
		return new ConcretePrototypeA(getId());
	}

	ConcretePrototypeB::ConcretePrototypeB(std::string id) : Prototype(id)
	{
	}

	Prototype *ConcretePrototypeB::Clone()
	{
		// Shallow copy 
		return new ConcretePrototypeB(getId());
	}
}