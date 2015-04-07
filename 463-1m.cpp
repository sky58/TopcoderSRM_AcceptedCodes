//SRM463DIV1-500(DIV2-1000) Nisoku
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
class Nisoku{
	public:
	double Nisoku::theMax(vector <double> a){
		sort(a.begin(),a.end());int i,j,n=a.size();double out=0.0;
		if(n==1) return a[0];
		for(i=0;i<=n;i+=2){
			double f=1.0;
			for(j=0;j<i/2;j++) f*=(a[j]+a[i-j-1]);
			for(j=i;j<n;j++) f*=a[j];
			out>?=f;
		}
		return out;
	}
};
