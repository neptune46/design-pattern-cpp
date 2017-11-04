//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Compose objects into tree structures to represent part-whole hierarchies. Composite
//lets clients treat individual objects and compositions of objects uniformly.
#pragma once

#include <string>
#include <map>
namespace composite
{

	/// <summary>
	/// The 'Component' abstract class
	/// </summary>
	class Component
	{
	private:
		std::string _name;

	public:
		std::string getName();
		void setName(std::string value);

		// Constructor
		Component(std::string name);

		virtual void Add(Component*) = 0;
		virtual void Remove(Component*) = 0;
		virtual void Operation(int) = 0;
		virtual Component *GetChild(std::string) = 0;

	};

	/// <summary>
	/// The 'Composite' class
	/// </summary>
	class Composite : public Component
	{
	private:

		std::map<std::string, Component*> *_children;

		// Constructor
	public:
		Composite(std::string name);

		virtual void Add(Component *Component);

		virtual void Remove(Component *Component);

		virtual void Operation(int tabs);

		virtual Component *GetChild(std::string name);
		static void Test();
	};

	/// <summary>
	/// The 'Leaf' class
	/// </summary>
	class Leaf : public Component
	{
		// Constructor
	public:
		 Leaf(std::string name);

		virtual void Add(Component *c);

		virtual void Remove(Component *c);

		virtual void Operation(int tabs);

		virtual Component *GetChild(std::string name);
	};
}

