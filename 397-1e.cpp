//SR<397DIV1-250 SortingGame
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
int n, k;
map<int, bool> sumi;
vector <int> x;


int kei(int a, int b, vector <int> t){
	int i, ret=0, d, tt=1;
	for(i=0;i<b/2;i++){
		d=t[a+i];t[a+i]=t[a+b-i-1];t[a+b-i-1]=d;
	}
//	reverse(t[a],t[a+b-1]);
	for(i=0;i<n;i++){
		ret+=t[i]*tt;tt*=10;
//		ret*=10;ret+=t[i];
	}
	return ret;
}

int kouho(int a){
	vector <int> t;int i, ret=0, f;
	while(a>0){
		t.push_back(a%10);a/=10;
	}
	for(i=0;i<=n-k;i++){
		f=kei(i,k,t);
		if(!sumi[f]){
			sumi[f]=true;x.push_back(f);ret++;
		}
	}
	return ret;
}

class SortingGame{
	public:
	int SortingGame::fewestMoves(std::vector <int> a, int b){
		int goal=0, start=0, t=1, out=0, i, j, point=0, kazu=1, tugi=0;
		
		n=a.size();k=b;
		for(i=0;i<n;i++){
			goal*=10;goal+=(n-i);
		}
		for(i=0;i<n;i++){
			start+=a[i]*t;t*=10;
		}
		if(start==goal) return 0;
		x.push_back(start);sumi[start]=true;
		while(1){
			for(i=0;i<kazu;i++){
				if(x[point+i]==goal) return out;
				tugi+=kouho(x[point+i]);
			}
			if(tugi==0) return -1;
			point+=kazu;kazu=tugi;tugi=0;out++;
		}			
	}
};
