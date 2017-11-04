//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

////Compose objects into tree structures to represent part-whole hierarchies. Composite
//lets clients treat individual objects and compositions of objects uniformly.
#include "stdafx.h"
#include "composite.h"
#include <iostream>
using namespace std;
namespace composite
{

	std::string Component::getName()
	{
		return _name;
	}

	void Component::setName(std::string value)
	{
		_name = value;
	}

	Component::Component(std::string name)
	{
		this->_name = name;
	}

	Composite::Composite(std::string name) : Component(name)
	{
		_children = new map<std::string, Component*>();
	}

	void Composite::Add(Component *Component)
	{
		(*_children)[Component->getName()] = Component;
	}

	void Composite::Remove(Component *Component)
	{
		_children->erase(Component->getName());
	}

	void Composite::Operation(int tabs)
	{
		std::cout << std::string(tabs,'\t') << "Composite " <<getName() << std::endl;
	
		// Recursively display child nodes
		for (std::map<std::string, Component*>::const_iterator it = _children->begin(); it != _children->end(); it++)
		{
			GetChild(it->first)->Operation(tabs + 1);
		}
	}

	Component *Composite::GetChild(std::string name)
	{
		
			std::map<std::string, Component*>::const_iterator it = _children->find(name);
		if ( it == _children->end() ) 
			return NULL;
		else
		{
			return it->second;
		}
		
	}

	void Composite::Test()
	{
		// Create a tree structure
		Component *root = new Composite("Root");
		Component *a = new Leaf("A");
		root->Add(a);
		Component *b = new Leaf("B");
		root->Add(b);
	
		Component *c = new Leaf("C");
		root->Add(c);
	
		Component *comp = new Composite("Branch");
		Component *l1 = new Leaf("1");
		comp->Add(l1);
		Component *l2 = new Leaf("2");
		comp->Add(l2);
		root->Add(comp);
	
	
		// display tree recursively
		root->Operation(0);
		// remove all
		root->Remove(c);
		root->Remove(a);
		root->Remove(b);
		comp->Remove(l1);
		comp->Remove(l2);
		root->Remove(comp);
		// remove a  Leaf
		//Leaf  Leaf = new  Leaf("Leaf D");
		//root.Add(leaf);
		//root.Remove(leaf);
		std::cout << "After all branches removed:" << std::endl;
		// Recursively display tree
		root->Operation(0);
	}

	 Leaf:: Leaf(std::string name) : Component(name)
	{
	}

	void Leaf::Add(Component *c)
	{
		throw "Cannot add to a  Leaf";
		std::cout << std::endl;
	}

	void Leaf::Remove(Component *c)
	{
		throw "Cannot remove a  Leaf";
	}

	void Leaf::Operation(int tabs)
	{
		std::cout << std::string(tabs, '\t') <<" Leaf " << getName() << std::endl;
	}

	Component * Leaf::GetChild(std::string name)
	{
		throw "Threre are no children in the leaves";
	}
}