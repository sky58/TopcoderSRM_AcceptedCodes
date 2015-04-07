//SRM399DIV1-250 AvoidingProduct
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
class AvoidingProduct{
	public:
	vector <int> AvoidingProduct::getTriple(vector <int> a,int n){
		int kazu[1010];vector <int> ka,out;int i,j,k,mi=2000000000;
		for(i=0;i<1010;i++) kazu[i]=0;
		out.push_back(0);out.push_back(0);out.push_back(0);
		for(i=0;i<a.size();i++) kazu[a[i]]=1;
		for(i=1;i<1010;i++) if(kazu[i]==0) ka.push_back(i);
//		return ka;
		for(i=0;i<ka.size();i++){
			for(j=i;j<ka.size();j++){
				for(k=j;k<ka.size();k++){
					if(mi>abs(n-ka[i]*ka[j]*ka[k])){
						out[0]=ka[i];out[1]=ka[j];out[2]=ka[k];mi=abs(n-ka[i]*ka[j]*ka[k]);if(mi==0) break;
					}
					if(ka[i]*ka[j]*ka[k]>=n) break;
				}
				if(ka[i]*ka[j]*ka[j]>=n) break;
			}
			if(ka[i]*ka[i]*ka[i]>=n) break;
		}
		return out;
	}
};
