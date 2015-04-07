//SRM292DIV1-250 Abacus
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
class Abacus{
	public:
	vector <string> Abacus::add(vector <string> a,int b){
		int t=0,i,j;vector <string> out;
		for(i=0;i<6;i++){
			for(j=0;j<12;j++){if(a[i][j]=='-') break;}
			t=t*10+(9-j);
		}
		t=(t+b)%1000000;
		for(i=0;i<6;i++){
			string c="";
			for(j=t%10;j<9;j++) c+='o';c+="---";for(j=0;j<t%10;j++) c+='o';
			out.pb(c);t/=10;
		}
		reverse(out.begin(),out.end());return out;
	}
};
