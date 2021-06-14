/*
Saints Petersburg State University DP problemset
C. Knight
https://codeforces.com/gym/100135/attachments
*/
#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int cs){
	//write solution here
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i+1 < n && j+2 < m){
                dp[i+1][j+2] += dp[i][j];
            }
            if(i+2 < n && j+1 < m){
                dp[i+2][j+1] += dp[i][j];
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    //cout<<"Case "<<cs<<": "<<pos<<endl;
}
 
int main(){
	freopen("knight.in","r",stdin);
    freopen("knight.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t = 1;
	//cin>>t;
	for(int i = 0; i < t; i++)
	    solve(i+1);
}