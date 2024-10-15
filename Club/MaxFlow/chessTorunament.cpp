#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<ii> Graph;

bool graphExists(vector<int> &a, int n)
{
  vector<ii> graphsEdges;

  priority_queue<ii> pq;

  for (int i = 0; i < n; i++)
  {
    if (a[i] > 0)
      pq.push({a[i], i});
  }

  while (!pq.empty())
  {
    auto [degree, u] = pq.top(); pq.pop();

    if (degree == 0)
      break;

    if (degree > pq.size())
      return false;

    vector<ii> temp;
    for (int i = 0; i < degree; i++)
    {
      auto [degree, v] = pq.top();
      pq.pop();
      graphsEdges.push_back({u, v});
      if (--degree > 0)
        temp.push_back({degree, v});
    }

    for (auto &[degree, v]: temp)
      pq.push({degree, v});
  }

  for (auto &edge: graphsEdges)
  {
    Graph.push_back({edge.first + 1, edge.second + 1});
  }
  return true;
}

int main()
{
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n);
  int total = 0;
  for (int &ai: a)
  {
    cin >> ai;
    total += ai;
  }

  if (total % 2 == 1)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  if (graphExists(a, n))
  {
    cout << Graph.size() << endl;
    for (auto &edge: Graph)
    {
      cout << edge.first << " " << edge.second << endl;
    }
  }
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
