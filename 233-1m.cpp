//SRM233DIV1-500 SmartWordToy
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
bool sumi[30][30][30][30],bad[30][30][30][30];
vector <vector <int> > now,next,cl;
//void ad(string a){
void ad(vector <int> a){
//	cout<<"a"<<endl;
	if(!sumi[a[0]][a[1]][a[2]][a[3]] && !bad[a[0]][a[1]][a[2]][a[3]]){
		sumi[a[0]][a[1]][a[2]][a[3]]=true;next.pb(a);
	}
	return;
}
vector <int> de(string a){
	vector <int> ret;for(int i=0;i<a.size();i++) ret.pb((a[i]-'a'));return ret;
}
class SmartWordToy{
	public:
	int SmartWordToy::minPresses(string a,string b,vector <string> c){
		int i,j,k,l,m;string x,y,z,w;vector <int> s=de(a),g=de(b);
		memset(sumi,false,sizeof(sumi));memset(bad,false,sizeof(bad));
		for(i=0;i<c.size();i++){
			istringstream sin(c[i]);
			sin>>x>>y>>z>>w;
			for(j=0;j<x.size();j++) for(k=0;k<y.size();k++) for(l=0;l<z.size();l++) for(m=0;m<w.size();m++){
				bad[(x[j]-'a')][(y[k]-'a')][(z[l]-'a')][(w[m]-'a')]=true;
			}
		}
		ad(s);now=next;next=cl;
		for(i=0;now.size()>0;i++){
//			cout<<now.size()<<endl;
			for(j=0;j<now.size();j++){
				vector <int> t=now[j];if(t==g) return i;//cout<<i<<' '<<t[0]<<' '<<t[1]<<' '<<t[2]<<' '<<t[3]<<endl;
				for(k=0;k<4;k++) for(l=25;l<28;l++){
//					y=x;y[k]=((((y[k]-'a')+l)%26)+'a');ad(y);
					vector <int> u=t;u[k]=(u[k]+l)%26;ad(u);
				}
			}
			now=next;next=cl;
		}
		return -1;
	}
};
