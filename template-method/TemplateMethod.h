//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//TemplateMethod: //Define the skeleton of an algorithm in an operation, deferring some steps to subclasses.
//Template Method lets subclasses redefine certain steps of an algorithm without changing
//the algorithm's structure.
#pragma once

namespace templatemethod
{
	class AbstractClass
	{
	protected:
		virtual void PrimitiveOperation1() = 0;
		virtual void PrimitiveOperation2() = 0;
	public:
		void TemplateMethod();

		static void Test();
	};

	class ConcreteClass : public AbstractClass
	{

	protected:
		virtual void PrimitiveOperation1();

		virtual void PrimitiveOperation2();
	};
}
