//SRM277DIV1-250 RogersPhenomenon
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
class RogersPhenomenon{
	public:
	int RogersPhenomenon::countTriggers(vector <int> a,vector <int> b){
		int n=a.size(),m=b.size(),i,out=0;double x=0.0,y=0.0;
		for(i=0;i<n;i++) x+=a[i];
		for(i=0;i<m;i++) y+=b[i];
		x/=n;y/=m;
		for(i=0;i<n;i++){
			if(1.0*a[i]<x && 1.0*a[i]>y) out++;
		}
		for(i=0;i<m;i++){
			if(1.0*b[i]<y && 1.0*b[i]>x) out++;
		}
		return out;
	}
};
