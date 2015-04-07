//SRM279DIV1-575 DivisiblePermutations
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
lint dp[(1<<15)+10][55];
int ka[12];
class DivisiblePermutations{
	public:
	long long DivisiblePermutations::count(string a,int b){
		int i,j,k,n=a.size();memset(ka,0,sizeof(ka));
		for(i=0;i<(1<<15)+10;i++) for(j=0;j<55;j++) dp[i][j]=0;dp[0][0]=1;
		for(i=0;i<n;i++) ka[(a[i]-'0')]++;
		for(i=0;i<(1<<n);i++) for(j=0;j<b;j++){
			if(dp[i][j]<=0) continue;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			for(k=0;k<n;k++){
				if(i&(1<<k)) continue;dp[i+(1<<k)][(j*10+(a[k]-'0'))%b]+=dp[i][j];
			}
		}
		for(i=1;i<10;i++) for(j=1;j<=ka[i];j++) dp[(1<<n)-1][0]/=j;
		return dp[(1<<n)-1][0];
	}
};
