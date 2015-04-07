//SRM245DIV1-300 Flush
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
lint co[55][55];
class Flush{
	public:
	double Flush::size(vector <int> a,int b){
		int i,j,k,l;double out=0.0;
		for(i=0;i<55;i++) for(j=0;j<=i;j++){
			if(j==0 || j==i) co[i][j]=1;else co[i][j]=co[i-1][j]+co[i-1][j-1];
		}
		for(i=0;i<=a[0] && i<=b;i++) for(j=0;i+j<=b && j<=a[1];j++) for(k=0;i+j+k<=b && k<=a[2];k++){
			l=b-i-j-k;if(l<0 || l>a[3]) continue;
			out+=1.0*co[a[0]][i]*co[a[1]][j]*co[a[2]][k]*co[a[3]][l]*max(max(i,j),max(k,l));
		}
		return out/co[a[0]+a[1]+a[2]+a[3]][b];
	}
};
