//SRM333DIV1-250 BirthNumbersValidator
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
string kei(string a){
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,d;long long c;
	y=(a[0]-'0')*10+(a[1]-'0');
	m=(a[2]-'0')*10+(a[3]-'0');
	d=(a[4]-'0')*10+(a[5]-'0');
	istringstream sin(a);sin>>c;
	if(y%4==0) day[1]++;
	if(m==0 || (m>12 && m<51) || m>62) return "NO";
	if(m>50) m-=50;
	if(d==0 || d>day[m-1]) return "NO";
	if(c%11!=0) return "NO";
	return "YES";
}
class BirthNumbersValidator{
	public:
	vector <string> BirthNumbersValidator::validate(vector <string> a){
		vector <string> out;
		for(int i=0;i<a.size();i++) out.push_back(kei(a[i]));
		return out;
	}
};
