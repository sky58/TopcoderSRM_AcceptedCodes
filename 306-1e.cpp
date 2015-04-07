//SRM306DIV1-250 BifidSortMachine
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
map<int,int> me;vector <int> b;int n;
bool ch(vector <int> c){
	vector <int> d=c;sort(d.begin(),d.end());if(d==c) return true;return false;
}
int cal(vector <int> c){
	int i,j,m=c.size();
	map<int,int> me2;
	for(i=0;i<m;i++){
		vector <int> d;for(j=0;j<m;j++){if(!me2[c[j]]) d.pb(c[j]);}
		if(ch(d)) return i;me2[b[n-1-i]]=1;
	}
}
class BifidSortMachine{
	public:
	int BifidSortMachine::countMoves(vector <int> a){
		b=a;int i,j,out=1000;n=a.size();sort(b.begin(),b.end());
		for(i=0;i<n;i++){
			vector <int> c;
			for(j=0;j<n;j++){
				if(!me[a[j]]) c.pb(a[j]);
			}
			out<?=i+cal(c);me[b[i]]=1;
		}
		return out;
	}
};
