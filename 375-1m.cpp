//SRM375DIV1-500 DateFieldCorrection

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
using namespace std;
string month[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int day[12]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string moji(int a){
	string ret="";string r="";int amari;
	if(a==0) return "0";if(a<0) return "-"+moji(-a);
	while(a>0){
		amari=a%10;r+=(amari+'0');a/=10;
	}
	for(int i=0;i<r.size();i++) ret+=r[r.size()-(i+1)];
	return ret;
}
int ch(char a){
	if(a==' ') return 36;
	if(a<'A') return (a-'0');
	if(a<'a') return (a-'A')+10;
	return (a-'a')+10;
}
class DateFieldCorrection{
	public:
	string DateFieldCorrection::correctDate(string a){
		string kyo[35]={"09op","12q","213qw","324we","435er","546rt","657ty","768yu","879ui","980io",
					  "aqwsz","sweadzx","dersfxc","frtdgcv","gtyfhvb","hyugjbn","juihknm","kiojlm","lopk",
					  "qw","we","er","rt","ty","yu","ui","io","op","zx","xc","cv","vb","bn","nm",
					  " xcvbnm"};
		int flo[40][40];int i,j,k,mi=1000;string out="";
		
		for(i=0;i<40;i++) for(j=0;j<40;j++) flo[i][j]=300;
		for(i=0;i<34;i++) for(j=1;j<kyo[i].size();j++){
			flo[ch(kyo[i][0])][ch(kyo[i][j])]=1;
			flo[ch(kyo[i][j])][ch(kyo[i][0])]=1;
		}
		for(i=1;i<=6;i++){flo[36][ch(kyo[34][i])]=3;flo[ch(kyo[34][i])][36]=3;}
		for(i=0;i<40;i++) flo[i][i]=0;
		
		for(k=0;k<40;k++) for(i=0;i<40;i++) for(j=0;j<40;j++)
		flo[i][j]=min(flo[i][j],flo[i][k]+flo[k][j]);
		
//		printf("%d %d\n",flo[1][36],flo[2][36]);
		for(i=0;i<12;i++) for(j=1;j<=day[i];j++){
			string s=month[i]+" "+moji(j);int r=0;
			if(s.size()!=a.size()) continue;
			for(k=0;k<s.size();k++){
				r+=flo[ch(s[k])][ch(a[k])];
			}
			if(r<mi){mi=r;out=s;}
		}
		return out;
	}
};
