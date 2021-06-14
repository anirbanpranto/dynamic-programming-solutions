/*
Saints Petersburg State University DP problemset
E. Slalom
https://codeforces.com/gym/100135/attachments
*/
#include<bits/stdc++.h>
 
using namespace std;
const int inf = -1e9+7;


void solve(int cs){
	//write solution here
    int n;
    cin>>n;
    vector<vector<int>> score(n);
    vector<vector<int>> dp(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            int x;
            cin>>x;
            score[i].push_back(x);
            dp[i].push_back(inf);
        }
    }

    dp[0][0] = score[0][0];

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(i+1 < n){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + score[i+1][j]);
            }
            if(i+1 < n && j+1 <= n){
                 dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + score[i+1][j+1]);
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[n-1][i]);
    }
    cout<<ans<<endl;
    //cout<<"Case "<<cs<<": "<<pos<<endl;
}
 
int main(){
	//freopen("slalom.in","r",stdin);
    //freopen("slalom.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t = 1;
	//cin>>t;
	for(int i = 0; i < t; i++)
	    solve(i+1);
}