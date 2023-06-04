#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int z=0, t=n-1;
   int i=0;
   while(i<=t)
   {
      if(arr[i]==0){
         swap(arr[i],arr[z++]);
         i++;
      } else if(arr[i]==1){
         i++;
      } else if(arr[i]==2){
         swap(arr[i],arr[t--]);
      }
   }
}