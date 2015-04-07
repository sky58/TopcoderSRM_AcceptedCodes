//SRM305DIV1-250 UnfairDivision
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
vector <int> a;int n;
vector <int> cal2(int b,int c){
	int i,d;
	vector <int> ret;ret.pb(0);ret.pb(0);ret.pb(0);
	if(b>c){d=b;b=c;c=d;}
	for(i=0;i<=b;i++) ret[0]+=a[i];
	for(i=b+1;i<=c;i++) ret[1]+=a[i];
	for(i=c+1;i<n;i++) ret[2]+=a[i];
	sort(ret.begin(),ret.end());reverse(ret.begin(),ret.end());
	d=ret[0];ret[0]=ret[1];ret[1]=d;
	return ret;
}
int cal(int b){
	vector <int> ret;int i;
	for(i=0;i<n-1;i++){
		if(i!=b) ret=max(ret,cal2(i,b));
	}
//	for(i=0;i<3;i++) cout<<ret[i]<<' ';cout<<endl;
	return ret[2];
}
class UnfairDivision{
	public:
	int UnfairDivision::albertsShare(vector <int> A){
		int i,out=0;a=A;n=a.size();
		for(i=0;i<n-1;i++) out>?=cal(i);
		return out;
	}
};
