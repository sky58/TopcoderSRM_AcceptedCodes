//SRM472DIV1-600 TwoSidedCards
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
bool sumi[55];lint con[55][55];lint mo=1000000007;
class TwoSidedCards{
	public:
	int TwoSidedCards::theCount(vector <int> a,vector <int> b){
		lint out=1;vector <pint> c;int n=a.size(),i,j,k;vector <int> re;
		memset(sumi,false,sizeof(sumi));
		for(i=0;i<n;i++) c.pb(mp(a[i],b[i]));sort(c.begin(),c.end());
		for(i=0;i<55;i++) for(j=0;j<55;j++) con[i][j]=0;con[0][0]=1;
		for(i=1;i<55;i++) for(j=0;j<=i;j++){
			con[i][j]+=con[i-1][j];if(j>0) con[i][j]+=con[i-1][j-1];con[i][j]%=mo;
		}
		for(i=0;i<n;i++){
			if(sumi[i]) continue;
			lint kei=0;int ka=0;
			for(int it=i;!sumi[it];it=c[it].se-1){ka++;sumi[it]=true;}
			for(j=0;j*2<=ka;j++){
				if(j>0){
					lint t=1;for(k=0;k<j;k++) t=(t*con[ka-2*k][2])%mo;for(k=ka-2*j;k>0;k--) t=(t*k)%mo;kei+=(con[ka][j*2]*2*t)%mo;
				}
				else{
					lint t=1;for(k=ka;k>0;k--) t=(t*k)%mo;kei+=con[ka][j]*t;kei%=mo;
				}
//				cout<<ka<<' '<<j<<' '<<kei<<endl;
			}
			out=(out*kei)%mo;re.pb(ka);
		}
		for(i=0;i<re.size();i++){out*=con[n][re[i]];out%=mo;n-=re[i];}
		return out;
	}
};
