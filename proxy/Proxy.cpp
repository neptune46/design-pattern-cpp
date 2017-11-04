//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Proxy: //Provide a surrogate or placeholder for another object to control access to it.
#include "stdafx.h"
#include "Proxy.h"

namespace proxy
{
	Proxy::Proxy()
	{
		m_pRealSubject = NULL;
	}
	void Proxy::Request()
	{
		//  'lazy initialization' 
		if (m_pRealSubject == NULL)
		{
			m_pRealSubject = new RealSubject();
		}
	
		m_pRealSubject->Request();
	}

	void RealSubject::Test()
	{
		// Create proxy and request a service 
		Proxy *proxy = new Proxy();
		proxy->Request();
	}

	void RealSubject::Request()
	{
		std::cout << "Called RealSubject::Request()" << std::endl;
	}
}