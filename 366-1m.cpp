//SRM366DIV1-500 GuitarConcert

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
bool kei(vector <string> a,vector <string> b){
	int i,n=a.size();
	for(i=0;i<n;i++){
		if(a[i]<b[i]) return true;
		if(a[i]>b[i]) return false;
	}
	return false;
}

class GuitarConcert{
	public:
	vector <string> GuitarConcert::buyGuitars(vector <string> a,vector <string> b){
		vector <string> out;int ma=0,n=a.size(),m=b[0].size(),i,j,k;
		for(i=1;i<(1<<n);i++){
			vector <string> ret;vector <bool> sumi;int kazu=0;
			for(j=0;j<m;j++) sumi.push_back(false);
			for(j=0;j<n;j++){
				if(i&(1<<j)){
					ret.push_back(a[j]);
					for(k=0;k<m;k++){
						if(b[j][k]=='Y'){
							if(!sumi[k]) kazu++;
							sumi[k]=true;
						}
					}
				}
			}
			sort(ret.begin(),ret.end());
			if(kazu<ma) continue;
			else if(kazu>ma){out=ret;ma=kazu;}
			else if(out.size()<ret.size()) continue;
			else if(kazu==ma && out.size()>ret.size()) out=ret;
			else if(kei(ret,out)) out=ret;
		}
		return out;
	}
};
