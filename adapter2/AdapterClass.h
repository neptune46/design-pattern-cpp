//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Convert the interface of a class into another interface clients expect. Adapter
//lets classes work together that couldn't otherwise because of incompatible interfaces.
//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com
#pragma once

#include <iostream>

// AdapterClass Pattern -  class flavour
namespace adapter2
{
	/// <summary>
	/// The 'AdapteeClass' class has the existing way requests are implemented
	/// </summary>
	class AdapteeClass
	{
	public:
		void SpecificRequest();
	};


	/// <summary>
	/// The 'ITarget' interface
	/// </summary>
	class ITarget
	{
	public:
		virtual void Request() = 0;
	};


	/// <summary>
	/// The 'AdapterClass' class Implements the required standard via the AdapteeClass
	/// </summary>
	class AdapterClass : AdapteeClass, ITarget
	{

	public:
		void Request();
		static void Test();

	};
}
