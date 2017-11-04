//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////The Flyweight pattern uses sharing to support large numbers of fine-grained objects
//efficiently.

#pragma once
#include <string>
#include <map>
#include <iostream>

namespace flyweight
{
	/// <summary>
	/// The 'Flyweight' abstract class
	/// /// </summary>
	class Flyweight
	{

	public:
		virtual void Operation(int) = 0;
	};

	/// <summary>
	/// The 'FlyweightFactory' class
	/// /// </summary>
	class FlyweightFactory
	{
		/// <summary>
		/// The 'ConcreteFlyweight' class
		/// /// </summary>
	private:
		class ConcreteFlyweight : public Flyweight
		{
		public:
			ConcreteFlyweight(int intrinsicState);
			virtual void Operation(int extrinsicState);
private:
			int _intrinsicState;
		public:
			int getIntrinsicState();
			void setIntrinsicState(int value);
		};
	private:
		std::map<std::string, Flyweight*> *_flyweights;

		// Constructor
	public:
		FlyweightFactory();

		Flyweight *GetFlyweight(std::string key);
	};




	/// <summary>
	/// The 'UnsharedConcreteFlyweight' class
	/// /// </summary>
	class UnsharedConcreteFlyweight : Flyweight
	{
	public:
		virtual void Operation(int extrinsicState);
	};
	/// <summary>
	/// FlyweightClient startup class for Structural 
	/// Flyweight Design Pattern.
	/// </summary>
	class FlyweightClient
	{

	private:
		static FlyweightFactory *_factory;
		static int _extrinsicState;
	public:
		static void Test();

	};
}

