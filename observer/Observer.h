//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Observer: //Define a one to many dependency between objects so that when one object changes
//state, all its dependents are notified and updatedautomatically.
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
namespace observer
{

	/// <summary>
	/// The 'Observer' abstract class
	/// </summary>
	class Observer
	{
	public:
		virtual void Update() = 0;
	};

	/// <summary>
	/// The 'Subject' abstract class
	/// </summary>
	class Subject: std::vector<Observer*>
	{
	public:
		static void Test();

		void Attach(Observer *observer);
		void Detach(Observer *observer);
		void Notify();
	};

	/// <summary>
	/// The 'ConcreteSubject' class
	/// </summary>
	class ConcreteSubject : public Subject
	{
	private:
		string _subjectState;
		// Gets or sets subject state
	public:
		string getSubjectState();
		void setSubjectState(string value);
	};


	/// <summary>
	/// The 'ConcreteObserver' class
	/// </summary>
	class ConcreteObserver : public Observer
	{
	private:
		std::string _name;
		string _observerState;
		ConcreteSubject *_subject;
		// Constructor
	public:
		ConcreteObserver(ConcreteSubject *subject, std::string name);
		virtual void Update();

	};
}
