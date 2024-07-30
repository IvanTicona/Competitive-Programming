#include<bits/stdc++.h>

using namespace std;

vector<int> grafo[200010];
int degree[200010];
int lostPartners[200010];
bool leftUnion[200010];

int main(){

  int c, p, x, l;
  cin>>c>>p>>x>>l;
  for (int i = 0; i < p; i++){
    int a, b;
    cin>>a>>b;
    //Los socios son socios entre si, no uno si y el otro no
    grafo[b].push_back(a);
    grafo[a].push_back(b);
    degree[a]++;
    degree[b]++;
  }

  memset(lostPartners,0,sizeof(lostPartners));
  memset(leftUnion,false,sizeof(leftUnion));

  priority_queue<int> pq;
  pq.push(l);
  leftUnion[l]=true;

  while (!pq.empty()){
    int nodoActual=pq.top(); pq.pop();
    for(int vec: grafo[nodoActual]){
      lostPartners[vec]++;
      if(!leftUnion[vec]&&lostPartners[vec]*2>=degree[vec]){
        leftUnion[vec]=true;
        pq.push(vec);
      }
    }
  }
  
  if(leftUnion[x]) cout<<"leave"<<endl;
  else cout<<"stay"<<endl;

  return 0;
}