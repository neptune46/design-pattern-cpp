//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Convert the interface of a class into another interface clients expect. Adapter
//lets classes work together that couldn't otherwise because of incompatible interfaces.
#pragma once

#include <iostream>

// AdapterObject Pattern -  Object flavour
namespace adapter
{ /// <summary>
	/// The 'AdapteeObject' class has the existing way requests are implemented
	/// </summary>
	class AdapteeObject
	{
	public:
		void SpecificRequest();
	};


	/// <summary>
	/// The 'Target' class
	/// </summary>
	class Target
	{
	public:
		virtual void Request();
	};


	/// <summary>
	/// The 'AdapterObject' class Implements the required standard via the AdapteeObject
	/// </summary>
	class AdapterObject : Target
	{
	private:

		AdapteeObject *_adaptee;
	public:
		virtual void Request();
		static void Test();
		 AdapterObject()
		 {_adaptee = new AdapteeObject();
		 }
	};


}
