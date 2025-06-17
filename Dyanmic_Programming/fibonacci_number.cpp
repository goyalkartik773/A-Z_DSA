#include<iostream>
using namespace std;
int nth_fibo(int num){
if(num == 0 || num == 1)
return 1;
return nth_fibo(num-1) + nth_fibo(num-2);
}
int main(){
 // 0 1 1 2 3 5 8 13 21 35 56 91
 int n;
 cout<<"enter the number upto which you want fibonacci series\n";
 cin>>n;
 for(int i=0;i<n;i++){
    cout<<nth_fibo(i)<<" ";
 }
}