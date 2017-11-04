//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Represent an operation to be performed on the elements of an ObjectStructure. Visitor
//lets you define a new operation without changing the classes of the elements on
//which it operates.
#include "stdafx.h"
#include "visitor.h"
#include <iostream>
#include <algorithm>

namespace visitor
{

	void ConcreteVisitor1::VisitConcreteElementA(ConcreteElementA *concreteElementA)
	{
		std::cout << "ConcreteElementA visited by ConcreteVisitor1" << std::endl;
	}

	void ConcreteVisitor1::VisitConcreteElementB(ConcreteElementB *concreteElementB)
	{
		std::cout << "ConcreteElementB visited by ConcreteVisitor1" << std::endl;
	}

	void ConcreteVisitor2::VisitConcreteElementA(ConcreteElementA *concreteElementA)
	{
		std::cout << "ConcreteElementA visited by ConcreteVisitor2" << std::endl;
	}

	void ConcreteVisitor2::VisitConcreteElementB(ConcreteElementB *concreteElementB)
	{
		std::cout << "ConcreteElementB visited by ConcreteVisitor2" << std::endl;
	}

	void ConcreteElementA::Accept(Visitor *visitor)
	{
		visitor->VisitConcreteElementA(this);
	}

	void ConcreteElementA::OperationA()
	{
	}

	void ConcreteElementB::Accept(Visitor *visitor)
	{
		visitor->VisitConcreteElementB(this);
	}

	void ConcreteElementB::OperationB()
	{
	}

	void ObjectStructure::Attach(Element *element)
	{
		this->push_back(element);
	}

	void ObjectStructure::Detach(Element *element)
	{
		//this->Remove(element);
		this->erase(std::remove(this->begin(), this->end(), element),this->end());
	}

	void ObjectStructure::AcceptVisior(Visitor *visitor)
	{
		for (std::vector<Element*>::const_iterator o = this->begin(); o != this->end(); o++)
		{
			(*o)->Accept(visitor);
		}
	}

	void ObjectStructure::Test()
	{
		// Setup collection
		ObjectStructure *coll = new ObjectStructure();
		coll->Attach(new ConcreteElementA());
		coll->Attach(new ConcreteElementB());
	
		// Collection accepting visitors
		coll->AcceptVisior(new ConcreteVisitor1());
		coll->AcceptVisior(new ConcreteVisitor2());
	}
}