//AtCoder DP Competition Frog 2
//https://atcoder.jp/contests/dp
#include<bits/stdc++.h>
 
using namespace std;
const int inf = 1e9+7;


void solve(int cs){
	//write solution here
    int n,k;
    cin>>n>>k;
    int h[n];
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    vector<int> dp(n, inf);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(j+i < n){
                dp[j+i] = min(dp[j+i], dp[i] + abs(h[j+i] - h[i]));
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