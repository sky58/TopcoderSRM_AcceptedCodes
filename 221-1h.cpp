//SRM221DIV1-900 PresentyationComp
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
int cal(string a){
	int n=a.size(),i,x=0,y=0;
	for(i=0;i<n;i++){
		if(a[i]=='x') x++;
		else{
			if(x%2==0) y++;else y+=5;
		}
	}
	x%=8;y%=6;return y*8+x;
}
class PresentationComp{
	public:
	string PresentationComp::simplify(string a){
		int i,j,k,t=cal(a);
		for(i=0;i<15;i++) for(j=0;j<(1<<i);j++){
			string b="";
			for(k=i-1;k>=0;k--){
				if(j&(1<<k)) b+='y';else b+='x';
			}
//			cout<<b<<' '<<cal(b)<<' '<<t<<endl;
			if(cal(b)==t) return b;
		}
	}
};
