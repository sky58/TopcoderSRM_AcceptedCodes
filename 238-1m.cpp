//SRM238DIV1-500 SequenceSync
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
bool sumi[1100000];
vector <int> now,next,cl;
int tr[25][5];
class SequenceSync{
	public:
	int SequenceSync::getLength(vector <string> a){
		int n=a.size(),i,j,k,l;
		for(i=0;i<n;i++){
			istringstream sin(a[i]);
			for(j=0;j<4;j++) sin>>tr[i][j];
		}
		memset(sumi,false,sizeof(sumi));sumi[(1<<n)-1]=true;now.pb((1<<n)-1);
		for(i=0;now.size()>0;i++){
			for(j=0;j<now.size();j++){
				if(__builtin_popcount(now[j])<2) return i;
				for(k=0;k<4;k++){
					int t=0;
					for(l=0;l<n;l++){
						if(now[j]&(1<<l)) t|=(1<<tr[l][k]);
					}
					if(!sumi[t]){sumi[t]=true;next.pb(t);}
				}
			}
			now=next;next=cl;
		}
		return -1;
	}
};
