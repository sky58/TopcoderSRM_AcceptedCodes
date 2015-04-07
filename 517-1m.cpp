//SRM517DIV1-600
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
lint dp[55][55],con[55][55];lint mo=1000000007;
lint rec(int x,int y,vector <int> a){
	if(dp[x][y]>-1) return dp[x][y];
	lint ret=0;int i,j;
	for(i=x;i<y;i++){
		if(a[i]<x || a[i]>=y) return 0;
	}
	if(y<=x+1) return 1;
	for(i=x+1;i<y;i++){
/*		if(a[i-1]<i || a[i]>=i) continue;int f=0;
		for(j=x;j<i-1;j++){
			if(a[j]>=i) f=1;
		}
		for(j=i+1;j<y;j++){
			if(a[j]<i) f=1;
		}
		if(f>0) continue;//cout<<x<<' '<<y<<' '<<i<<endl;
*/
		vector <int> b=a;int d=b[i-1];b[i-1]=b[i];b[i]=d;
		ret=(ret+(con[y-x-2][y-i-1]*rec(x,i,b))%mo*rec(i,y,b))%mo;
	}
//	cout<<x<<' '<<y<<' '<<ret<<endl;
	return dp[x][y]=ret;
}
class AdjacentSwaps{
	public:
	int AdjacentSwaps::theCount(vector <int> a){
		int i,j;
		for(i=0;i<55;i++) for(j=0;j<55;j++) dp[i][j]=-1;
		for(i=0;i<55;i++){
			con[i][0]=con[i][i]=1;
			for(j=1;j<i;j++) con[i][j]=(con[i-1][j-1]+con[i-1][j])%mo;
		}
		return rec(0,a.size(),a);
	}
};
