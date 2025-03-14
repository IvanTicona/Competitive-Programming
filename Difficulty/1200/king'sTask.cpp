#include<bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin>>n;
  int sorted[2*n];
  int count=0;
  int max=2*n;

  int size = sizeof(sorted)/sizeof(sorted[0]);
  for (int i = 0; i < 2*n; i++){
    cin>>sorted[i];
  }
  bool noSorted=true;

  while (noSorted){
    
    for (int i = 0; i < 2*n; i++){
      if(sorted[i] != i+1 ) break;
      if(i==2*n-1) noSorted=false;
    }
    if(!noSorted) break;

    //Regla 1
    for (int i = 0; i < size; i+=2){
      swap(sorted[i],sorted[i+1]);
    }
    
    for (int i = 0; i < 2*n; i++){
      if(sorted[i] != i+1 ) break;
      if(i==2*n-1) noSorted=false;
    }

    count++;
    if(!noSorted) break;

    //Regla 2
    for (int i = 0,j=n; i < n; i++,j++){
      swap(sorted[i],sorted[j]);
    }

    for (int i = 0; i < 2*n; i++){
      if(sorted[i] != i+1 ) break;
      if(i==2*n-1) noSorted=false;
    }
    count++;

    if(count>max){
      count=-1;
      noSorted=false;
    }
  }
  int comp;
  if (n%2==1){
    comp = (2*n) - count;
  }else{
    comp = 4-count;
  }
  
  cout<<min(comp,count);

  return 0;
}