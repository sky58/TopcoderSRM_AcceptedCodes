//SRM279DIV1-200 DancingSentence
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
char de(char a,int b){
	if(b%2==0){
		if(a<='Z' && a>='A') return a;else return ((a-'a')+'A');
	}
	else{
		if(a<='z' && a>='a') return a;else return ((a-'A')+'a');
	}
}
class DancingSentence{
	public:
	string DancingSentence::makeDancing(string a){
		int i,n=a.size(),t=0;string out="";
		for(i=0;i<n;i++){
			if(a[i]==' ') out+=' ';
			else{out+=de(a[i],t);t++;}
		}
		return out;
	}
};
