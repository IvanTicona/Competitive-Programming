#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> edgesGraph;

// Function that returns true if a simple graph exists and prints the edges
bool graphExistsAndPrintEdges(vector<int> &a, int n)
{
  vector<pair<int, int>> edges; // Store the edges as pairs of vertices

  // Priority queue to keep track of degrees (max heap)
  priority_queue<pair<int, int>> pq;

  // Initialize the priority queue with degrees and their corresponding indices
  for (int i = 0; i < n; i++)
  {
    if (a[i] > 0)
      pq.push({a[i], i});
  }

  // Continue until the queue is empty
  while (!pq.empty())
  {
    // Extract the vertex with the highest degree
    auto [degree, idx] = pq.top();
    pq.pop();

    // If degree is 0, the graph is valid
    if (degree == 0)
      break;

    // If there are not enough vertices to connect, return false
    if (degree > pq.size())
      return false;

    // Collect the next "degree" vertices to connect with the current one
    vector<pair<int, int>> temp;
    for (int i = 0; i < degree; i++)
    {
      auto [nextDegree, nextIdx] = pq.top();
      pq.pop();

      // Create an edge between idx and nextIdx
      edges.push_back({idx, nextIdx});

      // Decrease the degree of the connected vertex and add back to the queue if necessary
      if (--nextDegree > 0)
        temp.push_back({nextDegree, nextIdx});
    }

    // Push all modified vertices back into the priority queue
    for (auto &[nextDegree, nextIdx] : temp)
      pq.push({nextDegree, nextIdx});
  }

  // Print all the edges if the graph is valid
  for (auto &edge : edges)
  {
    edgesGraph.push_back({edge.first + 1, edge.second + 1});
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
  for (int &ai : a)
  {
    cin >> ai;
    total += ai;
  }

  if (total % 2 == 1)
  {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  if (graphExistsAndPrintEdges(a, n))
  {
    cout << edgesGraph.size() << endl;
    for (auto &edge : edgesGraph)
    {
      cout << edge.first << " " << edge.second << endl;
    }
  }
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
