//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//FactoryMethod: //Define an interface for creating an object, but let subclasses decide which class
//to instantiate. Factory Method lets a class defer instantiation to subclasses.
#pragma once

#include <iostream>
namespace factorymethod
{

	class IProduct
	{
		//override String GetProductName();
	public:
		virtual std::string GetProductName() = 0;
	};


	class DefaultProduct : public IProduct
	{

	public:
		virtual std::string GetProductName();
	};

	class Creator
	{
	protected:
		virtual IProduct *FactoryMethod() = 0;
	public:
		void AnOperation();

		static void Test();

	};
	class ConcreteDefaultCreator : public Creator
	{

	protected:
		virtual IProduct *FactoryMethod();
	};

	class Product1 : public IProduct
	{
	public:
		virtual std::string GetProductName();
	};
	class ConcreteCreator1 : public Creator
	{

	protected:
		virtual IProduct *FactoryMethod();
	};

	class Product2 : public IProduct
	{
	public:
		virtual std::string GetProductName();
	};
	class ConcreteCreator2 : public Creator
	{
	protected:
		virtual IProduct *FactoryMethod();
	};

}
