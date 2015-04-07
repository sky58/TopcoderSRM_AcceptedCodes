//SRM286DIV1-250 ExtraBall
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
bool ch(string a,string b){
	int i,f=0,n=a.size();
	for(i=0;i<n;i++){
		if(a[i]=='.' && b[i]=='X') f++;
	}
	if(f==1) return true;return false;
}
class ExtraBall{
	public:
	double ExtraBall::expectedPayout(vector <int> a,vector <int> b,vector <string> c,vector <int> d){
		int n=a.size(),i,j;string s="";double out=0.0;
		for(i=0;i<n;i++) s+='.';
		for(i=0;i<b.size();i++) for(j=0;j<n;j++){
			if(b[i]==a[j]) s[j]='X';
		}
		for(i=0;i<d.size();i++){
			if(ch(s,c[i])) out+=1.0*d[i]/(75-b.size());
		}
		return out;
	}
};
