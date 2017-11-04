//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Memento: //Without violating encapsulation, capture and externalize an object'sinternal state
//so that the object can be restored to this state later.
#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace memento
{

	/// <summary>
	/// The 'Originator' class
	/// </summary>
	template <class State>
	class Originator
	{
	
		/// <summary>
		///  The 'Memento' class
		/// </summary>
	public:
		class Memento
		{
		private:
			State _state;

			// Constructor
		public:
			Memento(State state);

			// Gets or sets state
			State getState();
		};
	private:
		State _state;

		// Property
	public:
		State getState();
		void setState(State value);

		// Creates memento 
		Memento *CreateMemento();

		// Restores original state
		void SetMemento(Memento *memento);
	};



	/// <summary>
	///  The 'Caretaker' class
	/// </summary>
	class Caretaker
	{
	private:
		Originator<string>::Memento *_memento;

		// Gets or sets memento
	public:

		void setMemento(Originator<string>::Memento *value);
		Originator<string>::Memento *getMemento();

		static void Test();
	};
}
