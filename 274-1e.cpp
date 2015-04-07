//SRM274DIV1-250 PalindromeMaker
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
int b[30];
class PalindromeMaker{
	public:
	string PalindromeMaker::make(string a){
		int n=a.size(),i,j;string out="",t="";
		memset(b,0,sizeof(b));
		for(i=0;i<n;i++) b[(a[i]-'A')]++;
		for(i=0;i<26;i++){
			if(b[i]%2!=0){
				if(t=="") t+=(i+'A');else return "";
			}
		}
		for(i=0;i<26;i++) for(j=0;j<b[i]/2;j++) out+=(i+'A');out+=t;for(i=25;i>=0;i--) for(j=0;j<b[i]/2;j++) out+=(i+'A');
		return out;
	}
};
