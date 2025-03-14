#include <bits/stdc++.h>

using namespace std;

void showHeights(vector<int> &tower) {
  sort(tower.rbegin(), tower.rend());
  for (int &v : tower) cout << v << " ";
  cout << endl;
}

int main() {

  vector<int> boxes(6);
  for (int &height : boxes) cin >> height;
  int t1, t2;
  cin >> t1 >> t2;

  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      for (int k = j + 1; k < 6; k++) {
        int sum1 = boxes[i] + boxes[j] + boxes[k];
        if (sum1 == t1) {
          vector<int> tower1 = {boxes[i], boxes[j], boxes[k]};
          vector<int> remaining;
          for (int l = 0; l < 6; l++) {
            if (l != i && l != j && l != k) remaining.push_back(boxes[l]);
          }
          int sum2 = accumulate(remaining.begin(), remaining.end(), 0);
          if (sum2 == t2) {
            showHeights(tower1);
            showHeights(remaining);
            return 0;
          }
        }
      }
    }
  }

  return 0;
}
