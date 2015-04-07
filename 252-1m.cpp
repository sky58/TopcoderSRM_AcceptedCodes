//SRM252DIV1-500 WatchtowerSpotlight
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
bool sumi[110][60][60],bad[110][60][60];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
double pi=3.14159265358979,ep=1e-8;
class WatchtowerSpotlight{
	public:
	int WatchtowerSpotlight::quickestEscape(string a,string b,string c){
		memset(bad,false,sizeof(bad));memset(sumi,false,sizeof(sumi));
		int sx,sy,gx,gy,wx,wy,s,d,i,j,k;vector <pint> now,next,cl;
		istringstream sin(a);sin>>sx>>sy;
		istringstream sin1(b);sin1>>gx>>gy;
		istringstream sin2(c);sin2>>wx>>wy>>s>>d;
		for(i=0;i<s;i++){
			double l1=i*2.0*pi/s,l2=(i+1)*2.0*pi/s;bad[i][wx][wy]=true;
			for(j=0;j<60;j++) for(k=0;k<60;k++){
				if(d*d>=(j-wx)*(j-wx)+(k-wy)*(k-wy)){
					double l=atan2(0.0+k-wy,0.0+j-wx);//cout<<j<<' '<<k<<' '<<l<<endl;
					if((l1-ep<l && l2+ep>l) || (l1-ep<l+2.0*pi && l2+ep>l+2.0*pi)){
						bad[i][j][k]=true;//cout<<i<<' '<<j<<' '<<k<<endl;
					}
				}
			}
		}
		if(bad[0][sx][sy]) return -1;sumi[0][sx][sy]=true;now.pb(mp(sx,sy));
		for(i=0;;i++){
			for(j=0;j<now.size();j++){
				int x=now[j].fi,y=now[j].se;if(x==gx && y==gy) return i;
				for(k=0;k<4;k++){
					int nx=x+dx[k],ny=y+dy[k];
					if(nx<0 || ny<0 || nx>=50 || ny>=50) continue;
					if(bad[(i+1)%s][nx][ny] || sumi[(i+1)%s][nx][ny]) continue;
					sumi[(i+1)%s][nx][ny]=true;next.pb(mp(nx,ny));
				}
			}
			now=next;next=cl;if(now.size()<1) break;
		}
		return -1;
	}
};
