//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Define a family of algorithms, encapsulate each one, and make them interchangeable.
//Strategy lets the algorithm vary independently from clients that use it.
#pragma once

namespace strategy
{

	/// <summary>
	/// 'IContext' inteface
	/// </summary>
	class IContext
	{
		virtual void ContextInterface() = 0;
	};

	/// <summary>
	/// The 'Strategy' abstract class
	/// </summary>
	class Strategy
	{
	public:
		virtual void AlgorithmInterface(IContext*) = 0;
	};

	/// <summary>
	/// A 'ConcreteStrategy' class
	/// </summary>
	class ConcreteStrategyA : public Strategy
	{
	public:
		virtual void AlgorithmInterface(IContext *context);
	};

	/// <summary>
	/// A 'ConcreteStrategy' class
	/// </summary>
	class ConcreteStrategyB : public Strategy
	{
	public:
		virtual void AlgorithmInterface(IContext *context);
	};

	/// <summary>
	/// A 'ConcreteStrategy' class
	/// </summary>
	class ConcreteStrategyC : public Strategy
	{
	public:
		virtual void AlgorithmInterface(IContext *context);
	};


	/// <summary>
	/// The 'Context' class
	/// </summary>
	class Context : public IContext
	{

	public:
		static void Test();
	private:
		Strategy *_strategy;

		// Constructor
	public:
		Context(Strategy *strategy);

		void ContextInterface();
	};
}
