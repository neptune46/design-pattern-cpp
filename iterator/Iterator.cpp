//This source code was generated using Premium Visual Studio Design Patterns add-in
//You can find the source code and binaries at http://VSDesignPatterns.codeplex.com

//Iterator: //Provide a way to access the elements of an aggregate object sequentially without
//exposing its underlying representation.
#include "stdafx.h"
#include <iostream>
#include <set>
#include <string>
using namespace std;
#include "iterator.h"

namespace iterator
{
template <class T>
void ITERATE (const T& typedCollection, const char* separator="")
{
    typename T::const_iterator pos;

    std::cout << separator;
    for (pos = typedCollection.begin(); pos != typedCollection.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
 #pragma warning( push )
 #pragma warning( disable:  4996 4018)
	void IteratorClient::Test()
	{
	std::set<string> typedCollection;   

    // create inserter for typedCollection
    CustomIterator<set<string> > iter(typedCollection);

    // insert elements with the regular iterator interface
    *iter = "Item1";
    iter++;
    *iter = "Item2";
    iter++;
    *iter = "Item3";

    ITERATE(typedCollection);

    // create inserter for typedCollection and insert elements more conveniently
    insertHelper(typedCollection) = "Item4";
    insertHelper(typedCollection) = "Item5";

    ITERATE(typedCollection);

    // use inserter with an algorithm
    string vals[] = { "Item10", "Item11", "Item12" };
    copy (vals, vals+(sizeof(vals)/sizeof(vals[0])),  // source
          insertHelper(typedCollection)); // destination

    ITERATE(typedCollection);

	}// end test
#pragma warning( pop )
	template <class Container>
	CustomIterator<Container>& CustomIterator<Container>::operator* () 
	{
		return *this;
	}

	template <class Container>
	CustomIterator<Container>::CustomIterator (Container& c) : container(c) 
	{}

	template <class Container>
	CustomIterator<Container>& CustomIterator<Container>::operator++ () 
	{
		return *this;
	}

	template <class Container>
	CustomIterator<Container>& CustomIterator<Container>::operator++ (int) 
		{
			return *this;
		}
	template <class Container>
	CustomIterator<Container>& CustomIterator<Container>::operator= (const typename Container::value_type& value)	
	
	{ 
		container.insert(value);
		return *this;
	}
}
