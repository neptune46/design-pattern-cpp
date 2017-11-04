//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Interpreter: //Given a language, define a represention for its grammar along with an interpreter
//that uses the representation to interpret sentences in the language.
#include "stdafx.h"
#include "interpreter.h"
namespace interpreter
{

	void InterpreterClient::Test()
	{
		Context *context = new Context();
	
		// Can be a sequence or a tree 
		AbstractExpression* list[4] = {new TerminalExpression(),new NonterminalExpression(),new TerminalExpression(),new TerminalExpression() };
	
		// Interpret 
		for (int i = 0; i < 4; i++)
		{
			list[i]->Interpret(context);
		}
	
	}

	NonterminalExpression *AbstractExpression::getNext()
	{
		return privateNext;
	}

	void AbstractExpression::setNext(NonterminalExpression *value)
	{
		privateNext = value;
	}

	void TerminalExpression::Interpret(Context *context)
	{
		std::cout << "Calling TerminalExpression.Interpret()" << std::endl;
	}

	void NonterminalExpression::Interpret(Context *context)
	{
		std::cout << "Calling NonterminalExpression.Interpret()" << std::endl;
	}
}