//SRM312DIV1-250 ParallelepipedUnion
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
bool sumi[110][110][110];
class ParallelepipedUnion{
	public:
	int ParallelepipedUnion::getVolume(vector <string> a){
		int x1,y1,z1,x2,y2,z2,out=0,i,j,k;
		memset(sumi,false,sizeof(sumi));
		istringstream sin(a[0]);sin>>x1>>y1>>z1>>x2>>y2>>z2;
		for(i=x1;i<x2;i++) for(j=y1;j<y2;j++) for(k=z1;k<z2;k++){
			if(!sumi[i][j][k]){sumi[i][j][k]=true;out++;}
		}
		istringstream sin2(a[1]);sin2>>x1>>y1>>z1>>x2>>y2>>z2;
		for(i=x1;i<x2;i++) for(j=y1;j<y2;j++) for(k=z1;k<z2;k++){
			if(!sumi[i][j][k]){sumi[i][j][k]=true;out++;}
		}
		return out;
	}
};

//Another answer
class ParallelepipedUnion{
	public:
	int ParallelepipedUnion::getVolume(vector <string> a){
		int x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4;
		istringstream si(a[0]),se(a[1]);
		si>>x1>>y1>>z1>>x2>>y2>>z2;
		se>>x3>>y3>>z3>>x4>>y4>>z4;
		int out=(x2-x1)*(y2-y1)*(z2-z1)+(x4-x3)*(y4-y3)*(z4-z3);
		if(x1>x4 || x3>x2 || y1>y4 || y3>y2 || z1>z4 || z3>z2) return out;
		return out-min(min(x2-x1,x4-x3),min(x2-x3,x4-x1))*min(min(y2-y1,y4-y3),min(y2-y3,y4-y1))*min(min(z2-z1,z4-z3),min(z2-z3,z4-z1));
	}
};
