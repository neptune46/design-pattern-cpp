//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//AbstractFactory: //Provide an interface for creating families of related or dependent objects without
//specifying their concrete classes.
#pragma once
#include "Products.h"

namespace abstractfactory
{
	/// The 'Client' class. Interaction environment for the products.
	class AbstractFactory;
	class Client
	{

	private:
		AbstractProductA *_AbstractProductA;
		AbstractProductB *_AbstractProductB;

		/// The main entry point for the application.
	public:
		static void Test();
		// Constructor
		Client(AbstractFactory *factory);
		void Run();
	};


  /// The 'AbstractFactory' abstract class
  class AbstractFactory
  {
	public:
	virtual AbstractProductA *CreateProductA() = 0;
	virtual AbstractProductB *CreateProductB() = 0;

  };

  /// The 'ConcreteFactory1' class
  class ConcreteFactory1 : public AbstractFactory
  {
	public:
	virtual AbstractProductA *CreateProductA();
	virtual AbstractProductB *CreateProductB();
  };


  /// The 'ConcreteFactory2' class
  class ConcreteFactory2 : public AbstractFactory

  {
	public:
	virtual AbstractProductA *CreateProductA();
	virtual AbstractProductB *CreateProductB();

  };


}


