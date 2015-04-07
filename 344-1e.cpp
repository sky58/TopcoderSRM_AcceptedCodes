//SRM344DIV1-250 VolleyballTournament
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
#include<queue>
#include<deque>
using namespace std;
class VolleyballTournament{
	public:
	string VolleyballTournament::reconstructResults(int a,int b,int c,int d){
		vector <int> win,los;int i;string out;
		d-=b*3;c-=a*3;
		if(d>1 && d<2*a-1) return "AMBIGUITY";
		if(c>1 && c<2*b-1) return "AMBIGUITY";
		for(i=0;i<b;i++){
			if(i<b-c%b) los.push_back(c/b);
			else los.push_back(c/b+1);
		}
		for(i=0;i<a;i++){
			if(i<a-d%a) win.push_back(d/a);
			else win.push_back(d/a+1);
		}
		for(i=0;i<los.size();i++){
			out+=(los[i]+'0');out+="-3";
			if(i!=los.size()-1 || win.size()>0) out+=',';
		}
		for(i=0;i<win.size();i++){
			out+="3-";out+=(win[i]+'0');
			if(i!=win.size()-1) out+=',';
		}
		return out;
	}
};
