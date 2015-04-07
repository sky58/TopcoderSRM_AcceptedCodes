//SRM425DIV1-500(DIV2-1000) PiecesMover

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

int n;
vector <int> xx;
vector <int> kk, c;
map<int, bool> sumi;

int zyou(int m, int k){
	int ret=1;
	for(int i=0;i<k;i++) ret*=m;return ret;
}

int checksaiki(int x, int y){
	int ret=1;
	kk[x+y*5]=0;
	if(x>0 && kk[x-1+y*5]==1) ret+=checksaiki(x-1, y);
	if(x<4 && kk[x+1+y*5]==1) ret+=checksaiki(x+1, y);
	if(y>0 && kk[x+y*5-5]==1) ret+=checksaiki(x, y-1);
	if(y<4 && kk[x+y*5+5]==1) ret+=checksaiki(x, y+1);
	return ret;
}

bool check(int a){
//	vector <int> k;
	int i, t;kk=c;
	for(i=0;i<25;i++){
		if(a%2==1){
			kk.push_back(1);t=i;
		}
		else kk.push_back(0);
		a/=2;
	}
	if(checksaiki(t%5, t/5)==n) return true;
	return false;
}

int kouho(int aa){
	vector <int> piece;
	int i, x, y, t, f, ret=0, a=aa;vector <int> k;
	
	for(i=0;i<25;i++){
		if(a%2==1){
			k.push_back(1);piece.push_back(i);
		}
		else k.push_back(0);
		a/=2;
	}
	for(i=0;i<piece.size();i++){
		x=piece[i]%5;y=piece[i]/5;t=piece[i];
		if(x>0 && k[x-1+y*5]==0){
			f=aa-zyou(2,t)+zyou(2,t-1);
			if(!sumi[f]){
				sumi[f]=true;ret++;xx.push_back(f);
			}
		}
		if(x<4 && k[x+1+y*5]==0){
			f=aa-zyou(2,t)+zyou(2,t+1);
			if(!sumi[f]){
				sumi[f]=true;ret++;xx.push_back(f);
			}
		}
		if(y>0 && k[x-5+y*5]==0){
			f=aa-zyou(2,t)+zyou(2,t-5);
			if(!sumi[f]){
				sumi[f]=true;ret++;xx.push_back(f);
			}
		}
		if(y<4 && k[x+5+y*5]==0){
			f=aa-zyou(2,t)+zyou(2,t+5);
			if(!sumi[f]){
				sumi[f]=true;ret++;xx.push_back(f);
			}
		}
	}
	return ret;
}

class PiecesMover{
	public:
	int PiecesMover::getMinimumMoves(std::vector <string> a){
		int i, j, t=0, f=1, out=0, point=0, kazu=1, tugi;
		for(i=0;i<5;i++) for(j=0;j<5;j++){
			if(a[i][j]=='*'){
				n++;t+=f;
			}
			f*=2;
		}
//		return n;
		if(check(t)) return 0;//else return 1;
		xx.push_back(t);sumi[t]=true;
		while(1){
			for(i=0;i<kazu;i++){
				if(check(xx[point+i])) return out;//return xx[point+i];
				tugi+=kouho(xx[point+i]);
			}
			if(tugi==0) return -1;
			point+=kazu;kazu=tugi;tugi=0;out++;
		}		
	}
};
