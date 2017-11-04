//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Interpreter: //Given a language, define a represention for its grammar along with an interpreter
//that uses the representation to interpret sentences in the language.
#pragma once
#include <iostream>
namespace interpreter
{

	/// <summary>
	/// InterpreterClient
	/// </summary>
	class InterpreterClient
	{

	public:
		static void Test();
	};

	/// <summary>
	///  Context
	/// </summary>
	class Context
	{
	};

	class NonterminalExpression;

	// AbstractExpression
	class AbstractExpression
	{
	public:
		virtual void Interpret(Context*) = 0;
private:
		NonterminalExpression *privateNext;
	protected:
		NonterminalExpression *getNext();
		void setNext(NonterminalExpression *value);
	};

	/// <summary>
	/// TerminalExpression
	/// </summary>
	class TerminalExpression : public AbstractExpression
	{
	public:
		virtual void Interpret(Context *context);
	};

	/// <summary>
	/// "NonterminalExpression" 
	/// </summary>
	class NonterminalExpression : public AbstractExpression
	{
	public:
		virtual void Interpret(Context *context);
	};
}
