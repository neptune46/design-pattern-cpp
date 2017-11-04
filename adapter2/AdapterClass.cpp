//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Convert the interface of a class into another interface clients expect. Adapter
//lets classes work together that couldn't otherwise because of incompatible interfaces.
#include "StdAfx.h"
#include "adapterClass.h"

namespace adapter2
{

	void AdapteeClass::SpecificRequest()
	{
		std::cout << "Called SpecificRequest() in the SpecificRequest" << std::endl;
	}

	void AdapterClass::Request()
	{
		// Possibly do some other work
		std::cout << "Do extra work in the SpecificRequest" << std::endl;
		// and then call SpecificRequest
		SpecificRequest();
	}

	void AdapterClass::Test()
	{
		// What the client really wants
		ITarget *target = new AdapterClass();
		target->Request();
	}
}