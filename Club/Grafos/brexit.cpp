#include <bits/stdc++.h>

using namespace std;

vector<int> countries[200010];
int partner[200010];
int leavepartner[200010];
bool leave[200010];

int main(){

  int C, P, X, L;
  cin>>C>>P>>X>>L;

  for (int i = 0; i < P; i++){
    int A, B;
    cin>>A>>B;
    countries[A].push_back(B);
    countries[B].push_back(A);
    partner[A]++;
    partner[B]++;
  }

  queue<int> pq;
  pq.push(L);
  leave[L]=true;

  while (!pq.empty()){
    int na=pq.front();
    pq.pop();

    for (auto &vec: countries[na]){
      leavepartner[vec]++;
      if (!leave[vec] && leavepartner[vec]*2 >= partner[vec]){
        leave[vec]=true;
        pq.push(vec);
      }
    }
  }

  if (leave[X]){
    cout<<"leave"<<endl;
  }else{
    cout<<"stay"<<endl;
  }

  return 0;
}
