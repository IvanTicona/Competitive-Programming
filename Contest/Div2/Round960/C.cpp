#include<bits/stdc++.h>

using namespace std;

int MAD(const vector<int>& arr, int end) {
  unordered_map<int, int> count;
  int mad_value = 0;
  
  for (int i = 0; i <= end; ++i) {
    count[arr[i]]++;
  }
  
  for (const auto& pair : count) {
    if (pair.second > 1) {
      mad_value = max(mad_value, pair.first);
    }
  }
  
  return mad_value;
}

int processArray(vector<int>& a) {
  int n = a.size();
  int sum_result = 0;
  
  while (any_of(a.begin(), a.end(), [](int x) { return x != 0; })) {
    sum_result += accumulate(a.begin(), a.end(), 0);
    
    vector<int> b(n, 0);
    
    for (int i = 0; i < n; ++i) {
      b[i] = MAD(a, i);
    }
    
    a = b;
  }
  
  return sum_result;
}

int main(){

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
      cin>>a[i];
    }
    cout<<processArray(a)<<endl;
  }

  return 0;
}