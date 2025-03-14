#include <bits/stdc++.h>

using namespace std;

// const int MAX_R = 4;
// const int MAX_C = 4;
// const int dc4[4] = {1, 0, -1, 0};
// const int dr4[4] = {0, 1, 0, -1};
// const int dr8[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// const int dc8[8] = {1, 0, -1, 0, 1, -1, 1, -1};

// bool isValid(int x, int y, int R, int C) {
//   return x >= 0 && x < R && y >= 0 && y < C;
// }

// bool checkPolygon(int R, int C, int p) {
//   if (p == 0) return false;

//   vector<vector<int>> board(R, vector<int>(C, 0));
//   pair<int, int> source = {-1, -1};

//   for (int i = 0; i < R * C; ++i) {
//     if (p & (1 << i)) {
//       int r = i / C, c = i % C;
//       board[r][c] = 1;
//       if (source == make_pair(-1, -1)) {
//         source = {r, c};
//       }
//     }
//   }

//   queue<pair<int, int>> q;
//   vector<vector<bool>> visited(R, vector<bool>(C, false));
//   q.push(source);
//   visited[source.first][source.second] = true;

//   while (!q.empty()) {
//     auto [r, c] = q.front(); q.pop();
//     for (int i = 0; i < 4; ++i) {
//       int nr = r + dr4[i], nc = c + dc4[i];
//       if (isValid(nr, nc, R, C) && !visited[nr][nc] && board[nr][nc]) {
//         q.push({nr, nc});
//         visited[nr][nc] = true;
//       }
//     }
//   }

//   for (int r = 0; r < R; ++r)
//       for (int c = 0; c < C; ++c)
//           if (board[r][c] && !visited[r][c])
//               return false;

//   q = queue<pair<int, int>>();
//   visited = vector<vector<bool>>(R, vector<bool>(C, false));

//   for (int r = 0; r < R; ++r) {
//     if (!board[r][0]) q.push({r, 0});
//     if (!board[r][C - 1]) q.push({r, C - 1});
//   }
//   for (int c = 1; c < C - 1; ++c) {
//     if (!board[0][c]) q.push({0, c});
//     if (!board[R - 1][c]) q.push({R - 1, c});
//   }

//   while (!q.empty()) {
//     auto [r, c] = q.front(); q.pop();
//     visited[r][c] = true;
//     for (int i = 0; i < 8; ++i) {
//       int nr = r + dr8[i], nc = c + dc8[i];
//       if (isValid(nr, nc, R, C) && !visited[nr][nc] && !board[nr][nc]) {
//         q.push({nr, nc});
//         visited[nr][nc] = true;
//       }
//     }
//   }

//   for (int r = 0; r < R; ++r)
//     for (int c = 0; c < C; ++c)
//       if (!board[r][c] && !visited[r][c])
//         return false;

//   return true;
// }

int main() {
  // int answer_matrix[MAX_R][MAX_C] = {0};

  // for (int h = 1; h <= MAX_R; ++h) {
  //   for (int w = 1; w <= MAX_C; ++w) {
  //     for (int p = 1; p < (1 << (h * w)); ++p) {
  //       if (checkPolygon(h, w, p)) {
  //         answer_matrix[h - 1][w - 1]++;
  //       }
  //     }
  //   }
  // }

  int results[4][4] = {
    {1, 3, 6, 10},
    {3, 13, 40, 108},
    {6, 40, 217, 1109},
    {10, 108, 1109, 10977}
  };

  int h, w;
  cin >> h >> w;
  // cout << answer_matrix[h - 1][w - 1] << endl;
  cout << results[h - 1][w - 1] << endl;

  return 0;
}
