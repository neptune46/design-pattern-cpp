//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Convert the interface of a class into another interface clients expect. Adapter
//lets classes work together that couldn't otherwise because of incompatible interfaces.
#include "StdAfx.h"
#include "adapterObject.h"
namespace adapter
{

	void AdapteeObject::SpecificRequest()
	{
		std::cout << "Called SpecificRequest() in the AdapteeObject" << std::endl;
	}

	void Target::Request()
	{
		std::cout << "Called Target Request() in the AdapteeObject" << std::endl;
	}

	void AdapterObject::Request()
	{
		// Possibly do some other work
		std::cout << "Do extra work in the AdapteeObject" << std::endl;
		// and then call SpecificRequest
		_adaptee->SpecificRequest();
	}

	void AdapterObject::Test()
	{
		// What the client really wants
		AdapterObject *second = new AdapterObject();
		second->Request();
	}
}