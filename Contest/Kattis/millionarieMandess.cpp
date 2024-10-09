#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int inf = 1 << 30;

vi dx = {1, -1, 0, 0};
vi dy = {0, 0, 1, -1};

int n, m;

bool inrange(int nextx, int nexty){
  return nextx >= 0 && nexty >= 0 && nextx < n && nexty < m;
}

struct state{
  int x;
  int y;
  int val;
};

bool operator<(const state &s1, const state &s2){
  if (s1.val == s2.val){
    if (s1.x == s2.x){
      return s1.y < s2.y;
    }
    return s1.x < s2.x;
  }
  return s1.val > s2.val;
}

void fast(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

int main(){

  fast();

  cin >> n >> m;

  vvi val(n, vi(m));
  vvi vis(n, vi(m, false));
  vvi best(n, vi(m, inf));

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> val[i][j];
    }
  }

  best[0][0] = 0;

  priority_queue<state> q;
  q.push({0, 0, 0});

  while (!q.empty()){
    int currx = q.top().x;
    int curry = q.top().y;
    q.pop();

    if (vis[currx][curry]){
      continue;
    }
    vis[currx][curry] = true;

    for (int i = 0; i < 4; i++){
      int nextx = currx + dx[i];
      int nexty = curry + dy[i];

      if (!inrange(nextx, nexty)){
        continue;
      }

      int nextval = max(0, val[nextx][nexty] - val[currx][curry]);
      nextval = max(nextval, best[currx][curry]);

      if (best[nextx][nexty] > nextval){
        best[nextx][nexty] = nextval;
        q.push({nextx, nexty, nextval});
      }
    }
  }

  cout << best[n - 1][m - 1] << endl;

  return 0;
}