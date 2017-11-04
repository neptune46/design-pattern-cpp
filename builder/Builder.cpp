//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Builder: //Separate the construction of a complex object from its representation so that the
//same construction process can create different representations.
#include "stdafx.h"
#include "builder.h"
namespace builder
{

	void Director::Construct(Builder *builder)
	{
		_builder = builder;
		_builder->BuildPartA();
		_builder->BuildPartB();
	}

	void Director::Test()
	{
		Director *pDirector = new Director();
	
		Builder *b1 = new ConcreteBuilder1();
		Builder *b2 = new ConcreteBuilder2();
	
		// Construct two products
		pDirector->Construct(b1);
		Product *p1 = b1->GetResult();
		std::cout << std::endl<< "Product Parts from ConcreteBuilder1:\t";
		p1->Display();
	
		pDirector->Construct(b2);
		Product *p2 = b2->GetResult();
		std::cout << std::endl<< "Product Parts from ConcreteBuilder2:\t";
		p2->Display();
	}

	void ConcreteBuilder1::BuildPartA()
	{
		_product->push_back("PartA");
	}

	void ConcreteBuilder1::BuildPartB()
	{
		_product->push_back("PartB");
	}

	Product *ConcreteBuilder1::GetResult()
	{
		return _product;
	}

	void ConcreteBuilder2::BuildPartA()
	{
		_product->push_back("PartC");
	}

	void ConcreteBuilder2::BuildPartB()
	{
		_product->push_back("PartD");
	}

	Product *ConcreteBuilder2::GetResult()
	{
		return _product;
	}

	void Product::Display()
	{
		
		for (Product::const_iterator it = this->begin(); it != this->end(); ++it)
		{
			std::cout <<it->c_str() <<"\t";
		}
		this->clear();
	}
}