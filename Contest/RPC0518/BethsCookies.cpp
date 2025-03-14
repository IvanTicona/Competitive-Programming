#include<bits/stdc++.h>

using namespace std;

int precedencia(char op) {
    if (op == '*')
        return 2;
    if (op == '+')
        return 1;
    return 0;
}

string shuntingYard(const string &exp) {
    stack<char> operadores;
    string salida;

    for (char ch : exp) {
        if (ch == '1') {
            salida += ch;
        } else if (ch == '(') {
            operadores.push(ch);
        } else if (ch == ')') {
            while (!operadores.empty() && operadores.top() != '(') {
                salida += operadores.top();
                operadores.pop();
            }
            if (!operadores.empty() && operadores.top() == '(') {
                operadores.pop();
            }
        } else if (ch == '*' || ch == '+') {
            while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(ch)) {
                salida += operadores.top();
                operadores.pop();
            }
            operadores.push(ch);
        }
    }

    while (!operadores.empty()) {
        salida += operadores.top();
        operadores.pop();
    }

    return salida;
}

int evaluarPostfija(const string &exp) {
    stack<int> pila;

    for (char ch : exp) {
        if (ch == '1') {
            pila.push(1);
        } else if (ch == '*' || ch == '+') {
            int op2 = pila.top();
            pila.pop();
            int op1 = pila.top();
            pila.pop();

            if (ch == '*') {
                pila.push(op1 * op2);
            } else if (ch == '+') {
                pila.push(op1 + op2);
            }
        }
    }

    return pila.top();
}

int main(){

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

    cout<<evaluarPostfija(shuntingYard(infijo))<<endl;

  return 0;
}