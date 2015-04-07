//SRM315DIV1-500 SillySudoku
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
vector <string> a;int out=0;
bool ta[6][6],yo[6][6];
bool si[6][6][6];
void dfs(int x,int y){
	if(x>=4){out++;return;}
	if(y>=4){dfs(x+1,0);return;}
	for(int i=1;i<5;i++){
		if(ta[y][i] || yo[x][i] || si[x/2][y/2][i]) continue;
		if(a[x][y]!='-' && a[x][y]!=(i+'0')) continue;
		ta[y][i]=true;yo[x][i]=true;si[x/2][y/2][i]=true;dfs(x,y+1);
		ta[y][i]=false;yo[x][i]=false;si[x/2][y/2][i]=false;
	}
	return;
}
class SillySudoku{
	public:
	int SillySudoku::countWays(vector <string> A){
		a=A;
		memset(ta,false,sizeof(ta));memset(yo,false,sizeof(yo));memset(si,false,sizeof(si));
		dfs(0,0);return out;
	}
};
