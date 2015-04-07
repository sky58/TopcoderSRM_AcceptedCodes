//SRM462DIV1-450 CandyBox
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
class CandyBox{
	public:
	vector <double> CandyBox::expectedScore(int a,vector <int> b,int c){
		vector <double> out;int i,j,n=b.size();double kei=0.0;
		for(i=0;i<n;i++){out.pb(1.0*b[i]);kei+=1.0*b[i];}
		if(n==1) return out;
		for(i=0;i<n;i++) for(j=0;j<c;j++){
			double ex=1.0*a*(n-1)*2/n/(a*n-1),sa=(kei-out[i])/(n*1.0-1.0);
			out[i]-=out[i]*ex/a;out[i]+=ex*sa/a;
		}
		return out;
	}
};
