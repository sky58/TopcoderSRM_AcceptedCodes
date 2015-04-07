//SRM427DIV1-600 LocateTreasure

#include<stdio.h>
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
#include<list>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<cstdlib>
#include<ctime>
using namespace std;
int dig(int a){
	int ret=0;
	if(a<10) return a;
	while(a>0){
		ret+=a%10;a/=10;
	}
	return dig(ret);
}

string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}

int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}

string dasu(int x, int y){
	string ret="";
	if(x<0){
		x=0-x;ret+="-";
	}
	ret+=moji(x);
	ret+=" ";
	if(y<0){
		y=0-y;ret+="-";
	}
	ret+=moji(y);	
	return ret;
}

class LocateTreasure{
	public:
	string LocateTreasure::location(int k, int mul){
		int x=0, y=0, t=1, syu=0, mae, syuu, px=0, py=0, i;
		vector <int> kazu, vx, vy;
		int xx[4]={0,1,0,-1};int yy[4]={1,0,-1,0};
		
		while(syu<1){
			kazu.push_back(t);t=dig(t*mul);
			for(i=0;i<kazu.size();i++){
				if(kazu[i]==t){
					syu=kazu.size()-i;break;
				}
			}
		}
		mae=kazu.size()-syu;
//		return moji(mae);
		for(i=0;i<mae;i++){
			x+=kazu[i]*xx[i%4];y+=kazu[i]*yy[i%4];k--;
			if(k==0) return dasu(x,y);
		}
		syuu=4*syu/gcd(4,syu);
//		return moji(syuu);
		for(i=0;i<syuu;i++){
			vx.push_back(kazu[i%syu+mae]*xx[(i+mae)%4]);px+=vx[i];
			vy.push_back(kazu[i%syu+mae]*yy[(i+mae)%4]);py+=vy[i];
		}
		for(i=0;i<k%syuu;i++){
			x+=vx[i];y+=vy[i];
		}
		x+=px*(k/syuu);y+=py*(k/syuu);return dasu(x,y);
	}
};
