#include "stdafx.h"
#include <string>
#include <algorithm> 
#include <fstream>
#include <vector>
#include <iostream>
#include <istream>
#include <iterator>
using namespace std;

int main()
{
	string from, to;
	cin >> from >> to; // get source and target file names
	ifstream is{ from }; // input stream for file "from"
	istream_iterator<string> ii{ is }; // input iterator for stream
	istream_iterator<string> eos{}; // input sentinel

	ofstream os{ to }; // output stream for file "to"
	ostream_iterator<string> oo{ os,"\n" }; // output iterator for stream
	vector<string> b{ ii,eos }; // b is a vector initialized from input
	sort(b.begin(), b.end()); // sor t the buffer
	unique_copy(b.begin(), b.end(), oo); // copy buffer to output, discard replicated values
	return !is.eof() || !os; // retur n error state (§1.3, §8.4)
}