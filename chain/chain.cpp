//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Avoid coupling the sender of a request to its receiver by giving more than one object
//a chance to handle the request.
//
//Chain the receiving objects and pass the request along the chain until an object
//handles it.
#include "stdafx.h"
#include "chain.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;
namespace chain
{

	const int Request::getTarget()
	{
		return _data;
		
	}

	Request::Request(int data)
	{
		_data = data;
	}

	void Handler::Test()
	{
		// Setup Chain of Responsibility 
		Handler *h1 = new ConcreteHandlerA();
		Handler *h2 = new ConcreteHandlerB();
		Handler *h3 = new ConcreteHandlerC();
		h1->SetSuccessor(h2);
		h2->SetSuccessor(h3);

		//Generate  requests	
/*
		  std::vector<Request*> vec;
		  vec.push_back(new Request(1));
		  vec.push_back(new Request(7));
		  vec.push_back(new Request(15));
		  vec.push_back(new Request(23));
		  vec.push_back(new Request(13));
		  vec.push_back(new Request(6));
		  vec.push_back(new Request(28));
		  vec.push_back(new Request(23));
*/
		  Request* requests[] = {new Request(1), new Request(7), new Request(15), new Request(23), new Request(13), new Request(6), new Request(28), new Request(23)};
		  std::vector <Request*> vec(&requests[0], &requests[sizeof(requests)/sizeof(requests[0])]);
		 //process requests

		  for (std::vector<Request*>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		{
			h1->HandleRequest(*it);
			delete *it;
		}
		vec.clear();

	}

	void Handler::SetSuccessor(Handler *successor)
	{
		this->successor = successor;
	}

	bool ConcreteHandlerA:: CanHandle(Request* request)
	{
		return request->getTarget() >= 0 && request->getTarget() < 10;
	}
	void ConcreteHandlerA::HandleRequest(Request *request)
	{
		if (CanHandle(request))
		{
			cout << "ConcreteHandlerA handled request " << request->getTarget() << std::endl;
	
		}
		else if (successor != NULL)
		{
			successor->HandleRequest(request);
		}
	}

	bool ConcreteHandlerB:: CanHandle(Request* request)
	{
		return request->getTarget() >= 10 && request->getTarget() < 20;
	}
	void ConcreteHandlerB::HandleRequest(Request *request)
	{
		if (CanHandle(request))
		{
			std::cout <<"ConcreteHandlerB handled request " << request->getTarget() << std::endl;
	
		}
		else if (successor != NULL)
		{
			successor->HandleRequest(request);
		}
	}

	bool ConcreteHandlerC:: CanHandle(Request* request)
	{
		return request->getTarget() >= 20 && request->getTarget() < 30;
	}

	void ConcreteHandlerC::HandleRequest(Request *request)
	{
		if (CanHandle(request))
		{
			std::cout << "ConcreteHandlerC handled request " << request->getTarget() << std::endl;
	
		}
		else if (successor != NULL)
		{
			successor->HandleRequest(request);
		}
	}

}