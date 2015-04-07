//SRM418DIV1-500(Fail)
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
int memo[60][60];
int retu[60];
int N;vector <int> kane;
vector <int> kaku(int a, int b){
	vector <int> ret;int i, j, f;
	ret.push_back(a);f=b;
	while(1){
		if(retu[f]==0) return ret;
		if(memo[f][f]>-1){
			retu[f]--;ret.push_back(memo[f][f]);memo[f][f]=-1;return ret;
		}
		for(i=0;i<N;i++){
			if(memo[f][i]>-1){
				ret.push_back(memo[f][i]);
				retu[f]--;retu[i]--;memo[f][i]=-1;memo[i][f]=-1;
				f=i;break;
			}
		}
	}
}



class StampsCollection{
	public:
	int StampsCollection::sell(int n, std::vector <string> de, std::vector <int> ken){
		int i, j, f, out=0, a, b;vector <vector <int> >ret;
		
		N=n;kane=ken;
		for(i=0;i<n;i++) for(j=0;j<n;j++) memo[i][j]=-1;
		for(i=0;i<n;i++) retu[i]=0;
		for(i=0;i<de.size();i++){
			if(de[i].size()<3){
				sscanf(de[i].c_str(),"%d", &a);
				if(memo[a][a]==-1 || kane[memo[a][a]]<kane[i]){
					memo[a][a]=i;retu[a]++;
				}
			}
			else{
				sscanf(de[i].c_str(),"%d %d", &a, &b);
				if(memo[a][b]==-1 || kane[memo[a][b]]<kane[i]){
					memo[a][b]=i;memo[b][a]=i;retu[a]++;retu[b]++;
				}
			}
		}
		return retu[1];
/*		for(i=0;i<n;i++){
			if(memo[i][i]>-1){
				f=memo[i][i];memo[i][i]=-1;retu[i]--;ret.push_back(kaku(f,i));
			}
		}
		for(i=0;i<n;i++){
			if(retu[i]!=1) continue;
			for(j=0;j<n;j++){
				if(memo[i][j]>-1){
					f=memo[i][j];memo[i][j]=-1;memo[j][i]=-1;
					retu[i]--;retu[j]++;ret.push_back(kaku(f,j));
				}
			}
		}
		for(i=0;i<n;i++){
			if(retu[i]==0) continue;
			for(j=0;j<n;j++){
				if(memo[i][j]>-1){
					f=memo[i][j];memo[i][j]=-1;memo[j][i]=-1;
					retu[i]--;retu[j]++;ret.push_back(kaku(f,j));
				}
			}
		}
		return ret[0][0];
		for(i=0;i<ret.size();i++ out+=kei(rei[i]));
		return out;*/
	}
};
