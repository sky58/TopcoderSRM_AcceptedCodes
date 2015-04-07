//SRM523DIV1-900 AlphabetPaths
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
#define All(s) s.begin(),s.end()
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int num[(1<<21)+10];
int ka[30];
string al="ABCDEFZHIKLMNOPQRSTVX";
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
vector <string> a;int w,h;
vector <int> now,cl;
bool in(int x,int y){
  if(x<0 || y<0 || x>=w || y>=h) return false;return true;
}
void rec(int x,int y,int kaz,int ma){
  int i;
  if(kaz>9){
  	now.pb(ma);num[ma]++;return;
  }
  rep(i,4){
    int x1=x+dx[i],y1=y+dy[i];
    if(!in(x1,y1)) continue;
    if(a[x1][y1]=='.') continue;
    if(!(ma&ka[(a[x1][y1]-'A')])){
    	rec(x1,y1,kaz+1,ma+ka[(a[x1][y1]-'A')]);
    }
  }
  return;
} 
class AlphabetPaths{
	public:
	long long AlphabetPaths::count(vector <string> A){
		a=A;w=a.size();h=a[0].size();
		int i,j,k;lint out=0;
		rep(i,21) ka[(al[i]-'A')]=(1<<i);
		rep(i,w) rep(j,h){
			if(a[i][j]=='.') continue;
			now=cl;
			rep(k,4){
				int x=i+dx[k],y=j+dy[k];
				if(in(x,y)){
					if(a[x][y]!='.') rec(x,y,1,ka[(a[x][y]-'A')]);
				}
			}
			rep(k,now.size()){
				if(!(now[k]&ka[(a[i][j]-'A')])){
					out+=(lint)num[now[k]]*num[(1<<21)-now[k]-ka[(a[i][j]-'A')]-1]*2;
				}
				num[now[k]]=0;
			}
		}
		return out;
	}
};
