//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Builder: //Separate the construction of a complex object from its representation so that the
//same construction process can create different representations.
#pragma once
#include <string>
#include <vector>
#include <iostream>


namespace builder
{
	class Product : public std::vector<std::string>
	{

	public:
		void Display();
	};

	class Builder
	{
	public:
		virtual void BuildPartA() = 0;
		virtual void BuildPartB() = 0;
		virtual Product *GetResult() = 0;
	};
	class Director
	{
	private:
		Builder *_builder;
		// Builder constructs using a series of steps
	public:
		void Construct(Builder *builder);

		static void Test();
	};



	class ConcreteBuilder1 : public Builder
	{
	private:
		Product *_product;
	public:
		virtual void BuildPartA();

		virtual void BuildPartB();

		virtual Product *GetResult();
		ConcreteBuilder1 (){_product = new Product();}
	};

	class ConcreteBuilder2 : public Builder
	{
	private:
		Product *_product;
	public:
		virtual void BuildPartA();

		virtual void BuildPartB();

		virtual Product *GetResult();
		ConcreteBuilder2 (){_product = new Product();}
	};


}
