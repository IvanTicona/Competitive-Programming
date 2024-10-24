/*
Author: Ivan Ticona
*/
#include<bits/stdc++.h>

using namespace std;
#define NMAX 3610

int head, tail, total, n, edgeN;
int q[NMAX], slic[NMAX], lead[NMAX], headg[NMAX], tailg[NMAX];

//DINIC ALGORITHM

struct stct0{
  int next, v;
} edge[100000];

int DFS(int point){
  int ptrg;
  ptrg = headg[point];
  while(ptrg+1){
    if(lead[edge[ptrg].v] == -1 || (slic[lead[edge[ptrg].v]] == slic[point]+1 && DFS(lead[edge[ptrg].v]) )){
      lead[edge[ptrg].v] = point;
      return 1;
    }
    ptrg = edge[ptrg].next;
  }
  slic[point] = -1;
  return 0;
}

int BFS(){
  int flag, ptrg, i;
  head = 0;
  for (int i = 0; i <= n-1; i++) slic[i] = 1;
  for (int i = 0; i <= n-1; i++) if(lead[i] != -1) slic[lead[i]] = -1;
  tail = 0;
  for (int i = 0; i <= n-1; i++) if(slic[i] == 1) q[tail++] = i;
  flag = 0;
  while(head != tail){
    ptrg = headg[q[head]];
    while(ptrg != -1){
      if(lead[edge[ptrg].v] == -1) flag = 1;
      else if (slic[lead[edge[ptrg].v]] == -1){
        slic[lead[edge[ptrg].v]] = slic[q[head]] + 1;
        q[tail++] = lead[edge[ptrg].v];
      }
      ptrg = edge[ptrg].next;
    }
    ++head;
  }
  return flag;
}

void add(int a, int b){
  if(headg[a] == -1) headg[a] = edgeN;
  else edge[tailg[a]].next = edgeN;
  edge[edgeN].next = -1;
  edge[edgeN].v = b;
  tailg[a] = edgeN++;
  return;
}

int r, c;
const int dx [] = {1, 0, -1, 0}, dy [] = {0, 1, 0, -1};
bool check(int x, int y){
  return x >= 0 && x < r && y >= 0 && y < c;
}

char str[66][66];

int main(){

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int i, j, u, v, k, cases = 0;
  while(scanf("%d %d", &r, &c), r+c){
    edgeN = 0;
    n = r*c;
    for (int i = 0; i < n; i++)
    {
      headg[i] = -1;
      tailg[i] = -1;
    }
    for (int i = 0; i < r; i++) scanf("%s", str[i]);
    int cnt = 0;
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if(str[i][j] != '#') continue;
        cnt++;
        for (int k = 0; k <= 3; k++)
        {
          u = i + dx[k], v = j + dy[k];
          if(check(u, v) && str[u][v] == '#') add(i*c+j, u*c+v);
        }
      }
    }
    if(cnt&1){
      printf("Case %d: %s\n", ++cases, 0==1?"Possible":"Impossible");
      continue;
    }
    int total = 0;
    for (int i = 0; i < n; i++) lead[i] = -1;
    while(BFS()){
      i = 0;
      while(i != tail && slic[q[i]] != 2){
        if(DFS(q[i])) total++;
        i++;
      }
    }
    printf("Case %d: %s\n", ++cases, total == cnt?"Possible":"Impossible");
  }

  return 0;
}