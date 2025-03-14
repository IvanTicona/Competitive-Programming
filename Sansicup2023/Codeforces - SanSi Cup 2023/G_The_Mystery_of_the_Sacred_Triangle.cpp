/*
Competitive Programming
G. The Mystery of the Sacred Triangle
Author: Ivan Ticona
Created: 30/12/2024 01:27 AM
*/
#include<bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define EPS 1e-9
#define MOD 1000000007
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define FORP(i, a, b, c) for(int i = a; i <= b; i += c)
#define RFORP(i, a, b, c) for(int i = a; i >= b; i -= c)
#define F first
#define S second
#define all(x) x.begin(), x.end()
// #define sort(x) sort(all(x))
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define rv(x) for(auto &i: x) cin >> i
#define includes(x, y) x.find(y) != x.end()
#define fill(x, y) memset(x, y, sizeof(x))
#define mxe(x) *max_element(all(x))
#define mne(x) *min_element(all(x))

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<pll> vpll;

struct Pt {
  double x, y;
};

double interpY(const Pt &A, const Pt &B, double x) {
  return A.y + (B.y - A.y) * ( (x - A.x) / (B.x - A.x) );
}

double areaTramoLineal(double xL, double xR, double yL, double yR) {
  return 0.5 * (yL + yR) * (xR - xL);
}

void solve(){
  Pt p[3];
  for(auto & i : p){
    cin >> i.x >> i.y;
  }
  sort(p, p+3, [&](const Pt &A, const Pt &B){
      return A.x < B.x;
  });

  Pt A = p[0], B = p[1], C = p[2];
  double x1 = A.x, x2 = B.x, x3 = C.x;

  auto fAC = [&](double x){ return interpY(A,C,x); };
  auto fAB = [&](double x){ return interpY(A,B,x); };
  auto fBC = [&](double x){ return interpY(B,C,x); };

  auto areaBajoMax2 = [&](double L, double R, const function<double(double)>& f1, const function<double(double)>& f2){
    double yL1 = f1(L), yL2 = f2(L);
    double yR1 = f1(R), yR2 = f2(R);

    double dL = yL1 - yL2;
    double dR = yR1 - yR2;

    auto areaMaxNoCruce = [&](double l, double r, double yl1, double yr1, double yl2, double yr2){
        double area;
        if(yl1 >= yl2 && yr1 >= yr2){
            area = areaTramoLineal(l, r, yl1, yr1);
        } else {
            area = areaTramoLineal(l, r, yl2, yr2);
        }
        return area;
    };

    if(dL * dR >= 0){
        return areaMaxNoCruce(L, R, yL1, yR1, yL2, yR2);
    }
    double t = -dL/(dR - dL);
    double xM = L + t*(R - L);
    double yM1 = f1(xM), yM2 = f2(xM);
    double areaLeft = areaMaxNoCruce(L, xM,
                                     yL1, yM1,
                                     yL2, yM2);
    double areaRight = areaMaxNoCruce(xM, R,
                                      yM1, yR1,
                                      yM2, yR2);
    return areaLeft + areaRight;
  };

  double totalArea = 0.0;
  if(x2 > x1) {
      totalArea += areaBajoMax2(x1, x2, fAC, fAB);
  }
  if(x3 > x2) {
      totalArea += areaBajoMax2(x2, x3, fAC, fBC);
  }

  cout << llround(totalArea) << '\n';
}

int main(){

  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}