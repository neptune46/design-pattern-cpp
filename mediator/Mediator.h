//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Define an object that encapsulates how a set of objects interact.Mediator promotes
//loose coupling by keeping objects from referring toeach other explicitly, and it
//lets you vary their interaction independently.
#pragma once
#include <string>
#include <iostream>

namespace mediator
{
	class Colleague;
	/// <summary>
	/// "Mediator" 
	/// </summary>
	class Mediator
	{
	public:
		virtual void SendMsg(std::string, Colleague*) = 0;
		static void Test();
	};

	class ConcreteColleague1;
	class ConcreteColleague2;
	/// <summary>
	///  "ConcreteMediator" 
	/// </summary>
	class ConcreteMediator : public Mediator
	{
	private:
		ConcreteColleague1 *_colleague1;
		ConcreteColleague2 *_colleague2;

	public:
		void setColleague1(ConcreteColleague1 *value);

		void setColleague2(ConcreteColleague2 *value);

		virtual void SendMsg(std::string message, Colleague *colleague);
	};

	/// <summary>
	/// "Colleague" 
	/// </summary>
	class Colleague
	{
	protected:
		Mediator *_mediator;

		// Constructor 
	public:
		Colleague(Mediator *mediator);
		virtual void Notification(std::string) = 0;

	};

	/// <summary>
	/// "ConcreteColleague1" 
	/// </summary>
	class ConcreteColleague1 : public Colleague
	{
		// Constructor 
	public:
		ConcreteColleague1(Mediator *mediator);

		void Send(std::string message);

		virtual void Notification(std::string message);
	};

	/// <summary>
	/// "ConcreteColleague2" 
	/// </summary>
	class ConcreteColleague2 : public Colleague
	{
		// Constructor 
	public:
		ConcreteColleague2(Mediator *mediator);

		void Send(std::string message);

		virtual void Notification(std::string message);
	};
}
