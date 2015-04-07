//SRM501DIV1-500 FoxAverageSequence
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
int dp[2][1610][42][2];
class FoxAverageSequence{
	public:
	int FoxAverageSequence::theCount(vector <int> a){
		int i,j,k,l,n=a.size(),out=0,mo=1000000007;
		memset(dp,0,sizeof(dp));dp[0][0][0][0]=1;
		for(i=0;i<n;i++){
		 int no=i%2,ne=(i+1)%2;
		 for(j=0;j<=1605;j++) for(k=0;k<41;k++) dp[ne][j][k][0]=dp[ne][j][k][1]=0;
		 for(j=0;j<=1605;j++) for(k=0;k<41;k++){
			if(dp[no][j][k][0]+dp[no][j][k][1]<1) continue;
			for(l=0;l<41;l++){
				if(a[i]>-1 && a[i]!=l) continue;if(l*i>j) continue;
//				if(i>0) cout<<j<<' '<<k<<' '<<l<<endl;
				if(l<k) dp[ne][j+l][l][1]=(dp[ne][j+l][l][1]+dp[no][j][k][0])%mo;
				else{
					dp[ne][j+l][l][0]=(dp[ne][j+l][l][0]+dp[no][j][k][1])%mo;
					dp[ne][j+l][l][0]=(dp[ne][j+l][l][0]+dp[no][j][k][0])%mo;
				}
			}
		 }
		}
		for(i=0;i<1605;i++) for(j=0;j<41;j++){
//			if(dp[n%2][i][j][0]+dp[n%2][i][j][1]>0) cout<<i<<' '<<j<<' '<<dp[n%2][i][j][0]<<' '<<dp[n%2][i][j][1]<<endl;
			out=((out+dp[n%2][i][j][0])%mo+dp[n%2][i][j][1])%mo;
		}
		return out;
	}
};
