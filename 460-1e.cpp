//SRM460DIV1-250 TheQuestionAndAnswersDivOne
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
int comb(int a,int b){
	int i,ret=1;
	for(i=0;i<b;i++) ret=ret*(a-i)/(i+1);
	return ret;
}
int calc(int a,int b){
	if(a==0 && b==0) return 1;
	if(a==0 || b==0) return 0;
	if(a<b) return 0;
	int ret=0,t=1,i,j;
	for(i=b;i>=1;i--){
		int f=t*comb(b,i);
		for(j=0;j<a;j++) f*=i;
		t*=-1;ret+=f;
	}
	return ret;
}
class TheQuestionsAndAnswersDivOne{
	public:
	int TheQuestionsAndAnswersDivOne::find(int a,vector <string> b){
		int i,ret=0,y=0,n=0;
		for(i=0;i<b.size();i++){
			if(b[i]=="Yes") y++;else n++;
		}
//		cout<<calc(3,2)<<' '<<y<<' '<<n;
		for(i=0;i<=a;i++) ret+=calc(y,i)*calc(n,a-i)*comb(a,i);
		return ret;
	}
};
