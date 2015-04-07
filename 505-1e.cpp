//SRM505DIV1-300 RectangleArea
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
bool gr[110][110];
bool sumi[110];
void dfs(int a){
	if(sumi[a]) return;sumi[a]=true;
	for(int i=0;i<105;i++){
		if(gr[a][i]) dfs(i);
	}
	return;
}
class RectangleArea{
	public:
	int RectangleArea::minimumQueries(vector <string> a){
		int w=a.size(),h=a[0].size(),i,j,out=0;
		for(i=0;i<w;i++) for(j=0;j<h;j++){
			if(a[i][j]=='Y'){gr[i][j+w]=true;gr[j+w][i]=true;}
		}
		for(i=0;i<h+w;i++){
			if(!sumi[i]){dfs(i);out++;}
		}
		return out-1;
	}
};
