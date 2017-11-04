//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//State: //Allow an object to alter its behavior when its internal state changes.The object
//will appear to change its class.
#pragma once
#include <string>
#include <iostream>


namespace state
{

	class Context;
	// IState 
	struct IState
	{
		virtual void Handle(Context*) = 0;
		virtual std::string getThisStateName() = 0;

	};


	// Context 
	class Context
	{

	public:
		// Constructor 
		Context(IState *state);
		static void Test();
		// Property 
private:
		IState *m_pCurrentState;
	public:
		IState *getCurrentState();
		void setCurrentState(IState *value);
		//Methods
		void Request();
	};


	// ConcreteStateA 
	class ConcreteStateA : public IState
	{
		std::string getThisStateName();
	public:
		void Handle(Context *pContext);

		
	};

	// ConcreteStateB 
	class ConcreteStateB : public IState
	{
		std::string getThisStateName();
	public:
		void Handle(Context *pContext);
		
	};

	// ConcreteStateC 
	class ConcreteStateC : public IState
	{
		std::string getThisStateName();
	public:
		void Handle(Context *pContext);
		
	};

}