#include "stdio.h"
#include <iostream>
#include <cstdio>
#include <string>

int main() {
  
#ifndef ONLINE_JUDGE	
  freopen("1124.in", "r", stdin);
  freopen("1124.out", "w", stdout);
#endif  
  
  std::string input;
  while(std::getline(std::cin, input))
    std::cout << input << "\n";

}