//SRM484DIV1-950 NumberMagic
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
lint n,m;
lint con(lint a,lint b){
	if(b+b>a) return con(a,a-b);
	lint i,ret=1;
	for(i=0;i<b;i++) ret=ret*(a-i)/(i+1);
	return ret;
}
lint up(lint k){
	lint ret=0,rest=n,i;
	for(i=k;;i--){
		lint t=con(k,i);
		if(t>=rest) return ret+i*rest;
		else{rest-=t;ret+=t*i;}
	}
}
lint dw(lint k){
	lint ret=0,rest=n,i;
	for(i=0;;i++){
		lint t=con(k,i);
		if(t>=rest) return ret+i*rest;
		else{rest-=t;ret+=t*i;}
	}
}
class NumberMagic{
	public:
	int NumberMagic::theMin(int N,int M){
		lint x=1,y=3000000000LL;n=N;m=M;
		while(y>x){
			lint z=(x+y)/2;
			if(z<35 && (1LL<<z)<n){x=z+1;continue;}
			if(up(z)>=z*m && dw(z)<=z*m) y=z;else x=z+1;
		}
		return x;
	}
};
