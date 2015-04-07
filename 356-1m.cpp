//SRM356DIV1-550 MarriageProblemRevised
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
int me[15],wo[15];
int mea[4200],woa[4200],bitc[4200];
class MarriageProblemRevised{
	public:
	int MarriageProblemRevised::neededMarriages(vector <string> a){
		int n=a.size(),m=a[0].size(),i,j,k,out=1000;
		memset(me,0,sizeof(me));memset(wo,0,sizeof(wo));
		memset(mea,0,sizeof(mea));memset(woa,0,sizeof(woa));
		for(i=0;i<n;i++) for(j=0;j<m;j++){
			if(a[i][j]=='1'){me[i]+=(1<<j);wo[j]+=(1<<i);}
		}
		for(i=0;i<n;i++) if(me[i]==0){return -1;}for(i=0;i<m;i++) if(wo[i]==0){return -1;}
		for(i=0;i<(1<<n);i++) for(j=0;j<n;j++) if(i&(1<<j)){mea[i]|=me[j];}
		for(i=0;i<(1<<m);i++) for(j=0;j<m;j++) if(i&(1<<j)){woa[i]|=wo[j];}
		for(i=0;i<(1<<12);i++) bitc[i]=__builtin_popcount(i);
		for(i=0;i<(1<<n);i++) for(j=0;j<(1<<m);j++){
//			cout<<i<<' '<<j<<' '<<mea[i]<<' '<<woa[j]<<endl;
			if((i|woa[j])==(1<<n)-1 && (j|mea[i])==(1<<m)-1) out<?=bitc[i]+bitc[j];
		}
		return out;
	}
};
