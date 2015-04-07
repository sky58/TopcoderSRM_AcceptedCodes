//SRM460DIV1-500 TheFansAndMeetingsDivOne
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
double dpb[42][42][1650],dpj[42][42][1650];
class TheFansAndMeetingsDivOne{
	public:
	double TheFansAndMeetingsDivOne::find(vector <int> jmi,vector <int> jma,vector <int> bmi,vector <int> bma,int s){
		int n=jmi.size(),i,j,k,l;double ret=0.0;
		for(i=0;i<42;i++) for(j=0;j<42;j++) for(k=0;k<1650;k++){dpj[i][j][k]=0.0;dpb[i][j][k]=0.0;}
		dpj[0][0][0]=1.0;dpb[0][0][0]=1.0;
		for(i=0;i<n;i++) for(j=0;j<=s;j++) for(k=0;k<=1600;k++){
			if(dpj[i][j][k]>0.0){
//				for(l=jmi[i];l<=jma[i];l++) dpj[i+1][j+1][k+l]+=dpj[i][j][k]*s/((1.0+jma[i]-jmi[i])*n);
				for(l=jmi[i];l<=jma[i];l++) dpj[i+1][j+1][k+l]+=dpj[i][j][k]/(1.0+jma[i]-jmi[i])*(1.0+j)/(1.0+i);
//				dpj[i+1][j][k]+=dpj[i][j][k]*(n-s)/n;
				dpj[i+1][j][k]+=dpj[i][j][k]*(1.0+i-j)/(1.0+i);
			}
			if(dpb[i][j][k]>0.0){
//				for(l=bmi[i];l<=bma[i];l++) dpb[i+1][j+1][k+l]+=dpb[i][j][k]*s/((1.0+bma[i]-bmi[i])*n);
				for(l=bmi[i];l<=bma[i];l++) dpb[i+1][j+1][k+l]+=dpb[i][j][k]/(1.0+bma[i]-bmi[i])*(1.0+j)/(1.0+i);
//				dpb[i+1][j][k]+=dpb[i][j][k]*(n-s)/n;
				dpb[i+1][j][k]+=dpb[i][j][k]*(1.0+i-j)/(1.0+i);
			}
		}
		for(i=0;i<=1600;i++) ret+=dpb[n][s][i]*dpj[n][s][i];
		return ret;
	}
};
