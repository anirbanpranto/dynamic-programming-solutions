//AtCoder DP Competition Frog 2
//https://atcoder.jp/contests/dp
#include<bits/stdc++.h>
 
using namespace std;
const int inf = 1e9+7;


void solve(int cs){
	//write solution here
    vector<vector<int>> cost(8, vector<int> (8, 0));
    vector<vector<int>> dp(8, vector<int> (8, inf));
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            cin>>cost[i][j];
        }
    }

    dp[0][0] = cost[0][0];
    //transitions j+1, i+1, (j+1 & i+1)
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i+1 < 8){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + cost[i+1][j]);
            }
            if(j+1 < 8){
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + cost[i][j+1]);
            }
            if(j+1 < 8 && i+1 < 8){
                dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + cost[i+1][j+1]);
            }
        }
    }
    cout<<dp[7][7]<<endl;
    //cout<<"Case "<<cs<<": "<<pos<<endl;
}
 
int main(){
	freopen("king2.in","r",stdin);
    freopen("king2.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t = 1;
	//cin>>t;
	for(int i = 0; i < t; i++)
	    solve(i+1);
}