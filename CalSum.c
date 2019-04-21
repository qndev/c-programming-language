#include<stdio.h>
#include<stdlib.h>

int main(){
  int n;
  long S=0;
  printf("Nhap n:");
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    S=S+i;
  }
  printf("Tong 1+2+3+...+n la: %ld", S);
  return 0;
}
