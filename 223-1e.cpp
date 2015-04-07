//SRM223DIV1-250 QuizShow
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
class QuizShow{
	public:
	int QuizShow::wager(vector <int> a,int b,int c){
		int out=0,ma=0,i,j;
		for(i=1;i<=a[0];i++){
			int t=0;
			for(j=0;j<8;j++){
				int x=a[0]-i,y=a[1]-b,z=a[2]-c;
				if(j&1) x+=i*2;
				if(j&2) y+=b*2;
				if(j&4) z+=c*2;
				if(x>y && x>z) t++;
			}
			if(ma<t){ma=t;out=i;}
		}
		return out;
	}
};
