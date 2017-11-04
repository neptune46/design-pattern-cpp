//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Memento: //Without violating encapsulation, capture and externalize an object'sinternal state
//so that the object can be restored to this state later.
#include "stdafx.h"
#include "memento.h"
using namespace std;
namespace memento
{

	void Caretaker::Test()
	{
		Originator<string> *o = new Originator<string>();
		o->setState("Original");
	
		// Store internal state
		Caretaker *c = new Caretaker();
		c->setMemento(o->CreateMemento());
	
		// Continue changing Originator
		o->setState("Changed");
	
		// Restore saved state
		o->SetMemento(c->getMemento());
	
	}
	template <class State>
	Originator<State>::Memento::Memento(State state)
	{
		_state = state;
	}
	
	template <class State>
	State Originator<State>::Memento::getState()
	{
		return _state;
	}
	
	template <class State>
	State Originator<State>::getState()
	{
		return _state;
	}

	template <class State>
	void Originator<State>::setState(State value)
	{
		_state = value;
		std::cout << "State = " << _state << std::endl;
	}

	template <>
	Originator<string>::Memento *Originator<string>::CreateMemento()
	{
		return (new Memento(_state));
	}
	
	template <class State>
	void Originator<State>::SetMemento(Memento *memento)
	{
		std::cout << "Restoring state..." << std::endl;
		setState(memento->getState());
	}
	
	void Caretaker::setMemento(Originator<string>::Memento *value)
	{
		_memento = value;
	}

	Originator<string>::Memento *Caretaker::getMemento()
	{
		return _memento;
	}
}