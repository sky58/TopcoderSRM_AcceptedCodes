//SRM294DIV1-500 Palindromist
#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<deque>
using namespace std;
#define pb push_back
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
bool dp[110];
vector <string> b;map<string,int> memo;
string cal(string a){
	int i,j,n=a.size(),t=0;string ret="";
//	cout<<a<<endl;
	memset(dp,false,sizeof(dp));dp[n]=true;
	for(i=n;i>0;i--) for(j=0;j<b.size();j++){
		if(!dp[i]) continue;
		int s=i-b[j].size();
		if(s<0) continue;
		if(b[j]==a.substr(s,b[j].size())) dp[s]=true;
	}
//	for(i=0;i<=n;i++){if(dp[i]) cout<<i<<endl;}
	if(!dp[0]) return "";
	while(1){
//		cout<<t<<endl;
		int f=0;
		for(i=t+1;i<=n && f<1;i++){
			if(dp[i] && memo[a.substr(t,i-t)]){
				ret+=a.substr(t,i-t);t=i;f=1;
				if(t<n) ret+=" ";else return ret;
			}
		}
	}
}
class Palindromist{
	public:
	string Palindromist::palindrome(string a,vector <string> B){
		string c=a;reverse(c.begin(),c.end());b=B;
		for(int i=0;i<b.size();i++) memo[b[i]]=1;
		string d=cal(a+c),e=cal(a+c.substr(1,c.size()-1));
		if(d=="") return e;if(e=="") return d;
		if(d<e) return d;return e;
	}
};
