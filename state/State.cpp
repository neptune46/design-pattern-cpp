//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//State: //Allow an object to alter its behavior when its internal state changes.The object
//will appear to change its class.
#include "stdafx.h"
#include "state.h"


namespace state
{

	void Context::Test()
	{
		// Setup pContext in a state 
		Context *pContext = new Context(new ConcreteStateA());
	
		// Client requests, that changes state 
		pContext->Request();
		pContext->Request();
		pContext->Request();
	
	}

	Context::Context(IState *pIState)
	{
		m_pCurrentState = NULL;
		this->setCurrentState(pIState);
	}

	IState *Context::getCurrentState()
	{
		return m_pCurrentState;
	}

	void Context::setCurrentState(IState *value)
	{
		IState* pOldState = m_pCurrentState;
		m_pCurrentState = value;
		if(pOldState != NULL)
			delete pOldState;
	}

	void Context::Request()
	{
		std::cout << "Handling Request in " + m_pCurrentState->getThisStateName() << std::endl;
		m_pCurrentState->Handle(this);
	}

	void ConcreteStateA::Handle(Context *pContext)
	{
		pContext->setCurrentState(new ConcreteStateB());
	}

	std::string ConcreteStateA::getThisStateName()
	{
		return "ConcreteStateA";
	}

	void ConcreteStateB::Handle(Context *pContext)
	{
		pContext->setCurrentState(new ConcreteStateC());
	}

	std::string ConcreteStateB::getThisStateName()
	{
		return "ConcreteStateB" ;
	}

	void ConcreteStateC::Handle(Context *pContext)
	{
		pContext->setCurrentState(new ConcreteStateA());
	}

	std::string ConcreteStateC::getThisStateName()
	{
		return "ConcreteStateC" ;
	}
}