//SRM277DIV1-500 AirlinerSeats
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
map<int,int> me;
class AirlinerSeats{
	public:
	vector <string> AirlinerSeats::mostAisleSeats(int a,int b){
		vector <string> out;string x="",y="";int i,j;
		if((a-b)*3<=a){
			for(i=0;i<(a-b);i++) me[1+i*3]=1;
		}
		else{
			for(i=0;i<(a-b);i++){
				if((a-b-i-1)*2+1<b) break;me[i]=1;
			}
			for(j=0;j<(a-b-i);j++){
				if(b%2==0) me[i+1+j*3]=1;else me[i+2+j*3]=1;
			}
		}
		for(i=0;i<50 && i<a;i++){
			if(me[i]) x+='.';else x+='S';
		}
		out.pb(x);
		if(a<=50) return out;
		if(a>50 && a<=100){for(i=50;i<a;i++) if(me[i]) y+='.';else y+='S';}
		if(a>100){for(i=a-50;i<a;i++) if(me[i]) y+='.';else y+='S';}
		out.pb(y);return out;
	}
};
