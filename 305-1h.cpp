//SRM305DIV1-900 PowerCollector
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
int po[70];bool so[70];
string moji(lint a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
class PowerCollector{
	public:
	string PowerCollector::countPowers(string a){
		lint b,out=0;int i,j;istringstream sin(a);sin>>b;
		memset(so,false,sizeof(so));memset(po,0,sizeof(po));
		for(i=2;i<70;i++){
			if(so[i]) continue;po[i]++;
			for(j=i*2;j<70;j+=i){po[j]++;so[j]=true;}
		}
		for(i=2;i<70;i++){
			if(so[i]) continue;for(j=i*i;j<70;j+=i*i) po[j]=0;
		}
		for(i=2;i<70;i++){
			if(po[i]<1) continue;
			lint c=(lint)(1e-7+pow(1.0*b,1.0/i)),d=1;
//			cout<<i<<' '<<po[i]<<' '<<c<<endl;
			for(j=0;j<i;j++) d*=c;if(d>b) c--;
			if(po[i]%2==1) out+=(c-1);else out-=(c-1);
		}
		return moji(out+1);
	}
};
