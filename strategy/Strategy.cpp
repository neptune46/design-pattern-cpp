//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Define a family of algorithms, encapsulate each one, and make them interchangeable.
//Strategy lets the algorithm vary independently from clients that use it.
#include "stdafx.h"
#include "strategy.h"
#include <iostream>
namespace strategy
{

	void ConcreteStrategyA::AlgorithmInterface(IContext *context)
	{
		std::cout << "Called ConcreteStrategyA.AlgorithmInterface()" << std::endl;
	
	}

	void ConcreteStrategyB::AlgorithmInterface(IContext *context)
	{
		std::cout << "Called ConcreteStrategyB.AlgorithmInterface()" << std::endl;
	
	}

	void ConcreteStrategyC::AlgorithmInterface(IContext *context)
	{
		std::cout << "Called ConcreteStrategyC.AlgorithmInterface()" << std::endl;
	
	}

	void Context::Test()
	{
		Context *context;
	
		// Three contexts following different strategies
		context = new Context(new ConcreteStrategyA());
		context->ContextInterface();
	
		context = new Context(new ConcreteStrategyB());
		context->ContextInterface();
	
		context = new Context(new ConcreteStrategyC());
		context->ContextInterface();
	}

	Context::Context(Strategy *strategy)
	{
		this->_strategy = strategy;
	}

	void Context::ContextInterface()
	{
		_strategy->AlgorithmInterface(this);
	}
}