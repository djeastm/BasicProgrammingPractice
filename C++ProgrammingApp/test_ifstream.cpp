#include "stdafx.h"
#include <string>
#include <algorithm> 
#include <fstream>
#include <vector>
#include <iostream>
#include <istream>
#include <iterator>
#include <set>

template<typename T, typename ... Args>
unique_ptr<T> make_unique(Args&&... args)
{
	// a way to make a "make_unique" to match the std make_shared, if needed
	return std::unique_ptr<T>{new T{ std::forward<Args>(args)... }};
}

namespace Estd {
	using namespace std;
	template<typename C>
	void sort(C& c)
	{
		sor t(c.begin(), c.end());
	}
	template<typename C, typename Pred>
	void sort(C& c, Pred p)
	{
		sor t(c.begin(), c.end(), p);
	}
	// ...
}
using namespace Estd;

int main()
{
	
	string from, to;
	cin >> from >> to; // get source and target file names
	ifstream is{ from }; // input stream for file "from"
	istream_iterator<string> ii{ is }; // input iterator for stream
	istream_iterator<string> eos{}; // input sentinel

	ofstream os{ to }; // output stream for file "to"
	ostream_iterator<string> oo{ os,"\n" }; // output iterator for stream

	//vector<string> b{ ii,eos }; // b is a vector initialized from input
	//sort(b.begin(), b.end()); // sort the buffer
	//sort(b); // using Estd to simplify sorting containers
	//unique_copy(b.begin(), b.end(), oo); // copy buffer to output, discard replicated values
	
	/*A more elegant solution is not to store duplicates at all.
	This can be done by keeping the strings in a set, 
	which does not keep duplicates and keeps its elements in order(§9.4).
	That way, we could replace the two lines using a
	vector with one using a set and replace unique_copy() with the simpler copy() :*/
	set<string> b{ ii,eos }; // collect strings from input
	copy(b.begin(), b.end(), oo); // copy buffer to output

	return !is.eof() || !os; // retur n error state (§1.3, §8.4)

	
}