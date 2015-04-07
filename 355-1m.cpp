//SRM355DIV1-600 Tetrahedron
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
int dist[4][4];
class Tetrahedron{
	public:
	string Tetrahedron::exists(vector <string> a){
		int i,j;double x1,x2,y1,y2;
		for(i=0;i<4;i++){
			istringstream sin(a[i]);
			for(j=0;j<4;j++) sin>>dist[i][j];
		}
		if(abs(dist[0][2]-dist[1][2])>dist[0][1]) return "NO";
		if(abs(dist[0][3]-dist[1][3])>dist[0][1]) return "NO";
		x1=(1.0*dist[0][1]*dist[0][1]+dist[0][2]*dist[0][2]-dist[1][2]*dist[1][2])*0.5/dist[0][1];
		y1=sqrt(1.0*dist[0][2]*dist[0][2]-x1*x1);
		x2=(1.0*dist[0][1]*dist[0][1]+dist[0][3]*dist[0][3]-dist[1][3]*dist[1][3])*0.5/dist[0][1];
//		cout<<x1<<' '<<x2<<' '<<y1<<endl;
		if(fabs(y1)<1e-10){
			if(fabs((x1-x2)*(x1-x2)-x2*x2-(dist[2][3]*dist[2][3]-dist[0][3]*dist[0][3]))<1e-10) return "YES";return "NO";
		}
		y2=(y1*y1+x1*x1+dist[0][3]*dist[0][3]-dist[2][3]*dist[2][3]-x1*x2*2)/(y1*2);
//		cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
		if(dist[0][3]*dist[0][3]-(x2*x2+y2*y2)>-1e-10) return "YES";return "NO";
	}
};
