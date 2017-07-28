#include "stdio.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <bitset>

int main() {

#ifndef ONLINE_JUDGE	
  freopen("599.in", "r", stdin);
  freopen("599.out", "w", stdout);
#endif  
  // Hint
  // v-e = number of connected components, keep a bitset of 
  // size 26 to count the number of vertices that
  // have some edge.Note: Also solvable with Union - Find
  //
  int TC;
  char a, b;
  scanf("%d", &TC); // number of test cases
  while (TC--) {
    std::bitset<26> bs(0);
    int e = 0;
    while (scanf(" (%c,%c)", &a, &b)) { // get edge list
      ++e;
      if (a == '*') break;
      int x = a - 'A';
      int y = b - 'A';
      //printf("%d, %d\n", x, y);
      bs.set(x); bs.set(y);
      //std::cout << bs;
    }    
    int v = 0;    
    char comma;
    while (scanf("%c", &a), a == '*');
    while (scanf("%c%c", &a, &comma) != EOF) {
      ++v;
      if (comma == '\n') break;
    }
    int connComp = v - e; // connected components
    int acorns = v-bs.count();
    int trees = connComp - acorns;    
    printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
  }
}