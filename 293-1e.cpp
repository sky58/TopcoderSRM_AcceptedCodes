//SRM293DIV1-300 ScrabbleBet
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
double con(int a,int b){
	double ret=1.0;
	for(int i=0;i<b;i++){ret*=(a-i);ret/=(i+1);}return ret;
}
class ScrabbleBet{
	public:
	double ScrabbleBet::estimate(int a,int b,int c,int d){
		double x=0.01*d,ret=0.0;int i;
		for(i=c;i<=b;i++) ret+=con(b,i)*pow(x,i)*pow(1.0-x,b-i);
		return 1.0-pow(1.0-ret,a);
	}
};
