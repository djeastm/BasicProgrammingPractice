
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>

int main() {
	

#ifndef ONLINE_JUDGE	
  freopen("11172.in", "r", stdin);
  freopen("11172.out", "w", stdout);
#endif
	
  int TC, a, b;
  scanf("%d", &TC); 
  while (TC--) { 
    scanf("%d %d", &a, &b); 
    char op;
    if (a < b) op = '<';
    else if (a > b) op = '>';
    else op = '=';
    printf("%c\n", op); 
  }

}