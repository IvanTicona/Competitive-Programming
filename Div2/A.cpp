#include<bits/stdc++.h>

using namespace std;

int main(){

  int t, n;
  string pass;
  cin >> t;
  while (t--){
    cin >> n >> pass;
    bool invalid = true;
    for (int i = 0; i < n-1; i++){
      if((pass[i]>= 'a' && pass[i] <= 'z')||(pass[i] >= '0' && pass[i] <= '9')){
        if(pass[i] <= pass[i+1]){
          invalid = false;
        }else{
          invalid = true;
          break;
        }
      }else{
        break;
      }
    }
    invalid ? cout << "NO" << endl : cout << "YES" << endl;
  }

  return 0;
}

// int main()
// {
//   int t, n;
//   string pass;
//   cin >> t;
//   while (t--)
//   {
//     cin >> n >> pass;
//     bool invalid = false;

//     for (int i = 0; i < n - 1; ++i)
//     {
//       if (isalpha(pass[i]) && isdigit(pass[i + 1]))
//       {
//         invalid = true;
//         break;
//       }
//       if (pass[i] > pass[i + 1])
//       {
//         invalid = true;
//         break;
//       }
//     }
//     if (isdigit(pass[n - 1]))
//     {
//       for (int i = 0; i < n; ++i)
//       {
//         if (isalpha(pass[i]))
//         {
//           invalid = true;
//           break;
//         }
//       }
//     }
//     if (!invalid)
//     {
//       cout << "YES" << endl;
//     }
//     else
//     {
//       cout << "NO" << endl;
//     }
//   }

//   return 0;
// }
