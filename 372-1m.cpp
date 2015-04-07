//SRM372DIV1-500 RoundOfEleven
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
#define pb push_back
typedef long long lint;
lint dpo[10][510][12];
lint dpe[10][510][12];
class RoundOfEleven{
	public:
	long long RoundOfEleven::maxIncome(int a,int b){
		vector <int> odd,even;lint out=0;int i,j,k,l,m,od,ev;
		for(i=0;i<10;i++) for(j=0;j<510;j++) for(k=0;k<12;k++){dpo[i][j][k]=0;dpe[i][j][k]=0;}
		dpo[0][0][0]=1;dpe[0][0][0]=1;
		for(i=0;a>0;i++){
			if(i%2==0) odd.pb(a%10);else even.pb(a%10);a/=10;
		}
		od=odd.size();ev=even.size();
		for(i=0;i<od;i++) for(j=0;j<=b;j++) for(k=0;k<11;k++){
			if(dpo[i][j][k]==0) continue;
			for(l=0;l<10;l++){
				if(j+abs(odd[i]-l)<=b) dpo[i+1][j+abs(odd[i]-l)][(k+l)%11]+=dpo[i][j][k];
			}
		}
		
		for(i=0;i<ev;i++) for(j=0;j<=b;j++) for(k=0;k<11;k++){
			if(dpe[i][j][k]==0) continue;
			for(l=0;l<10;l++){
				if(j+abs(even[i]-l)<=b) dpe[i+1][j+abs(even[i]-l)][(k+l)%11]+=dpe[i][j][k];
			}
		}
		for(i=0;i<=b;i++) for(j=0;j<11;j++){
//			cout<<i<<' '<<j<<'\n'<<dpo[1][i][j]<<'\n'<<dpe[1][i][j]<<'\n';
		} 
		for(i=0;i<11;i++) for(j=0;j<b;j++) for(k=0;k+j<b;k++){
			out+=(b-j-k)*dpo[od][j][i]*dpe[ev][k][i];
//			cout<<i<<' '<<j<<' '<<k<<' '<<dpo[od][j][i]<<' '<<dpe[ev][k][i]<<'\n';
		}
		return out;
	}
};
