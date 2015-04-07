//SRM255DIV1-250 WordCompositionGame
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
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class WordCompositionGame{
	public:
	string WordCompositionGame::score(vector <string> a,vector <string> b,vector <string> c){
		int x=0,y=0,z=0,as=a.size(),bs=b.size(),cs=c.size(),i,j;
		for(i=0;i<as;i++){
			int f=3;
			for(j=0;j<bs;j++){if(a[i]==b[j]) f--;}
			for(j=0;j<cs;j++){if(a[i]==c[j]) f--;}
			x+=f;
		}
		for(i=0;i<bs;i++){
			int f=3;
			for(j=0;j<as;j++){if(b[i]==a[j]) f--;}
			for(j=0;j<cs;j++){if(b[i]==c[j]) f--;}
			y+=f;
		}
		for(i=0;i<cs;i++){
			int f=3;
			for(j=0;j<bs;j++){if(c[i]==b[j]) f--;}
			for(j=0;j<as;j++){if(c[i]==a[j]) f--;}
			z+=f;
		}
		return moji(x)+'/'+moji(y)+'/'+moji(z);
	}
};
