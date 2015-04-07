//SRM271DIV1-500 GameEnding
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
int n;int dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};
bool dfs(bool m[][8]){
	int i,j,k,l;bool o[8][8];
	for(i=0;i<n;i++) for(j=0;j<n;j++){
		if(m[i][j]) continue;
		for(k=0;k<n;k++) for(l=0;l<8;l++) o[k][l]=m[k][l];
		for(k=0;k<n;k++) o[i][k]=o[k][j]=true;
		for(k=0;k<8;k++){
			int nx=i+dx[k],ny=j+dy[k];
			if(nx<n && nx>=0 && ny<n && ny>=0) o[nx][ny]=true;
		}
		if(!dfs(o)) return true;
	}
	return false;
}
class GameEnding{
	public:
	string GameEnding::result(int N,vector <string> a){
		bool m[8][8];memset(m,false,sizeof(m));
		int i,j;n=N;
		for(i=0;i<a.size();i++){
			int x=(a[i][0]-'a'),y=(a[i][1]-'0')-1;
			if(m[x][y]) return "Invalid input";
			for(j=0;j<n;j++) m[x][j]=m[j][y]=true;
			for(j=0;j<8;j++){
				int nx=x+dx[j],ny=y+dy[j];
				if(nx<n && nx>=0 && ny<n && ny>=0) m[nx][ny]=true;
			}
		}
		if(dfs(m)){
			if(a.size()%2==0) return "First player wins";return "Second player wins";
		}
		if(a.size()%2==1) return "First player wins";return "Second player wins";
	}
};
