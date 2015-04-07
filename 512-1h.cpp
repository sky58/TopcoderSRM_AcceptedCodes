//SRM512DIV1-1024 PickAndDelete
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
lint dp[210][210],co[210][210],po[210][210];
vector <lint> re,di;
class PickAndDelete{
	public:
	int PickAndDelete::count(vector <string> a){
		string b="";int i,j,k,n;lint mo=1000000007;
		for(i=0;i<a.size();i++) b+=a[i];
		istringstream sin(b);
		while(sin>>n) re.pb(n);n=re.size();sort(re.begin(),re.end());
		di.pb(re[0]);for(i=1;i<n;i++) di.pb(re[i]-re[i-1]);reverse(di.begin(),di.end());
		for(i=0;i<=n;i++){
			po[i][0]=1;co[i][0]=co[i][i]=1;dp[i][0]=0;
			for(j=1;j<=n;j++){
				po[i][j]=(po[i][j-1]*di[i])%mo;dp[i][j]=0;
				if(j<i) co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
			}
		}
		dp[0][0]=1;//cout<<di[0]<<di[1]<<di[2]<<endl;
		for(i=0;i<n;i++) for(j=0;j<=i;j++){
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
			for(k=0;j+k<=i+1;k++){
				dp[i+1][j+k]=(dp[i+1][j+k]+((dp[i][j]*po[i][k])%mo)*co[j+k][k])%mo;
			}
		}
		return (int)(dp[n][n]%mo);
	}
};
