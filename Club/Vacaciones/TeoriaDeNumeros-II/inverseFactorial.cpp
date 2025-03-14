#include <bits/stdc++.h>

using namespace std;


int main(){
  
  string factorial;
  cin>>factorial;
  cout<<factorial;

  int num=0;
  while (num!=factorial[0]-'0'){
    
  }

  return 0;
}



// string f;
//   cin >> f;
//   int d = f.length();
//   if (d < 10){
//     int i = 1;
//     long long j = 1; // `j` debe ser long long para manejar factoriales grandes
//     int k = stoi(f);
//     while (j < k){
//       i += 1;
//       j *= i;
//     }
//     cout << i << endl;
//   }else{
//     double x = 0.0; // `x` debe ser double para manejar sumas de logaritmos
//     int z = 0;
//     while (x < d - 1){
//       z += 1;
//       x += log10(z);
//     }
//     cout << z << endl;
//   }