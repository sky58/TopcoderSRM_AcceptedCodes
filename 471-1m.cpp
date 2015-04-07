//SRM471DIV1-500 ThirteenHard
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
int ke[4500][15];
int dp[17][28][4500];
int inf=1000000;
int dec(char a){
	if(a<='Z' && a>='A') return (a-'A')+1;return (a-'a')+27;
}
int cal(int a,int b){
	if(b==0) return ke[a][b]=inf;
	int i,ret=0;
	for(i=0;i<12;i++){
		if(a&(1<<i)){
			if((i+b+1)%13==0) return ke[a][b]=inf;
			ret+=(1<<((i+b)%13));
		}
	}
	ret+=(1<<(b-1));
	return ke[a][b]=ret;
}
class ThirteenHard{
	public:
	int ThirteenHard::calcTime(vector <string> a){
		int i,j,k,l,n=a.size(),out=inf;
		for(i=0;i<(1<<12);i++) for(j=0;j<13;j++) cal(i,j);
//		cout<<ke[3][11]<<endl;
		for(i=0;i<28;i++) for(j=0;j<17;j++) for(k=0;k<4500;k++) dp[j][i][k]=inf;dp[0][0][0]=0;
		for(i=0;i<15;i++) for(j=0;j<n;j++) for(k=0;k<(1<<12);k++){
			if(dp[i][j][k]>=inf) continue;
//			cout<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
			for(l=0;l<n;l++){
				if(a[j][l]=='#') continue;
				int x=dec(a[j][l]),y=x%13,z=ke[k][y];
				if(z>=inf) continue;dp[i+1][l][z]<?=dp[i][j][k]+x;
			}
		}
		for(i=0;i<16;i++) for(j=0;j<(1<<12);j++) out<?=dp[i][n-1][j];
		if(out>=inf) return -1;return out;
	}
};
