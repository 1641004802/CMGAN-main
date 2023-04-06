#include<bits/stdc++.h>
#define ll long long
using namespace std;

//以pos为下标的前缀和 
ll gsum(int pos,int r){
  ll num=(pos+1)/r;//完整的段数
  ll sum=r*(num-1)*num/2;
  if((pos+1)%r==0)
    return sum;
  else
    return sum+((pos+1)%r)*num;
}
//[left,right)
ll fsum(ll left,ll right,int i){
  return (right-left)*i;
}
//[left,right)
ll getsum(ll left,ll right,int r,int i){
  ll gmin=left/r;
  ll gmax=(right-1)/r;//right取不到 
  ll idx;
  if(i<=gmin){
    return gsum(right-1,r)-gsum(left-1,r)-fsum(left,right,i);
  }
  else if(i>=gmax){
    return fsum(left,right,i)-gsum(right-1,r)+gsum(left-1,r);
  }
  else{
    ll sum=0;
    for(int k=gmin;k<=gmax;k++){
      if(k>=i){
        idx=left+(k-gmin)*r;
        sum+=fsum(left,idx,i)-gsum(idx-1,r)+gsum(left-1,r);
        sum+=gsum(right-1,r)-gsum(idx-1,r)-fsum(idx,right,i);
        return sum;
      }
    }
  }
}

int main(){
  int n,N;
  cin>>n>>N;
  int r=N/(n+1);
  int a[n+1]={0};
  ll sum=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    sum+=getsum(a[i-1],a[i],r,i-1);
  }
  sum+=getsum(a[n],N,r,n);
  cout<<sum;
  system("pause");
  return 0;
}