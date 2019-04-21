#include <stdio.h>
#include <stdlib.h>
// Caculate sum of numbers 1 to n using recursive algorithm.
int cal_sum_recursive(int n);

int main(){
  int n;
  printf("Input number: ");
  scanf("%d", &n);
  int function = cal_sum_recursive(n);
  printf("Sum of 1+2+3+...+n is %d", function);
  return 0;
}

int cal_sum_recursive(int n){
  // Basic step	
  if(n == 0){
    return 0;
  }else{ //Recursive step
    int result_subproblem_1 = n;
    int result_subproblem_2 = cal_sum_recursive(n-1);
    int combine_result_subproblems = result_subproblem_1 + result_subproblem_2;
    return combine_result_subproblems;  
  }
}
