#include "stdio.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

int main() {

#ifndef ONLINE_JUDGE	
  freopen("146.in", "r", stdin);
  freopen("146.out", "w", stdout);
#endif  
  char input[55];
  while (fgets(input, sizeof input, stdin)) {
    if (input[0] == '#') break;
    std::vector<char> vect;    
    for (char& ch : input) {
      if (ch == '\n') break;
      vect.push_back(ch);
    }
    std::next_permutation(vect.begin(), vect.end());
    std::string successor;
    for (char& ch : vect) {
      if (ch == '\n') break;
      successor += ch;
    }
    if (successor > input)
      printf("%s", successor.c_str());
    else
      printf("No Successor");
    printf("\n");
  }
}