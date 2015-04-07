//SRM242DIV1-250 GuessCard
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
int now[110][110],next[110][110];
int ka[11000];
class GuessCard{
	public:
	int GuessCard::whichRow(int w,int h,vector <int> a){
		int i,j,k,m=w*h,n=a.size(),out=-1;memset(ka,0,sizeof(ka));
		for(i=0;i<m;i++) now[i%h][i/h]=i;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++) next[j/w][j%w]=now[j%h][j/h];
			for(j=0;j<w;j++) for(k=0;k<h;k++) now[k][j]=next[k][j];
			for(j=0;j<h;j++) ka[now[j][a[i]]]++;
		}
//		for(i=0;i<m;i++) cout<<now[i%h][i/h]<<endl;
		for(i=0;i<m;i++){
			if(ka[i]>=n){
				if(out>=0) return -1;out=i;
			}
		}
//		cout<<out<<endl;
		for(i=0;i<h;i++){
			if(now[i][a[n-1]]==out) return i;
		}
		return -1;
	}
};
