//SRM274DIV1-1000 RingImposition
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
vector <vector <int> > one,tmp,ret;
vector <int> cl;
map<int,vector <vector <int> > > me;
int n;
vector <vector <int> > cal(int a){
	if(me[a].size()) return me[a];
	int i,j,k;vector <vector <int> > ma=cal(a/2),ato=cal(a-a/2),out=tmp;
	for(i=0;i<n;i++) for(j=0;j<n;j++) for(k=0;k<n;k++) out[i][j]=(out[i][j]+ma[i][k]*ato[k][j])%100;
//	cout<<a<<' '<<out[0][1]<<endl;
	return me[a]=out;
}
class RingImposition{
	public:
	vector <int> RingImposition::predict(vector <int> a,int b){
		int i,j;n=a.size();
		for(i=0;i<n;i++) cl.pb(0);for(i=0;i<n;i++) tmp.pb(cl);one=tmp;
		for(i=0;i<n;i++){one[i][i]=1;one[i][(i+1)%n]=1;}me[1]=one;ret=cal(b);
		for(i=0;i<n;i++) for(j=0;j<n;j++) cl[i]=(cl[i]+ret[i][j]*a[j])%100;
		return cl;
	}
};
