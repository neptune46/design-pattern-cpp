//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Prototype: //Specify the kinds of objects to create using a prototypical instance, and create
//new objects by copying this prototype.
#pragma once
#include <string>
#include <iostream>

namespace prototype
{
	// "Prototype" 
	class Prototype
	{
		// Constructor 
	public:
		Prototype(std::string id);

		// Property 
	private:
		std::string privateId;
	public:
		std::string getId();
		void setId(std::string value);

		virtual Prototype *Clone() = 0;
	};

	// "ConcretePrototypeA" 
	class ConcretePrototypeA : public Prototype
	{
		// Constructor 
	public:
		ConcretePrototypeA(std::string id);

		virtual Prototype *Clone();
	};

	// "ConcretePrototypeB" 
	class ConcretePrototypeB : public Prototype
	{
		// Constructor 
	public:
		ConcretePrototypeB(std::string id);

		virtual Prototype *Clone();
	};

	class PrototypeClient
	{
	
	public:
		static void Test();
	};
}

