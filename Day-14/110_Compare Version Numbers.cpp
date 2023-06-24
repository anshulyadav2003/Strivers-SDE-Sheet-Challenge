#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
   int n1=a.length();   int n2=b.length();
   int i=0,j=0;
   while(i<n1 || j<n2)
   {
       while(i<n1 && a[i]=='0') i++;
       while(j<n2 && b[j]=='0') j++;
    //    string num1="",num2="";
       long long num1=0,num2=0;
       while(i<n1 && a[i]!='.') num1 = 10*num1 + (a[i++]-'0');// num1+=a[i++];
       while(j<n2 && b[j]!='.') num2 = 10*num2 + (b[j++]-'0');// num2+=b[j++];

       if(num1!=num2)   return num1<num2 ? -1 : 1;
       i++; j++;
   }
   return 0; // both are same
}