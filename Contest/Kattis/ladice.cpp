#include<bits/stdc++.h>

using namespace std;

class UnionFind{
  private:
    vector<int> parent, rank;
  public:
    UnionFind(int n){
      parent.assign(n, 0);
      for (int i = 0; i < n; i++){
        parent[i] = i;
      }
      rank.assign(n, 0);
    }

};

int main(){

  int N, L;
  cin>>N>>L;

  for(int i=0 ; i<N; i++){
    int A, B;
    cin>>A>>B;
    
  }
  return 0;
}