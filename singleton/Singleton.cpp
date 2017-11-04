//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Singleton: //Ensure a class only has one instance, and provide a global point of access to it.
#include "StdAfx.h"
#include "Singleton.h"
#include <string>
#include <iostream>
namespace singleton
{

	
	ConcreteSingleton::ConcreteSingleton()
	{
	}
	ConcreteSingleton* ConcreteSingleton::_instance = new ConcreteSingleton();
	ConcreteSingleton *ConcreteSingleton::getInstance()
	{
		return _instance;
	}

	void ConcreteSingleton::Operation()
	{
		std::cout << "Some Singleton Operation " << std::endl;
	}

	void ConcreteSingleton::Test()
	{
		ConcreteSingleton *singleton = ConcreteSingleton::getInstance();
		singleton->Operation();
	
	}
}