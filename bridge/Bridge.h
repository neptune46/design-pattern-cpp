//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Bridge: //Decouple an abstraction from its implementation so that the two can vary independently.
#pragma once
#include <iostream>


namespace bridge
{


	/// <summary>
	/// The 'Implementor' abstract class
	/// </summary>
	class Implementor
	{
	public:
		virtual void OperationImp() = 0;
	};


	/// <summary>
	/// The 'Abstraction' class
	/// </summary>
	class Abstraction
	{
		// Property
private:
	Implementor *_implementor;
	public:
		Implementor *getImplementor();
		void setImplementor(Implementor *value);

		virtual void Operation();
		/// <summary>
		/// Just for testing.
		/// </summary>
		static void Test();
	};




	/// <summary>
	/// The 'RefinedAbstraction' class
	/// </summary>
	class RefinedAbstraction : public Abstraction
	{
	public:
		virtual void Operation();
	};



	/// <summary>
	/// The 'ConcreteImplementorA' class
	/// </summary>
	class ConcreteImplementorA : public Implementor
	{
	public:
		virtual void OperationImp();

	};



	/// <summary>
	/// The 'ConcreteImplementorB' class
	/// </summary>
	class ConcreteImplementorB : public Implementor
	{
	public:
		virtual void OperationImp();

	};


}

