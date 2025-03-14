#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct State {
  int x, y, maxLadder;
  bool operator>(const State& other) const {
    return maxLadder > other.maxLadder;
  }
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int findShortestLadder(vector<vector<int>>& grid, int n, int m) {

  priority_queue<State, vector<State>, greater<State>> pq;
  vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

  pq.push({0, 0, 0});
  dist[0][0] = 0;

  while (!pq.empty()) {
    auto [x, y, maxLadder] = pq.top();
    pq.pop();

    if (x == n - 1 && y == m - 1) return maxLadder;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        int requiredLadder = max(0, grid[nx][ny] - grid[x][y]);
        int newMaxLadder = max(maxLadder, requiredLadder);

        if (newMaxLadder < dist[nx][ny]) {
          dist[nx][ny] = newMaxLadder;
          pq.push({nx, ny, newMaxLadder});
        }
      }
    }
  }
  return -1;
}

int main() {

  int n, m;
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> grid[i][j];
    }
  }

  cout << findShortestLadder(grid, n, m) << endl;

  return 0;
}
