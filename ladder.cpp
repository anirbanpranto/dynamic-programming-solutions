/*
Saints Petersburg State University DP problemset
A. Ladder
https://codeforces.com/gym/100135/attachments
*/
#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const ll inf = -1e9+7;
 
void solve(int cs){
	//write solution here
    int n;
    cin>>n;
    int num[n+1];
    for(int i = 1; i <= n; i++){
        cin>>num[i];
    }
    vector<int> dp(n+1, inf);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j : {i+1, i+2}){
            if(j<=n){
                dp[j] = max(dp[j], dp[i] + num[j]);
            }
        }
    }
    cout<<dp[n]<<endl;
    //cout<<"Case "<<cs<<": "<<pos<<endl;
}

int main(){
	freopen("ladder.in","r",stdin);
    freopen("ladder.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t = 1;
	//cin>>t;
	for(int i = 0; i < t; i++)
	    solve(i+1);
}