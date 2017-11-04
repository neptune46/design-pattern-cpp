//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Proxy: //Provide a surrogate or placeholder for another object to control access to it.
#pragma once
#include <string>
#include <iostream>

namespace proxy
{

	// Subject 
	class Subject
	{
	public:
		virtual void Request() = 0;
	};

	// Proxy class
	class Proxy : public Subject
	{
	private:
		Subject *m_pRealSubject;

	public:
		virtual void Request();
		Proxy();
	};
	// RealSubject class
	class RealSubject : public Subject
	{
	public:
		static void Test();
		virtual void Request();
	};
}
