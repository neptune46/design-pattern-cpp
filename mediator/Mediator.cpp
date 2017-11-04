//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Define an object that encapsulates how a set of objects interact.Mediator promotes
//loose coupling by keeping objects from referring toeach other explicitly, and it
//lets you vary their interaction independently.
#include "stdafx.h"
#include "mediator.h"
namespace mediator
{

	void Mediator::Test()
	{
		ConcreteMediator *m = new ConcreteMediator();
	
		ConcreteColleague1 *c1 = new ConcreteColleague1(m);
		ConcreteColleague2 *c2 = new ConcreteColleague2(m);
	
		m->setColleague1(c1);
		m->setColleague2(c2);
	
		c1->Send("Colleague1 message");
		c2->Send("Colleague2 message");
	
	
	}

	void ConcreteMediator::setColleague1(ConcreteColleague1 *value)
	{
		_colleague1 = value;
	}

	void ConcreteMediator::setColleague2(ConcreteColleague2 *value)
	{
		_colleague2 = value;
	}

	void ConcreteMediator::SendMsg(std::string message, Colleague *colleague)
	{
		if (colleague == _colleague1)
		{
			_colleague2->Notification(message);
		}
		else
		{
			_colleague1->Notification(message);
		}
	}

	Colleague::Colleague(Mediator *mediator)
	{
		this->_mediator = mediator;
	}

	ConcreteColleague1::ConcreteColleague1(Mediator *mediator) : Colleague(mediator)
	{
	}

	void ConcreteColleague1::Send(std::string message)
	{
		_mediator->SendMsg(message, this);
	}

	void ConcreteColleague1::Notification(std::string message)
	{
		std::cout << "Colleague1 gets message: " + message << std::endl;
	}

	ConcreteColleague2::ConcreteColleague2(Mediator *mediator) : Colleague(mediator)
	{
	}

	void ConcreteColleague2::Send(std::string message)
	{
		_mediator->SendMsg(message, this);
	}

	void ConcreteColleague2::Notification(std::string message)
	{
		std::cout << "Colleague2 gets message: " + message << std::endl;
	}
}