//SRM426DIV1-250 SufflingMachine

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
class ShufflingMachine{
  public:
  double ShufflingMachine::stackDeck(std::vector <int> a, int n, std::vector <int> b, int k){
    vector <int> kaii;
    int i, j, out=0, m=a.size(), kai;
    int card[60], cardd[60];
    int kazu[60][60];
    
    for(i=0;i<m;i++) card[i]=i;
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
        cardd[a[j]]=card[j];kazu[a[j]][card[j]]++;
      }
      for(j=0;j<m;j++) card[j]=cardd[j];
    }
    for(i=0;i<m;i++){
      kai=0;
      for(j=0;j<b.size();j++){
        kai+=kazu[b[j]][i];
      }
      kaii.push_back(kai);
    }
    sort(kaii.begin(),kaii.end(),greater<int>());
    for(i=0;i<k;i++) out+=kaii[i];
    return out/(double)n;
  }
};
