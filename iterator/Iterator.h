//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Iterator: //Provide a way to access the elements of an aggregate object sequentially without
//exposing its underlying representation.
#pragma once
#include <iterator>
namespace iterator
{
	// template class for insert iterator for associative containers
	template <class Container>
	class CustomIterator
	 : public std::iterator <std::output_iterator_tag, void, void, void, void>				
	{
	  protected:
		Container& container;    // container for elements 

	  public:
		// constructor
		explicit CustomIterator (Container& c);

		// assignment operator inserts a value into the container
		CustomIterator<Container>& operator= (const typename Container::value_type& value);
		// dereferencing is a no-op that returns the iterator itself
		CustomIterator<Container>& operator* ();
		// increment operation is a no-op that returns the iterator itself
		CustomIterator<Container>& operator++ ();
		CustomIterator<Container>& operator++ (int); 

	};

	// helper function to create the inserter
	template <class Container>
	inline CustomIterator<Container> insertHelper (Container& c)
	{
		return CustomIterator<Container>(c);
	}
	/// <summary>
	/// IteratorClient
	/// </summary>
	class IteratorClient
	{

	public:
		static void Test();
	};

}
