// C++ProgrammingApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm> 
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
inline void keep_window_open() { char ch; std::cin >> ch; }
using namespace std;
using namespace my_code;


int main()
{
	typedef long long ll; 
	typedef pair<int, int> ii; 
	typedef vector<ii> vii;
	typedef vector<int> vi;
	#define INF 1000000000


	//memset(memo, -1, sizeof memo); // initialize DP memoization table with -1
	//memset(arr, 0, sizeof arr); // to clear array of integers


	int billion = INF;
	vii test;
	//cout << "Hello World\n";
	read_file_for_me();
	keep_window_open();
    return 0;
}

void my_code::read_file_for_me() {
	FILE* fp = fopen("ch1_02_scanf_input.txt", "r");
	if (!fp) {
		perror("File opening failed");
		return;
	}
	int N;         
	char x[110];  // array size a bit larger than needed
	fscanf(fp,"%d\n", &N);
	while (N--) {                  // we simply loop from N, N-1, N-2, ..., 0
		fscanf(fp,"0.%[0-9]...\n", &x);   // `&' is optional when x is a char array
									  // note: if you are surprised with the trick above,
									  // please check scanf details in www.cppreference.com
		printf("the digits are 0.%s\n", x);
	}
	fclose(fp);
}

