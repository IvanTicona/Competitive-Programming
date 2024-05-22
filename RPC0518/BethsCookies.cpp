#include<bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)

using namespace std;


string postfijo(string infijo){

  string postFijo;
  stack<char> pila;
  
  for (int i = 0; i < infijo.size(); i++){
    
    if(infijo[i] == '1') postFijo+="1"; //✅

    else if(infijo[i] == '(') pila.push('('); //✅
    
    else if(infijo[i] == '+'){
      while (pila.top() != '('){
        postFijo+=pila.top();
        pila.pop();
      }
      pila.push('+');
    }
    
    else if(infijo[i] == '*') pila.push('*');
    
    else if(infijo[i] == ')'){
      while (pila.top() != '('){
        postFijo+=pila.top();
        pila.pop();
      }
      pila.pop();
    }
  }

  while (!pila.empty()){
    postFijo+=pila.top();
    pila.pop();
  }

  return postFijo;
}

int main(){

    input;

    int w;
    cin>>w;
    while (w--){
    

    int n;
    string brackets, exp, infijo;
    
    cin>>n>>brackets;
    for (int i = 0; i < brackets.size(); i++){
      exp+=brackets[i];
      if(brackets[i]=='(' && brackets[i+1]==')'){ 
        exp+="1";
      } else if(brackets[i]==')' && brackets[i+1]=='('){
        exp+="*";
      } else if(brackets[i]==')' && brackets[i+1]==')'){
        exp+="+1";
      }
    }
    for (int i = 0; i < exp.size(); i++){
      if(exp[i] == '(' && exp[i+2] ==')' || exp[i-2] == '(' && exp[i] ==')') continue;
      infijo+=exp[i];
    }
    //infijo

    cout<<"INFIJO: "<<infijo<<endl;
    cout<<"POSTFIJO: "<<postfijo(infijo)<<endl;
    cout<<endl;
    }
    

  return 0;
}