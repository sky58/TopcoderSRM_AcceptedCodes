//SRM472DIV1-900 ColorfulTiles
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
string de="BGRY";
class ColorfulTiles{
	public:
	int ColorfulTiles::theCount(vector <string> a,int b){
		lint out=0,mo=1000000007;int n=a.size(),m=a[0].size(),i,j,k,l;vector <int> cl;
		if(n<2 || m<2){
			string s="";
			if(n<2) s=a[0];else{for(i=0;i<n;i++) s+=a[i][0];}
			lint dp[55][5][55];for(i=0;i<55;i++) for(j=0;j<5;j++) for(k=0;k<55;k++) dp[i][j][k]=0;dp[0][4][0]=1;
			for(i=0;i<s.size();i++) for(j=0;j<5;j++) for(k=0;k<55;k++) for(l=0;l<4;l++){
				if(j==l) continue;
				if(de[l]==s[i]) dp[i+1][l][k]=(dp[i+1][l][k]+dp[i][j][k])%mo;
				else{dp[i+1][l][k+1]+=dp[i][j][k];dp[i+1][l][k+1]%=mo;}
			}
			for(i=0;i<4;i++) for(j=0;j<=b;j++) out=(out+dp[s.size()][i][j])%mo;return out;
		}
		lint dp[55][2560];
		for(i=0;i<3;i++) for(j=i+1;j<4;j++){
			vector <vector <int> > r;r.pb(cl);r.pb(cl);r[0].pb(i);r[0].pb(j);
			for(k=0;k<4;k++){if(i!=k && j!=k) r[1].pb(k);}
			for(k=0;k<55;k++) for(l=0;l<2560;l++) dp[k][l]=0;dp[0][0]=1;
			for(k=0;k<n;k++){
				int t1=0,t2=0;
				for(l=0;l<m;l++){if(a[k][l]!=de[r[k%2][l%2]]) t1++;if(a[k][l]!=de[r[k%2][(l+1)%2]]) t2++;}
				for(l=0;l<2505;l++){dp[k+1][l+t1]=(dp[k+1][l+t1]+dp[k][l])%mo;dp[k+1][l+t2]=(dp[k+1][l+t2]+dp[k][l])%mo;}
			}
			for(k=0;k<=b;k++) out=(out+dp[n][k])%mo;
			for(k=0;k<55;k++) for(l=0;l<2560;l++) dp[k][l]=0;dp[0][0]=1;
			for(k=0;k<m;k++){
				int t1=0,t2=0;
				for(l=0;l<n;l++){if(a[l][k]!=de[r[k%2][l%2]]) t1++;if(a[l][k]!=de[r[k%2][(l+1)%2]]) t2++;}
				for(l=0;l<2505;l++){dp[k+1][l+t1]=(dp[k+1][l+t1]+dp[k][l])%mo;dp[k+1][l+t2]=(dp[k+1][l+t2]+dp[k][l])%mo;}
			}
			for(k=0;k<=b;k++) out=(out+dp[m][k])%mo;
		}
//		cout<<out<<endl;
		while(1){
			int t=0;for(i=0;i<n;i++) for(j=0;j<m;j++){if(a[i][j]!=de[(i%2)*2+(j%2)]) t++;}if(t<=b) out=(out+mo-1)%mo;
			if(!next_permutation(de.begin(),de.end())) break;
		}
		return (int)(out%mo);
	}
};
