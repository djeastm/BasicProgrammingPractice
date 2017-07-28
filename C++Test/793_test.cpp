
#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;
// Unfinished attempt at 599 with UnionFind

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) {
    if (i == j) return true;
    else return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
      else {
        p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int main() {

#ifndef ONLINE_JUDGE	
  freopen("793.in", "r", stdin);
  freopen("793.out", "w", stdout);
#endif  
  int TC;
  scanf("%d ", &TC); // number of test cases
  int d = 0;
  while (TC--) {
    int count, a, b;
    int successful = 0, unsuccessful = 0;
    scanf(" %d ", &count);
    UnionFind uf(count);
    char t; // type, connection or query
    while (scanf("%[c|q] %d %d\n", &t, &a, &b) == 3) {
      --a; --b;
      if (t == 'c')
        uf.unionSet(a, b);
      else if (t == 'q') {
        if (uf.isSameSet(a, b)) ++successful;
        else ++unsuccessful;
      }
    }
    if (d > 0) printf("\n"); ++d;
    printf("%d,%d\n", successful, unsuccessful);
  }
}
