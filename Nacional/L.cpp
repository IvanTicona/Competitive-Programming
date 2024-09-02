#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vi lexicography(vi &nums){

  vi result(nums.size(), 0);

  for (int bit = 0; bit < 32; bit++){

    int count = 0, i = 0;

    for (int num: nums){
      if (num & (1 << bit)){
        count++;
      }
    }

    while (count>0){
      result[i] |= (1 << bit);
      count--;
      i++;
    }
  }

  return result;
}

int main(){
  
  int N; cin>>N;
  vi nums(N);
  for (int &v: nums) cin>>v;

  vi result = lexicography(nums);
  for (int num: result) cout<<num<<" ";

  return 0;
}