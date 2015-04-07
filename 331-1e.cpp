//SRM331DIV1-250 CarolsSinging
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
int bitc(int a){return a==0?0:a%2+bitc(a/2);}
class CarolsSinging{
	public:
	int CarolsSinging::choose(vector <string> a){
		int i,j,k,m=a.size(),n=a[0].size(),out=20;
		bool sumi[35];
		for(i=0;i<(1<<n);i++){
			memset(sumi,false,sizeof(sumi));
			for(j=0;j<m;j++) for(k=0;k<n;k++){
				if(i&(1<<k) && a[j][k]=='Y') sumi[j]=true;
			}
//			cout<<i<<' ';
			for(j=0;j<m;j++){
//				if(sumi[j]) cout<<"1 ";else cout<<"0 ";
			}
//			cout<<'\n';
			int f=0;
			for(j=0;j<m;j++){
				if(sumi[j]==false) f=1;
			}
			if(f==0){
//				cout<<i<<'\n';
				out<?=bitc(i);
			}
		}
		return out;
	}
};
