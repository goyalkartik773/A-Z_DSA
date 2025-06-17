#include<iostream>
#include<math.h>
using namespace std;
int clockwise_rotation(char a, char b) {
    return (b - a + 26) % 26;
}

int anticlockwise_rotation(char a, char b) {
    return (a - b + 26) % 26;
}
int circular(string str){
int n = str.size();
int ans = 0;
for(int i=0;i<n;i++){
    if(i==0){
        ans+= min(clockwise_rotation(str[i],'a'),anticlockwise_rotation(str[i],'a'));
    }
    else{
        ans+= min(clockwise_rotation(str[i],str[i-1]),anticlockwise_rotation(str[i],str[i-1]));
    }
}
return ans+str.size();
 }
int main(){
    string str = "zjpc";
    cout<<circular(str);
}
