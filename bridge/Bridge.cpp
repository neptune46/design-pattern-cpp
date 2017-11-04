//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Bridge: //Decouple an abstraction from its implementation so that the two can vary independently.
#include "StdAfx.h"
#include "bridge.h"

using namespace bridge;

Implementor *Abstraction::getImplementor()
{
	return _implementor;
}

void Abstraction::setImplementor(Implementor *value)
{
	_implementor = value;
}

void Abstraction::Operation()
{
	getImplementor()->OperationImp();
}



void Abstraction::Test()
{
	Abstraction *abstraction = new RefinedAbstraction();

	// Set implementation and call
	abstraction->setImplementor(new ConcreteImplementorA());
	abstraction->Operation();

	// Change implemention and call
	abstraction->setImplementor(new ConcreteImplementorB());
	abstraction->Operation();
}

void RefinedAbstraction::Operation()
{
	getImplementor()->OperationImp();
}

void ConcreteImplementorA::OperationImp()
{
	std::cout << "OperationA" << std::endl;
}

void ConcreteImplementorB::OperationImp()
{
	std::cout << "OperationB" << std::endl;
}

