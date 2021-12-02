#include <iostream>
using namespace std;
void part1(){
    string s;
    int n;
    int depth=0, hori=0;
    cin>>s>>n;
    while(s!="end"){
        if(s[0]=='f'){
            hori+=n;
        }else if(s[0]=='d'){
            depth+=n;
        }else{
            depth-=n;
        }
        cin>>s>>n;
    }
    cout<<depth*hori<<endl;
}

void part2(){
    string s;
    int n;
    int depth=0, hori=0,aim=0;
    cin>>s>>n;
    while(s!="end"){
        if(s[0]=='f'){
            hori+=n;
            depth+=(aim*n);
        }else if(s[0]=='d'){
            aim+=n;
        }else{
            aim-=n;
        }
        cin>>s>>n;
    }
    cout<<depth*hori<<endl;
}
int main(){
    part2();
    return 0;
}
// g++ --std=c++17 -Wall -Wextra Day2.cpp && ./a.out