//SRM273DIV1-250 FallingCoconuts
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
bool sumi[55][200];
void fal(int a,int b){
	if(a==0) sumi[a][b]=true;
	else if(!sumi[a-1][b]) fal(a-1,b);
	else if(!sumi[a-1][b+1]) fal(a-1,b+1);
	else if(!sumi[a-1][b-1]) fal(a-1,b-1);
	else sumi[a][b]=true;
	return;
}
class FallingCoconuts{
	public:
	vector <string> FallingCoconuts::harvest(vector <int> a){
		int i,j,s,g;vector <string> out;
		memset(sumi,false,sizeof(sumi));
		for(i=0;i<a.size();i++) fal(52,100+a[i]);
		for(s=0;s<200;s++){if(sumi[0][s]) break;}
		for(g=199;g>=0;g--){if(sumi[0][g]) break;}
		for(i=0;;i++){
			int f=0;string st="";
			for(j=s;j<=g;j++){if(sumi[i][j]){st+='O';f=1;}else st+='-';}
			if(f<1) return out;else out.pb(st);
		}
	}
};
