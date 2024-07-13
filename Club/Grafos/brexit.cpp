#include <bits/stdc++.h>
using namespace std;

vector<int> countries[200010];
int degree[200010];
int leftPartners[200010];
bool hasLeft[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int C, P, X, L;
    cin >> C >> P >> X >> L;
    
    for (int i = 0; i < P; i++) {
        int A, B;
        cin >> A >> B;
        countries[A].push_back(B);
        countries[B].push_back(A);
        degree[A]++;
        degree[B]++;
    }

    queue<int> q;
    q.push(L);
    hasLeft[L] = true;

    while (!q.empty()) {
        int na = q.front();
        q.pop();

        for (auto &neighbor : countries[na]) {
            leftPartners[neighbor]++;
            if (!hasLeft[neighbor] && leftPartners[neighbor] * 2 >= degree[neighbor]) {
                hasLeft[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    if (hasLeft[X]) {
        cout << "leave" << endl;
    } else {
        cout << "stay" << endl;
    }

    return 0;
}
