// UVA00272.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <stdio.h>
#include <regex>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <iostream>
#include <fstream>

#ifndef ONLINE_JUDGE
	inline void keep_window_open() { char ch; std::cin >> ch; }
#endif

int main()
{

//#ifndef ONLINE_JUDGE
//	fopen("a.in", "r");
//	fopen("a.out", "w");
//#endif
	
#ifndef ONLINE_JUDGE
	std::string n = "a.in";
	std::string o = "a.out";
	std::ifstream in{ n, std::ios_base::in };
	std::ofstream out{ o, std::ios_base::out };
	if (!in) {
		std::cerr << "no " << n << '\n';
		keep_window_open();
		exit(1);
	}
#endif
	std::regex startpat{ R"("\b)"};
	std::regex endpat{ R"(\b"|\b\D")"};
	int d = 1;
#ifndef ONLINE_JUDGE
	for (std::string s; std::getline(in, s);) {
#endif
#ifdef ONLINE_JUDGE		
	for (std::string s; std::getline(std::cin, s);) {
#endif
		std::string s2;
		s2 = regex_replace(s, startpat, "``");
		
#ifndef ONLINE_JUDGE
		if (!out) {
			std::cerr << "no " << o << '\n';
			keep_window_open();
			exit(1);
		}
		if (d > 1) out << "\n"; // print the extra line beforehand if on 2nd or later
		out << regex_replace(s2, endpat, "''");
		out.flush();
#endif

#ifdef ONLINE_JUDGE
		if (d > 1) std::cout << "\n"; // print the extra line beforehand if on 2nd or later
		std::cout << regex_replace(s2, endpat, "''");
#endif
		d++;
	}

#ifndef ONLINE_JUDGE
	out.close();
	in.close();
	keep_window_open();
	
	
#endif
	return 0;
}

