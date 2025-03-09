#include<iostream>
using namespace std;
void permutations(string orignal,string str){
    if(orignal.size()==0){
        cout<<str<<endl;
        return;
    }
    for(int i=0;i<orignal.size();i++){
        char ch = orignal[i];
        string left = orignal.substr(0,i);
        string right = orignal.substr(i+1);
        permutations(left+right,str+ch);
    }
}
// finding all permutations using backtracking 
// visit to sare possible path karega per apni conditions ke sath
//step -1 choose that path jis per apko answer mil sake
//step- 2 jab aap path sai return kare to apne change jo data set per kiye usse revert kar dena
void backtracking_permutations(string& str,int idx){
    if(idx == str.size()-1)
    {
        cout<<str<<endl;
        return;
    }
    for(int i=idx;i<str.size();i++){
        // idx wala character ko fixed karke backi jitne character bacche hai unke permutations nikal loo
        swap(str[idx],str[i]);
        backtracking_permutations(str,idx+1);
        swap(str[idx],str[i]);
    }
}
int main(){
string str = "123";
string s=" ";
backtracking_permutations(str,0);
}