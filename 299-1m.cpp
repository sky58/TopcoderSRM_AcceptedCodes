//SRM299DIV1-550 PalindromePartition
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
bool ka[2550][2550];int dp[2550];
class PalindromePartition{
	public:
	int PalindromePartition::partition(vector <string> a){
		int i,j,n;string b="";
		memset(ka,false,sizeof(ka));
		for(i=0;i<a.size();i++) b+=a[i];n=b.size();
		for(i=0;i<n;i++){ka[i][i]=true;ka[i][i+1]=true;}
		for(j=2;j<=n;j++) for(i=0;i<n && i+j<=n;i++){
			if(b[i]==b[i+j-1] && ka[i+1][i+j-1]) ka[i][i+j]=true;
//			if(ka[i][i+j]) cout<<i<<' '<<i+j<<endl;
		}
		for(i=0;i<2550;i++) dp[i]=10000;dp[0]=0;
		for(i=0;i<n;i++) for(j=i+1;j<=n;j++){if(ka[i][j]) dp[j]<?=dp[i]+1;}return dp[n];
	}
};
