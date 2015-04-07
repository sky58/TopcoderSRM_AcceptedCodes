//SRM260DIV1-500 SlowDigitalClock
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
string ka="0123456789";
int de(string a){return (a[0]-'0')*600+(a[1]-'0')*60+(a[3]-'0')*10+(a[4]-'0');}
string en(int a){
	string ret="";ret+=ka[a/600];a%=600;ret+=ka[a/60];a%=60;ret+=':';ret+=ka[a/10];a%=10;ret+=ka[a];return ret;
}
bool ch2(char a,char b){
	if(a==b){if(a=='0' || a=='1' || a=='2' || a=='5' || a=='8') return true;}
	if(a=='6' && b=='9') return true;if(a=='9' && b=='6') return true;return false;
}
bool ch(string a,string b){
	if(ch2(a[0],b[4]) && ch2(a[1],b[3]) && ch2(a[3],b[1]) && ch2(a[4],b[0])) return true;
}
class SlowDigitalClock{
	public:
	string SlowDigitalClock::firstCorrectTime(string a,string b,int c){
		int x=de(a),y=de(b),i;vector <string> zi;
		for(i=0;i<1440;i++) zi.pb(en(i));
		for(i=0;i<1440*c;i++){
			int nx=(x+i)%1440,ny1=((i*60)/c+y)%1440,ny2=((i*60+59)/c+y)%1440;
//			string sx=en(nx),sy1=en(ny1),sy2=en(ny2);
			string sx=zi[nx],sy1=zi[ny1],sy2=zi[ny2];
//			cout<<sx<<' '<<sy1<<' '<<sy2<<endl;
			if(ch(sx,sy1) || ch(sx,sy2)) return sx;
		}
		return "";
	}
};
