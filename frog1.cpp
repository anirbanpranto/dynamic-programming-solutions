//AtCoder DP Competition Frog 1
//https://atcoder.jp/contests/dp
#include<bits/stdc++.h>
 
using namespace std;

const int inf = 1e9+7;

void solve(int cs){
	//write solution here
    int n;
    cin>>n;
    int height[n];
    vector<int> dp(n, inf);
    dp[0] = 0; 
    for(int i = 0; i < n; i++){
        cin>>height[i];
    }
    
    for(int i = 0; i < n; i++){
        for(int j : {i+1, i+2}){
            if(j < n){
                dp[j] = min(dp[j], dp[i] + abs(height[i] - height[j]));
            }
        }
    }
    cout<<dp[n-1]<<endl;
    //cout<<"Case "<<cs<<": "<<pos<<endl;
}
 
int main(){
	//freopen("file.in","r",stdin);
    //freopen("file.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t = 1;
	//cin>>t;
	for(int i = 0; i < t; i++)
	    solve(i+1);
}