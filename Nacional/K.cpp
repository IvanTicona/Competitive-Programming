#include <bits/stdc++.h>

using namespace std;

// BOTTOM UP
/*int main(){
	
// 	int n, suma, v[110];
// 	bool dp[110][10100];

// 	cin>>n;
// 	suma = 0;
// 	for (int i = 1; i <= n; i++){
// 		cin>>v[i];
// 		suma += v[i];
// 	}
// 	if(suma%2==1){
// 		cout<<"-1"<<endl;
// 		return 0;
// 	}
// 	suma/=2;

// 	for (int j = 1; j <= suma; j++) dp[0][j]=false;

// 	dp[0][0]=true;

// 	for (int i = 1; i <= n; i++){
// 		for (int j = 0; j <= suma; j++){
// 			dp[i][j]=dp[i-1][j];
// 			if(v[i]<=j && dp[i-1][j-v[i]]){
// 				dp[i][j]=true;
// 			}
// 		}
// 	}
// 	if(!dp[n][suma]){
// 		cout<<"-1"<<endl;
// 		return 0;
// 	}
	
// 	vector<int> v1, v2;
// 	int s=suma;
// 	for (int i = n; i > 0; i--){
// 		if(s >= v[i] && dp[i-1][s-v[i]]){
// 			v1.push_back(v[i]);
// 			s-=v[i];
// 		}else{
// 			v2.push_back(v[i]);
// 		}
// 	}

// 	int s1=0, s2=0, prox;
// 	for (int i = 1; i <= n; i++){
// 		if(s1<=s2){
// 			prox = v1.back();
// 			v1.pop_back();
// 			s1+=prox;
// 		}else{
// 			prox = v2.back();
// 			v2.pop_back();
// 			s2+=prox;
// 		}
// 		cout<<prox<<(i==n? "\n":" ");
// 	}

// 	return 0;
// }
*/
//====================================================

// TOP DOWN
int n, suma, v[110];
bool marca[110][10100];
vector<int> v1, v2;

bool dfs(int pos, int s){

	if(marca[pos][s]){
		return false;
	}
	marca[pos][s] = true;
	if(pos == n){
		return s == suma;
	}
	if(dfs(pos+1,s)){
		v2.push_back(v[pos]);
		return true;
	}
	if(s+v[pos]<=suma && dfs(pos+1, s+v[pos])){
		v1.push_back(v[pos]);
		return true;
	}
	return false;
}

int main(){

	cin>>n;
	suma = 0;

	for (int i = 0; i < n; i++){
		cin>>v[i];
		suma += v[i];
	}
	if(suma%2==1){
		cout<<"-1"<<endl;
		return 0;
	}
	suma/=2;

	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= suma; j++){
			marca[i][j] = false;
		}
	}

	if(!dfs(0, 0)){
		cout<<"-1"<<endl;
		return 0;
	}

	int s1=0, s2=0, prox; 
	for (int i = 1; i <= n; i++){
		if(s1<=s2){
			prox = v1.back();
			v1.pop_back();
			s1+=prox;
		}else{
			prox = v2.back();
			v2.pop_back();
			s2+=prox;
		}
		cout<<prox<<(i==n? "\n":" ");
	}

	return 0;
}