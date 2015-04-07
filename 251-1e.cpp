//SRM252DIV1-250 SMS
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
string vo="aeiouAEIOU";int n;
bool chvo(char a){
	for(int i=0;i<vo.size();i++){if(a==vo[i]) return true;}
	return false;
}
bool ch(int t,string a){
	int ret=0,i;
	for(i=t-1;i>=0;i--){
		if(a[i]==' ') break;
		if(!chvo(a[i])){ret++;break;}
	}
	for(i=t+1;i<n;i++){
		if(a[i]==' ') break;
		if(!chvo(a[i])){ret++;break;}
	}
	if(ret>1) return true;return false;
}
class SMS{
	public:
	string SMS::compress(string a){
		n=a.size();int i;string out="";
		for(i=0;i<n;i++){
			if(chvo(a[i])) if(ch(i,a)) continue;out+=a[i];
		}
		return out;
	}
};
