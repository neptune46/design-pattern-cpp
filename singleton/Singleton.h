//This source code was generated using Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Singleton: //Ensure a class only has one instance, and provide a global point of access to it.
#pragma once

namespace singleton
{
	class ConcreteSingleton
	{
	private:

		ConcreteSingleton();
		static ConcreteSingleton *_instance;


	public:
		static ConcreteSingleton *getInstance();

		void Operation();

		static void Test();

	};
}
