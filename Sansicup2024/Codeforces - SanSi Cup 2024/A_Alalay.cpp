/*
Competitive Programming
A. Alalay
Author: Ivan Ticona
Created: 31/12/2024 07:00 PM
*/
#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x, y;
    int id;
};

long long cross(const Point &p1, const Point &p2, const Point &p3){
    return (p2.x - p1.x) * (p3.y - p1.y)
         - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> buildHull(vector<Point> pts){
    sort(pts.begin(), pts.end(), [](auto &a, auto &b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Point> lower;
    for(auto &p : pts){
        while(lower.size() >= 2
           && cross(lower[lower.size()-2], lower[lower.size()-1], p) <= 0LL){
            lower.pop_back();
        }
        lower.push_back(p);
    }

    vector<Point> upper;
    for(int i = (int)pts.size()-1; i >= 0; i--){
        auto &p = pts[i];
        while(upper.size() >= 2
           && cross(upper[upper.size()-2], upper[upper.size()-1], p) <= 0LL){
            upper.pop_back();
        }
        upper.push_back(p);
    }

    lower.pop_back();
    upper.pop_back();

    vector<Point> hull;
    for(auto &p : lower) hull.push_back(p);
    for(auto &p : upper) hull.push_back(p);

    return hull;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<Point> pts(n);

        for(int i = 0; i < n; i++){
            cin >> pts[i].x >> pts[i].y;
            pts[i].id = i;
        }

        vector<Point> hull = buildHull(pts);

        vector<int> hullIDs;
        hullIDs.reserve(hull.size());
        for(auto &p : hull) hullIDs.push_back(p.id);

        vector<int> givenIDs(n);
        for(int i = 0; i < n; i++){
            givenIDs[i] = i;
        }

        auto compareWithOffset = [&](int off){
            int diffs = 0;
            vector<int> posDif;
            for(int i = 0; i < n; i++){
                int idxHull = (off + i) % n;
                if(hullIDs[idxHull] != givenIDs[i]){
                    diffs++;
                    posDif.push_back(i);
                }
                if(diffs > 2) break;
            }
            return make_pair(diffs, posDif);
        };

        int bestOff = -1;
        vector<int> mismatch;

        for(int startTry = 0; startTry < min(n, 3); startTry++){
            for(int j = 0; j < n; j++){
                if(hullIDs[j] == givenIDs[startTry]){
                    auto [diffs, posDif] = compareWithOffset((j - startTry + n) % n);
                    if(diffs <= 2){
                        bestOff = (j - startTry + n) % n;
                        mismatch = posDif;
                        break;
                    }
                }
            }
            if(bestOff != -1) break;
        }

        int iAns = mismatch[0];
        int jAns = mismatch[1];
        if(iAns > jAns) swap(iAns, jAns);

        cout << iAns+1 << " " << jAns+1 << "\n";
    }

    return 0;
}
