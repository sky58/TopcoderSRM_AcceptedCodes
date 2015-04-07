//SRM423DIV1-1000 TheBeautifulBoard
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
#include<queue>
#include<deque>
using namespace std;
#define Int int
int gya[110000];
int mo=1234567891;
Int extgcd(Int a, Int b, Int &x, Int &y) {
  Int g = a; x = 1; y = 0;
  if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
  return g;
}
Int invMod(Int a, Int m) {
  Int x, y;
  if (extgcd(a, m, x, y) == 1) return (x + m) % m;return 0;
}
long long kei(long long a,int b){
	long long ret=1;int i;
	if(a==0) return 0;
	for(i=0;i<b;i++){
		ret=(ret*((a-i)%mo))%mo*gya[i+1]%mo;
	}
	return ret;
}
class TheBeautifulBoard{
	public:
	int TheBeautifulBoard::count(int n,vector <int> a){
		int i,f=n%2;long long out=1,ret1=1,ret2=1,vol;
		gya[1]=1;for(i=2;i<101000;i++) gya[i]=invMod(i,mo);
//		for(i=2;i<100100;i++) if(mo%i==0) cout<<i;
		if(n==1){if(a.size()==1 && a[0]==1) return 1;else return 0;}
		vol=(long long)n*n;
		for(i=0;i<a.size();i++){
			if(vol<(long long)a[i]) return 0;
			out=(out*kei(vol,a[i]))%mo;vol-=a[i];
//			cout<<out<<'\n';
		}
		for(i=0;i<a.size();i++){
			if(f==1 && a[i]%2==1){f=0;a[i]--;}
			if(a[i]%2>0) return (int)((out*gya[4])%mo);
		}
		vol=(long long)(n/2)*(n-n/2)*2;
		for(i=0;i<a.size();i++){
			ret1=(ret1*kei(vol,a[i]/2))%mo;vol-=a[i]/2;
		}
		for(i=0;i<a.size();i++) if(a[i]%4>0) return (int)(((out+ret1)*gya[4])%mo);
		vol=(long long)(n/2)*(n-n/2);
		for(i=0;i<a.size();i++){
			ret2=(ret2*kei(vol,a[i]/4))%mo;vol-=a[i]/4;
		}
		return (int)((((out+ret1+ret2*2)%mo)*gya[4])%mo);
	}
};
