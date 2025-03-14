#include<bits/stdc++.h>

using namespace std;

void move(queue<int> &deck, int card){
  deck.push(card);
  for (int i = 0; i < card; i++){
    int aux = deck.front();
    deck.pop();
    deck.push(aux);
  }
}

int main(){

  int t;
  cin>>t;
  while (t--){
    int n;
    cin>>n;
    vector<int> cards(n);
    for (int i = 1; i <= n; i++){cards[i-1]=i;}
    
    queue<int> deck;
    for (int i = n-1; i >=0; i--){
      int card = cards[i];
      move(deck, card);
    }
    vector<int> order;
    while (!deck.empty()){
      order.push_back(deck.front());
      deck.pop();
    }
    for (int i = n-1; i >= 0; i--){
      cout<<order[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}