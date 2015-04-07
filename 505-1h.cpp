//SRM505DIV1-1000 PerfectSequences2
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
lint dp[52][210][210];
int co=103;
class PerfectSequences2{
	public:
	long long PerfectSequences2::minimumMoves(vector <int> a){
		lint inf=1000000000000000LL,out=inf;int i,j,k,l,n=a.size();
		for(i=0;i<n;i++){
			lint su=0,sum=0;int pl=0,mi=0,ze=0;vector <int> v;
			for(j=0;j<n;j++){
				if(i==j) continue;
				if(a[j]>0) pl++;else if(a[j]<0) mi++;else ze++;su+=a[j];v.pb(a[j]);
			}
			out<?=abs(su)+abs(a[i]);//cout<<su<<' '<<abs(su)<<' '<<a[i]<<' '<<abs(a[i])<<endl;
			if(n%4==1){
				sort(v.begin(),v.end());
				for(j=0;j<n-1;j++){if(j<n/2) sum+=abs(v[j]+1);else sum+=abs(v[j]-1);}out<?=sum;
			}
		}
		for(i=0;i<52;i++) for(j=0;j<210;j++) for(k=0;k<210;k++) dp[i][j][k]=inf;dp[0][co][co+1]=0;
		for(i=0;i<n;i++) for(j=0;j<210;j++) for(k=0;k<210;k++){
			if(dp[i][j][k]>=inf) continue;
			for(l=-50;l<=50;l++){
				int x=(j-co)+l+co,y=(k-co)*l+co;
				if(x<0 || x>205 || y<0 || y>205) continue;dp[i+1][x][y]<?=dp[i][j][k]+abs(a[i]-l);
			}
		}
		for(i=0;i<210;i++) out<?=dp[n][i][i];return out;
	}
};
