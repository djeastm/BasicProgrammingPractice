
//#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
//#include <ios>
//inline void keep_window_open() { char ch; std::cin >> ch; }

//#define ONLINE_JUDGE

int main() {
	// OPTION 1
//#ifndef ONLINE_JUDGE
//	std::string line;
//	std::ifstream infile("a.in");
//	if (infile.is_open())
//	{
//		std::ofstream outfile("a.out");
//		std::ostringstream oss{};
//		if (outfile.is_open())
//		{
//			while (std::getline(infile, line))
//			{
//				oss << line << "\n";
//			}
//			outfile << oss.str();
//
//			/*int c = 1;
//			while (std::getline(ss, line)) {
//				if (c > 1) outfile << '\n';
//				c++;
//			}*/
//
//			outfile.close();
//		}
//		else std::cout << "Unable to open file for writing";
//
//		infile.close();
//	}
//
//	else std::cout << "Unable to open for reading";
//
//	return 0;
//
//
//#endif

	// Archive

	/*char line[110];
	freopen("a.in", "r", stdin);
	std::string text = "";
	while (1) {
	fgets(line, 100, stdin);
	text += line;

	if (feof(stdin)) break;
	}

	printf("%s", text.c_str());*/

#ifndef ONLINE_JUDGE	
	freopen("00272.in", "r", stdin);
	freopen("00272.out", "w", stdout);
#endif
	//int n = input.size(), 
	int wp = 0;
	std::vector<char> working(1000000);
	int i = 0;
	char ch;	
	bool first = true;
	while(std::cin.get(ch)) {
		if (ch == '"') { 
			if (first) {
				working[wp] = '`';
				working[wp + 1] = '`';
				first = false;
			}
			else {
				working[wp] = '\'';
				working[wp + 1] = '\'';
				first = true;
			}			
			wp += 2;
		} else 
		working[wp++] = ch;
	}


	std::cout << std::string(&working[0], &working[wp]);
	std::cout.flush();
#ifndef ONLINE_JUDGE
//	keep_window_open();
#endif
}