#include <stdio.h>
#include <string.h>

int main() {
   char tt[30];
   int n;
   int count =0;
  int count1[30];
  int min =1000;
  int i=0;
  int vitri=0;
  int j;
  int j1;
  for ( int i1 = 0; i <30; i++)
  {
    count1[i]=0;
  }
  
   printf("nhap ban do va so bo nho, cach nhau boi dau cach");
   scanf("%s %d",tt,&n);
   int k = strlen(tt)-1;
   
   for(i=0;i<=k;)
   {if (tt[i] == '1') { i++; continue;}
   else 
   {count =1;
    for( j=i+1;j<=k;j++)
    {
        if (tt[j] == '1')
        { count1[i]=count; 
        
         break;}
        else count++;
        
        

    }
    fl: i=j+1;
   }
   }
   for(j1=0;j1<=k;) {
   if ((count1[j1] >=n) && (count1[j1]<min)) {
    min=count1[j1];
    
    vitri=j1;
    j1++;


   }
   else j1++;
}
printf("\n vi tri la %d",vitri+1);
for(int k1=vitri;k1<=vitri+n;k1++)
tt[k1]='1';
printf("\n ban do la %s",tt);
}
