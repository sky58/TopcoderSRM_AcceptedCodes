//SRM433DIV1-500 SettingTents

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
int kei(int x,int y){
  int i,j;
  int ret=0;
  for(i=0;i<=x;i++) for(j=0;j<=y;j++){
    if((j*j+i*i)==(x-i)*(x-i)+(y-j)*(y-j)) ret++;
  }
  if(x==y) ret--;
  int ret2=0;
  for(i=1;i<x;i++) for(j=1;j*x<i*y;j++){
    if(j*j+i*i==(x-i)*(x-i)+(y-j)*(y-j)) ret2++;
  }
//  if(x==y) ret2--;
//  printf("%d %d %d %d %d\n",x,y,ret,ret2,ret+ret2*2);
  return ret+ret2*2;
}

class SettingTents{
  public:
  int SettingTents::countSites(int x,int y){
    int i,j,out=0;
    for(i=1;i<=x;i++) for(j=1;j<=y;j++){
      int t=kei(i,j);
//      printf("%d %d %d\n",i,j,t);
      out+=t*(x-i+1)*(y-j+1);
    }
    return out;
  }
};
