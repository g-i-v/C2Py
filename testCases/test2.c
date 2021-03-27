#include <stdio.h>

void main(){

  int k;
  int i;
  int x[5];

  int m = 10;

  for(i = 0;i<5;i++){
  	scanf("%d",&x[i]);
  }

  for(i = 0;i<5;i++){
  	printf("%d",x[i]);
  }



  if(x[2]>7){
  	k=1234;
  }

  else if(x[2]<=7){
  	k = 5678;
  }

  k = k+m;

  printf("%d",k);

}
