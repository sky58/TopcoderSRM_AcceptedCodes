//SRM304DIV1-1000 TheXGame
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
bool ch(string a){
	int i,t=0,f=0;string s;
	for(i=0;i<a.size();i++){if(a[i]=='X') a[i]=' ';}
	istringstream sin(a);
	while(sin>>s){t^=s.size();f++;}
	if(f==0 || t>0) return false;return true;
}
class TheXGame{
	public:
	int TheXGame::firstMove(string a){
		int out=100,n=a.size(),i,j,k;
		for(i=1;i<=n;i++) for(j=0;i+j<=n;j++){
			string b=a;int f=0;
			for(k=0;k<i;k++){
				if(b[j+k]=='X') f=1;b[j+k]='X';
			}
			if(f==0) if(ch(b)) out<?=i;
		}
		if(out>=100) return -1;return out;
	}
};
