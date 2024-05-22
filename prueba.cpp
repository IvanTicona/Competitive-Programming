#include<bits/stdc++.h>

using namespace std;

int main(){

    string input = "(((1)*((1)*(1)+1)+1)+1)";
    stack<char> pila;
    
    for (int i = 0; i < input.size(); i++){
      if(input[i] != '1'){
        pila.push(input[i]);
      }
    }
    for(int i = 0; i < input.size(); i++){
      if(input[i] != ')' && input[i] != '(' && input[i] != '+' && input[i] != '*'){
        pila.push(input[i]);
      }
    }
    
    while(!pila.empty()){
      cout<<pila.top()<<" ";
      pila.pop();
    }

  return 0;
}