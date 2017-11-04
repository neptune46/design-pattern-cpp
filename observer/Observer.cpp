//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Observer: //Define a one to many dependency between objects so that when one object changes
//state, all its dependents are notified and updatedautomatically.
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include "observer.h"
#include <algorithm>

namespace observer
{

	void Subject::Test()
	{
		// Configure Observer pattern
		ConcreteSubject *s = new ConcreteSubject();
		s->Attach(new ConcreteObserver(s, "A"));
		s->Attach(new ConcreteObserver(s, "B"));
		// Change subject and notify observers
		s->setSubjectState("NEW");
		s->Notify();
	}

	void Subject::Attach(Observer *observer)
	{
		this->push_back(observer);
	}

	void Subject::Detach(Observer *observer)
	{
		//std::vector<Observer *>::iterator newEnd = std::find(begin(), end(), observer);
		this->erase(std::remove(this->begin(), this->end(), observer),this->end());

	}

	void Subject::Notify()
	{
		for (std::vector<Observer *>::const_iterator o = this->begin(); o != this->end(); o++)
		{
			(*o)->Update();
		}
	}

	string ConcreteSubject::getSubjectState()
	{
		return _subjectState;
	}

	void ConcreteSubject::setSubjectState(string value)
	{
		_subjectState = value;
	}

	ConcreteObserver::ConcreteObserver(ConcreteSubject *subject, std::string name)
	{
		this->_subject = subject;
		this->_name = name;
	}

	void ConcreteObserver::Update()
	{
		_observerState = _subject->getSubjectState();
		std::cout << "Observer " << _name << " was notified that the new state is " << _observerState << std::endl;
	}
}