//SRM298DIV1-500 OrderDoesMatter
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
int in[1200],out[1200];
struct unionf{
	vector <int> data;
	unionf(int size):data(size,-1){}
	bool unions(int x,int y){
		x=root(x);y=root(y);
		if(x!=y){
			if(data[y]<data[x]){int d=x;x=y;y=d;}
			data[x]+=data[y];data[y]=x;
		}
		return x!=y;
	}
	bool finds(int x,int y){
		return root(x)==root(y);
	}
	int root(int x){
		return data[x]<0?x:data[x]=root(data[x]);
	}
};
class OrderDoesMatter{
	public:
	int OrderDoesMatter::getOrder(vector <int> a,vector <int> b){
		int i,j,n=a.size(),ma=0;vector <int> ret;unionf uni(55);
		memset(in,0,sizeof(in));memset(out,0,sizeof(out));
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			if(a[i]==a[j] || a[i]==b[j] || b[i]==a[j] || b[i]==b[j]) uni.unions(i,j);
		}
		for(i=0;i<n-1;i++) for(j=i+1;j<n;j++){
			if(!uni.finds(i,j)) return -1;
		}
		for(i=0;i<n;i++){in[a[i]]++;out[b[i]]++;}
		for(i=1;i<1100;i++){
			if(abs(in[i]-out[i])>1) return -1;
			if(in[i]-out[i]==1) ret.pb(i);if(in[i]-out[i]==-1) ret.pb(i);
			if(in[i]>0) ma>?=i;
		}
		if(ret.size()>2) return -1;if(ret.size()>0) return ret[0]*ret[1];return ma*ma;
	}
};
