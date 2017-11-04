//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Attach additional responsibilities to an object dynamically. Decorators provide
//a flexible alternative to subclassing for extending functionality.
#pragma once
#include <iostream>

namespace decorator
{
	/// <summary>
	/// The 'Component' abstract class
	/// </summary>
	class Component
	{
	public:
		virtual void Operation() = 0;
	};

	/// <summary>
	/// The 'ConcreteComponent' class
	/// </summary>
	class ConcreteComponent : public Component
	{
	public:
		virtual void Operation();
	};

	/// <summary>
	/// The 'Decorator' abstract class
	/// </summary>
	class Decorator: Component
	{
	public:
		static void Test();
private:
	Component *_component;
	public:
		Component *getcomponent();
		void setcomponent(Component *value);

		virtual void Operation();
	};

	/// <summary>
	/// The 'ConcreteDecoratorA' class
	/// </summary>
	class ConcreteDecoratorA : public Decorator
	{
	public:
		virtual void Operation();
	private:
		void *_addedeSate;
	};

	/// <summary>
	/// The 'ConcreteDecoratorB' class
	/// </summary>
	class ConcreteDecoratorB : public Decorator
	{
	public:
		virtual void Operation();

	private:
		void AddedBehavior();
	};
}
