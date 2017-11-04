//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////The Flyweight pattern uses sharing to support large numbers of fine-grained objects
//efficiently.
#include "stdafx.h"
#include "flyweight.h"
namespace flyweight
{
	int FlyweightClient::_extrinsicState = 0;
	FlyweightFactory * FlyweightClient::_factory = new FlyweightFactory();
	void FlyweightClient::Test()
	{
	
		// Work with different flyweight instances from the pool
		Flyweight *fa = _factory->GetFlyweight("A");
		fa->Operation(++_extrinsicState);
	
		Flyweight *fb = _factory->GetFlyweight("B");
		fb->Operation(++_extrinsicState);
	
		Flyweight *fc = _factory->GetFlyweight("C");
		fc->Operation(++_extrinsicState);
	
		UnsharedConcreteFlyweight *uf = new UnsharedConcreteFlyweight();
	
		uf->Operation(--_extrinsicState);
	}


	FlyweightFactory::ConcreteFlyweight::ConcreteFlyweight(int intrinsicState)
	{
		_intrinsicState = intrinsicState;
	}

	void FlyweightFactory::ConcreteFlyweight::Operation(int extrinsicState)
	{
		std::cout << "ConcreteFlyweight: " << extrinsicState << std::endl;
	}

	int FlyweightFactory::ConcreteFlyweight::getIntrinsicState()
	{
		return _intrinsicState;
	}

	void FlyweightFactory::ConcreteFlyweight::setIntrinsicState(int value)
	{
		_intrinsicState = value;
	}

	FlyweightFactory::FlyweightFactory()
	{
		_flyweights = new std::map<std::string, Flyweight*>();
		(*_flyweights)["A"] = new ConcreteFlyweight(1);
		(*_flyweights)["B"] = new ConcreteFlyweight(2);
		(*_flyweights)["C"] = new ConcreteFlyweight(3);
	}

	Flyweight *FlyweightFactory::GetFlyweight(std::string key)
	{

		std::map<std::string, Flyweight*>::const_iterator it = _flyweights->find(key);
		if ( it == _flyweights->end() ) 
			return NULL;
		else
		{
			return it->second;
		}
	}

	void UnsharedConcreteFlyweight::Operation(int extrinsicState)
	{
		std::cout << "UnsharedConcreteFlyweight: " << extrinsicState << std::endl;
	}
}