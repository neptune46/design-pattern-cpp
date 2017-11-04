//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Represent an operation to be performed on the elements of an ObjectStructure. Visitor
//lets you define a new operation without changing the classes of the elements on
//which it operates.
#pragma once
#include <vector>

namespace visitor
{
	class ConcreteElementA;
	class ConcreteElementB;
	/// <summary>
	/// The 'Visitor' abstract class
	/// </summary>
	class Visitor
	{
	public:
		virtual void VisitConcreteElementA(ConcreteElementA*) = 0;
		virtual void VisitConcreteElementB(ConcreteElementB*) = 0;

	};

	/// <summary>
	/// A 'ConcreteVisitor' class
	/// </summary>
	class ConcreteVisitor1 : public Visitor
	{
	public:
		virtual void VisitConcreteElementA(ConcreteElementA *concreteElementA);

		virtual void VisitConcreteElementB(ConcreteElementB *concreteElementB);
	};

	/// <summary>
	/// A 'ConcreteVisitor' class
	/// </summary>
	class ConcreteVisitor2 : public Visitor
	{
	public:
		virtual void VisitConcreteElementA(ConcreteElementA *concreteElementA);

		virtual void VisitConcreteElementB(ConcreteElementB *concreteElementB);
	};

	/// <summary>
	/// The 'Element' abstract class
	/// </summary>
	class Element
	{
	public:
		virtual void Accept(Visitor*) = 0;
	};

	/// <summary>
	/// A 'ConcreteElementA' class
	/// </summary>
	class ConcreteElementA : public Element
	{
	public:
		virtual void Accept(Visitor *visitor);

		//we are replacing OperationA with visitor.VisitConcreteElementA(this)
		void OperationA();
	};

	/// <summary>
	/// A 'ConcreteElementB' class
	/// </summary>
	class ConcreteElementB : public Element
	{
	public:
		virtual void Accept(Visitor *visitor);

		//we are replacing OperationB with visitor.VisitConcreteElementB(this)
		void OperationB();
	};

	/// <summary>
	/// The 'ObjectStructure' class
	/// </summary>
	class ObjectStructure : public std::vector<Element*>
	{
	public:
		void Attach(Element *element);

		void Detach(Element *element);

		void AcceptVisior(Visitor *visitor);
		static void Test();
	};
}
