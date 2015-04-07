//SRM524DIV1-500 LongestSequence
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
#define pf push_front
typedef long long lint;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define maxlen 2100
int tpo[maxlen];bool sumi[maxlen];
int now,n,mi;
vector <int> a;
void rec(int b){
	int i;
	if(sumi[b]) return;sumi[b]=true;
	rep(i,n){
		if(b-a[i]<=mi && b-a[i]>=0) rec(b-a[i]);
	}
	tpo[b]=now;now++;return;
}
class LongestSequence{
	public:
	int LongestSequence::maxLength(vector <int> A){
		int lo=0,hi=maxlen,i,j;a=A;n=a.size();
		while(hi>lo){
			mi=(hi+lo+1)/2;now=0;int f=0;
			memset(sumi,false,sizeof(sumi));
			rep(i,mi+1) rec(i);
			rep(i,mi+1) rep(j,n){
				if(i-a[j]<=mi && i-a[j]>=0){
					if(tpo[i]<tpo[i-a[j]]) f=1;
				}
			}
			if(f<1) lo=mi;else hi=mi-1;
		}
		if(lo>=maxlen) return -1;return lo;
	}
};
