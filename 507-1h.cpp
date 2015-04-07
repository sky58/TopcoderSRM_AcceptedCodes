//SRM507DIV1-900 CubeBuilding
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
int dp1[30][55][30][30];
int co[55][55];
lint dp2[30][30][55];
class CubeBuilding{
	public:
	int CubeBuilding::getCount(int a,int b,int c,int n){
		int i,j,k,l,m,mo=1000000007;
		memset(dp1,0,sizeof(dp1));dp1[0][0][n][0]=1;
		for(i=0;i<55;i++) for(j=0;j<=i;j++){
			if(j==i || j==0) co[i][j]=1;else co[i][j]=(co[i-1][j]+co[i-1][j-1])%mo;
		}
		for(i=0;i<=25;i++) for(j=0;j<=50;j++) for(k=n;k>0;k--) for(l=0;l<k;l++){
			if(dp1[i][j][k-l][l]<1) continue;
//			if(i+j<=5) cout<<i<<' '<<j<<' '<<k-l<<' '<<l<<' '<<dp1[i][j][k-l][l]<<endl;
			if(k-l<2){
				dp1[i][j][k-1][0]=(dp1[i][j][k-1][0]+dp1[i][j][k-l][l])%mo;
				dp1[i+1][j][k][0]=(dp1[i+1][j][k][0]+dp1[i][j][k-l][l])%mo;
				if(l>0) dp1[i][j+1][k][0]=(dp1[i][j+1][k][0]+dp1[i][j][k-l][l])%mo;
			}
			else{
				dp1[i][j][k-l-1][l]=(dp1[i][j][k-l-1][l]+dp1[i][j][k-l][l])%mo;
				dp1[i+1][j][k-l-1][l+1]=(dp1[i+1][j][k-l-1][l+1]+dp1[i][j][k-l][l])%mo;
				if(l>0) dp1[i][j+1][k-l-1][l+1]=(dp1[i][j+1][k-l-1][l+1]+dp1[i][j][k-l][l])%mo;
			}
		}
//		for(i=0;i<)
		for(i=0;i<30;i++) for(j=0;j<30;j++) for(k=0;k<55;k++) dp2[i][j][k]=0;dp2[0][0][0]=1;
		for(i=0;i<n;i++) for(j=0;j<=25;j++) for(k=0;k<=50;k++){
			if(dp2[i][j][k]<1) continue;
//			if(j+k<=5) cout<<i<<' '<<j<<' '<<k<<' '<<dp2[i][j][k]<<endl;
			for(l=0;j+l<=25;l++) for(m=0;k+m<=50;m++){
				dp2[i+1][j+l][k+m]=(dp2[i+1][j+l][k+m]+dp2[i][j][k]*dp1[l][m][0][0])%mo;
			}
		}
//		cout<<dp2[n][1][4]<<' '<<dp2[n][2][3]<<endl;
		return (dp2[n][a][b+c]*co[b+c][b]+dp2[n][b][a+c]*co[a+c][c]+dp2[n][c][a+b]*co[a+b][b])%mo;
	}
};
