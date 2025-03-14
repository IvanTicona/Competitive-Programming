#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;
const ll INF = 1e18;

class max_flow
{
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t)
  {
    d.assign(V, -1);
    d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      if (u == t)
        break;
      for (auto &idx : AL[u])
      {
        auto &[v, cap, flow] = EL[idx];
        if ((cap - flow > 0) && (d[v] == -1))
          d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};
      }
    }
    return d[t] != -1;
  }
  ll send_one_flow(int s, int t, ll f = INF)
  {
    if (s == t)
      return f;
    auto &[u, idx] = p[t];
    auto &cap = get<1>(EL[idx]), &flow = get<2>(EL[idx]);
    ll pushed = send_one_flow(s, u, min(f, cap - flow));
    flow += pushed;
    auto &rflow = get<2>(EL[idx ^ 1]);
    rflow -= pushed;
    return pushed;
  }

public:
  max_flow(int initialV) : V(initialV)
  {
    EL.clear();
    AL.assign(V, vi());
  }
  void add_edge(int u, int v, ll w, bool directed = true)
  {
    if (u == v)
      return;
    EL.emplace_back(v, w, 0);
    AL[u].push_back(EL.size() - 1);
    EL.emplace_back(u, directed ? 0 : w, 0);
    AL[v].push_back(EL.size() - 1);
  }
  ll edmonds_karp(int s, int t)
  {
    ll mf = 0;
    while (BFS(s, t))
    {
      ll f = send_one_flow(s, t);
      if (f == 0)
        break;
      mf += f;
    }
    return mf;
  }
};

int main()
{

  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int n, m;
  cin >> n >> m;
  max_flow mf(n);

  for (int i = 0; i < m; i++)
  {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    mf.add_edge(a - 1, b - 1, c);
  }

  cout << mf.edmonds_karp(0, n-1) << endl;

  return 0;
}