#include <stdio.h>

int n;
int k;
int A[100000];

int max(int *P){
  int res,i;
  res = 0;
  for(i=0;i<n;i++){
    if (res<P[i]){
      res=P[i];
    }
  }
  return res;
}

int hanntei(int m){
  int count,i;
  count = 0;
  for(i=0;i<n;i++){
    count+=A[i]/m;
  }
  if (count<k){
    return 1;
  }
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = max(A)+1;
  while (ub-lb>1){
    int mid = (ub+lb)/2;
    if (hanntei(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
