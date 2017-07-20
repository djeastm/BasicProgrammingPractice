
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ios>
inline void keep_window_open() { char ch; std::cin >> ch; }

#define ONLINE_JUDGE

int main() {
#ifndef ONLINE_JUDGE
	std::string line;
	std::ifstream infile("a.in");
	if (infile.is_open())
	{
		std::ofstream outfile("a.out");
		std::ostringstream oss{};
		if (outfile.is_open())
		{
			while (std::getline(infile, line))
			{
				oss << line << "\n";
			}
			outfile << oss.str();

			/*int c = 1;
			while (std::getline(ss, line)) {
				if (c > 1) outfile << '\n';
				c++;
			}*/

			outfile.close();
		}
		else std::cout << "Unable to open file for writing";

		infile.close();
	}

	else std::cout << "Unable to open for reading";

	return 0;


#endif
#ifdef ONLINE_JUDGE
	std::string input;
	//std::cin >> input;

	std::string output;
	//int n = input.size(), 
	int wp = 0;
	std::vector<char> working(100);
	int i = 0;
	char ch;	
	while(std::cin.get(ch)) {
		if (ch == '"') { 
			working[wp] = '`'; 
			working[wp + 1] = '`';
			wp += 2;
		} else 
		working[wp++] = ch;
	}


	std::cout << std::string(&working[0], &working[wp]);
	keep_window_open();
#endif
}