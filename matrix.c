#include <stdio.h>

int main() {
	int i,j;
   	int n;
	 do {
    printf("Enter a positive integer: ");
    scanf("%d", &n);
} while (n <= 0);

    /* int matrix[n][n]; 	
   for (i = 0; i < n; i++) {
      for ( j = 0; j < n; j++) {
         if (i == j) {
            matrix[i][j] = 1; 
         } else {
            matrix[i][j] = 0; 
         }
      }
   } 
   
   printf("Matrix identity:\n");
   for (i = 0; i < n; i++) {
      for ( j = 0; j < n; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
   
   return 0;
} */


printf("Matrix identity:\n");
   for (i = 0; i < n; i++) {
      for ( j = 0; j < n; j++) {
        // printf("%d ", matrix[i][j]);
        if (i==j){
        	printf("1");
        }
        else{
        	printf("0");
		}
		}
      printf("\n");
  }	
  return 0;
   }

