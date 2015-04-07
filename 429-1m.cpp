//SRM429DIV1-500(DIV2-1000) IngredientProportions

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

int gcd( int m, int n )
{
	int a=max(m,n),b=min(m,n);
	if ((0==m) || (0==n)) return 0;
	if(a%b==0) return b;
	return gcd(b,a-b*(a/b));
}

int lcm(int m, int n){
	return (long long)m*n/gcd(m,n);
}

class IngredientProportions{
	public:
	vector <int> IngredientProportions::getMasses(std::vector <string> a){
		int i, j, l, t, n=a.size()+1;vector <int> out;
		int bo[12], si[12], sumi[12];int hyou[12][12];
		for(i=0;i<12;i++){
			bo[i]=1;si[i]=1;sumi[i]=0;for(j=0;j<12;j++) hyou[i][j]=0;
		}
		for(i=0;i<a.size();i++){
			hyou[(a[i][1]-'0')][(a[i][8]-'0')]=(a[i][13]-'0');
			hyou[(a[i][8]-'0')][(a[i][1]-'0')]=(a[i][15]-'0');
		}
		for(i=0;i<n;i++){
			if(hyou[0][i]==0) continue;
			bo[i]=hyou[0][i];si[i]=hyou[i][0];sumi[i]++;hyou[0][i]=0;hyou[i][0]=0;
		}
		for(l=0;l<10;l++){
			for(i=1;i<n;i++){
				if(sumi[i]==0) continue;
				for(j=0;j<n;j++){
					if(hyou[i][j]==0) continue;
					bo[j]=bo[i]*hyou[i][j];si[j]=si[i]*hyou[j][i];sumi[j]++;hyou[i][j]=0;hyou[j][i]=0;
				}
			}
		}
		for(i=0;i<n;i++){
			t=gcd(bo[i],si[i]);bo[i]/=t;si[i]/=t;
		}
		t=1;
		for(i=1;i<n;i++) t=lcm(t,bo[i]);
		for(i=0;i<n;i++) out.push_back((long long)si[i]*t/bo[i]);
		return out;
	}
};
