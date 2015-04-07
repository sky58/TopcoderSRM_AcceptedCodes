//SRM230DIV1-500 PascalCount

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
int order(int a,int b){
	int ret=0;if(b==0) return ret;
	while(b%a==0){
		b/=a;ret++;
	}
	return ret;
}
int order2(int a,int b){
	int ret=0;
	while(b>0){
		b/=a;ret+=b;
	}
	return ret;
}
class PascalCount{
	public:
	int PascalCount::howMany(int a,int b){
		if(a<2) return 0;int out=0,i;
		int ni=order2(2,a),sa=order2(3,a),go=order2(5,a);
		int ni1=0,sa1=0,go1=0,ni2=ni,sa2=sa,go2=go;
		ni1=order(2,b);sa1=order(3,b);go1=order(5,b);
		for(i=0;i<=a;i++){
			if(ni-ni2>=ni1 && sa-sa2>=sa1 && go-go2>=go1){out++;}
//			printf("%d %d %d %d\n",i,ni-ni2,sa-sa2,go-go2);
			if(ni1) ni2+=(order(2,i+1)-order(2,a-i));
			if(sa1) sa2+=(order(3,i+1)-order(3,a-i));
			if(go1) go2+=(order(5,i+1)-order(5,a-i));
		}
		return out;
	}
};
