#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void main(){
  int i;
  int j = 25;

  char* str = "123 this is a string 123 ";

  float f;
  float t = 8.0;
  float m = 3.21;

  i = (int)t;
  f = (float)j;

  for(i=1;i<5;i++){
  	for(j=4;j<7;j++){
  		printf("nested FOR statements ");
  	}
  }

  f = f*m;
  printf("%s",str);
  printf("%f",f);
  
}
