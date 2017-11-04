//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Provide a unified interface to a set of interfaces in a subsystem. Facade defines
//a higher-level interface that makes the subsystem easier to use.
#pragma once
#include <string>
#include <iostream>

namespace facade
{

	class FacadeClient
	{
	public:
		static void Test();
	};


	class SubsystemA
	{
	public:
		std::string A1();
		std::string A2();
	};

	class SubsystemB
	{
	public:
		std::string B1();
		std::string B2();
	};

	class Facade
	{
	private:
		static SubsystemA *a;
		static SubsystemB *b;

	public:
		static void Operation1();
		static void Operation2();
		Facade()	{}
	
	};
}
