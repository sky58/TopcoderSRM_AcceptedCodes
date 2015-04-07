//SRM249DIV1-350 TableSeating
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
vector <int> b;double dp[(1<<12)+10];
int n;
double cal(int a){
//	cout<<a<<endl;
	int i,j;double ret=0.0;
	if(dp[a]>-1e-8) return dp[a];
	for(i=1;i<=b.size() && i<=n;i++){
		double re=0.0;int t=0;
		for(j=0;j+i<=n;j++){
//			cout<<(((1<<i)-1)<<j)<<endl;
			if(!(a&(((1<<i)-1)<<j))){t++;re+=cal(a+(((1<<i)-1)<<j))+i;}
		}
		if(t>0) ret+=re/t*0.01*b[i-1];
	}
	return dp[a]=ret;
}
class TableSeating{
	public:
	double TableSeating::getExpected(int A,vector <int> B){
		for(int i=0;i<(1<<12)+10;i++) dp[i]=-1.0;n=A;b=B;dp[(1<<n)-1]=0.0;return cal(0);
	}
};
