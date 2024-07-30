#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main() {

  string line;
  while (getline(cin, line)) {
    if (line.empty()) continue;

    stringstream ss(line);
    vector<ll> nums;
    long long num;

    while (ss >> num) {
      nums.push_back(num);
    }
    ll res=1;
    for(ll n: nums){
      ll r = gcd(res,n);
      res *= n;
      res /= r;
    }
    cout<<res<<endl;
  }

  return 0;
}