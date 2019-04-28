#include <stdio.h>

int n;
int c[100][100];

//  model
int x[100];
int x_best[100];
int f;// objective function
int f_best; // best objective value
int b[100];// b[v] = 1 means that v is used
int cmin;

void readData(char* fn){
  FILE* f = fopen(fn,"r");
  fscanf(f,"%d",&n);
  cmin = 100000000;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      fscanf(f,"%d",&c[i][j]);
      if(i != j && c[i][j] < cmin) cmin = c[i][j];
    }
  fclose(f);
}

void TRY(int k){// try values for x[k]

  for(int v = 1; v <= n; v++){
    if(!b[v]){
      x[k] = v;
      b[v] = 1;
      f = f + c[x[k-1]][x[k]];
      int gk = f + (n-k+1)*cmin;
      printf("x = (");
      for(int i = 1; i <= k; i++)
        printf("%d,",x[i]);
      printf("), f = %d, g = %d\n",f,gk);
      if(k == n){
        if(f + c[x[n]][x[1]] < f_best){
          f_best = f + c[x[n]][x[1]];
          for(int i = 1;i <= n; i++)
            x_best[i] = x[i];
          printf("Update Best %d\n",f_best);
        }
      }else{

        if(gk < f_best)
          TRY(k+1);
        else
          printf("Ko phat trien loi giai\n");
      }
      b[v] = 0;// recover
      f = f - c[x[k-1]][x[k]];
    }
  }
}

int main(int argc, char** argv){
  readData(argv[1]);
  for(int v = 1; v <= n; v++) b[v] = 0;

  x[1] = 1;
  b[1] = 1;
  f_best = 10000000;
  f = 0;
  TRY(2);

  printf("f_best = %d\n",f_best);
  for(int i = 1; i <= n; i++)
    printf("%d -> ",x_best[i]);
  printf("%d\n",x_best[1]);
}
