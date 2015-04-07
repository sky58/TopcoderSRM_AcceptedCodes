//SRM511DIV1-500
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
int dp[550][55];vector <int> a;int n;
int rec(int x,int y){
	if(dp[x][y]>-1) return dp[x][y];if(x>510) return 0;
	int i,f=0,ret=1;
	for(i=0;i<n;i++){
		if((x|a[i])==x){
			f++;if(f>y && rec(x,y+1)==1) ret=0;
		}
		else{
			if(rec(x|a[i],y+1)==1) ret=0;
		}
	}
//	cout<<x<<' '<<y<<' '<<ret<<endl;
	return dp[x][y]=ret;
}
class FiveHundredEleven{
	public:
	string FiveHundredEleven::theWinner(vector <int> A){
		a=A;n=a.size();int t=0,i,j;
		for(i=0;i<n;i++){
			t|=a[i];
		}
		if(t<511){
			if(n%2==0) return "Toastman";else return "Fox Ciel";
		}
		memset(dp,-1,sizeof(dp));
		if(rec(0,0)==0) return "Fox Ciel";return "Toastman";
	}
};
