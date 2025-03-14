#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

class UnionFind{
  private:
    vi p, rank;

  public:
    UnionFind(int N){
      p.assign(N, 0);
      for (int i = 0; i < N; ++i)
        p[i] = i;
      rank.assign(N, 0);
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j){
      int x = findSet(i), y = findSet(j);
      if (x == y)
        return;
      if (rank[x] > rank[y])
        swap(x, y);
      p[x] = y;
      if (rank[x] == rank[y])
        ++rank[y];
    }
};

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  UnionFind UF(n);

  for (int i = 0; i < q; i++){
    char c;
    int x, y;
    cin >> c >> x >> y;
    if (c == '?'){
      cout << (UF.isSameSet(x, y) ? "yes\n" : "no\n");
    }else{
      UF.unionSet(x, y);
    }
  }
}