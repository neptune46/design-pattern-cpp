//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//AbstractFactory: //Provide an interface for creating families of related or dependent objects without
//specifying their concrete classes.
#pragma once
#include <iostream>
namespace abstractfactory
{



	/// The 'AbstractProductA' abstract class
	class AbstractProductA
	{
	public:
		virtual std::string GetName() = 0;
	};


	/// The 'AbstractProductB' abstract class
	class AbstractProductB
	{

	public:
		virtual void Interact(AbstractProductA*) = 0;

	};


	/// The 'ProductA1' class
	class ProductA1 : public AbstractProductA
	{
	public:
		virtual std::string GetName();
	};

	/// The 'ProductB1' class
	class ProductB1 : public AbstractProductB
	{

	public:
		virtual void Interact(AbstractProductA *a);

	};


	/// The 'ProductA2' class
	class ProductA2 : public AbstractProductA
	{
	public:
		virtual std::string GetName();
	};


	/// The 'ProductB2' class
	class ProductB2 : public AbstractProductB
	{

	public:
		virtual void Interact(AbstractProductA *a);

	};


}
