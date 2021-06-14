/*
Saints Petersburg State University DP problemset
B. Rabbits
https://codeforces.com/gym/100135/attachments
*/
#include<bits/stdc++.h>
 
using namespace std;
 
void solve(int cs){
	//write solution here
    int n;
    cin>>n;
    string s;
    cin>>s;
    int score[n];
    for(int i = 0; i < n; i++){
        if(s[i]=='w') score[i] = -1;
        if(s[i]=='"') score[i] = 1;
        if(s[i]=='.') score[i] = 0;
    }
    vector<int> dp(n,-1);
    dp[0] = score[0];
    for(int i = 0; i < n; i++){
        for(int j : {i+1, i+3, i+5}){
            if(j < n && score[j] != -1 && dp[i] != -1){
                dp[j] = max(dp[j], dp[i] + score[j]);
            }
        }
    }
    cout<<dp[n-1]<<endl;
}
 
int main(){
	freopen("lepus.in","r",stdin);
    freopen("lepus.out","w",stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t = 1;
	//cin>>t;
	for(int i = 0; i < t; i++)
	    solve(i+1);
}