//SRM483DIV1-900 Sheep
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
vector <int> we;int no[2100];int a,b;
bool ch(int x){
	memset(no,0,sizeof(no));int i,j;
	for(i=0;i<a;i++){
		if(we[i]>x) return false;int f=0;
		for(j=0;j<b+10 && f==0;j++){
			if(j>=b) return false;
			if(no[j]+we[i]<=x){no[j]+=we[i];f=1;}
		}
	}
	return true;
}
class Sheep{
  public:
  int Sheep::minCapacity(int A,int B,vector <string> p1,vector <string> p2,vector <string> p3,vector <string> p4){
    string s;int x=10000000,y=0,i,j,t2;a=A;b=B;
    for(i=0;i<p1.size();i++) s+=p1[i];for(i=0;i<p2.size();i++) s+=p2[i];
    for(i=0;i<p3.size();i++) s+=p3[i];for(i=0;i<p4.size();i++) s+=p4[i];istringstream sin(s);
    for(i=0;i<a;i++){sin>>t2;we.pb(t2);}sort(we.begin(),we.end());reverse(we.begin(),we.end());
    while(x>y+50){
      int z=(x+y)/2,u=-100;
      for(i=z+20;i>=z-20;i--){
      	if(ch(i)) u=i;
      }
      if(u<-50) y=z+20;else x=u;
    }
    for(i=y-100;i<=x+5;i++){
    	if(ch(i)) return i;
    }
  }
};
