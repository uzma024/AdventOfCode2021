#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<string> paran;
// vector<char> first;
void part1(){
    int ans=0;
    for(int i=0;i<paran.size();i++){
        string sequence=paran[i];
        stack <char> open;
        for(int j=0;j<sequence.length();j++){
            if(sequence[j]=='('){
                open.push(')');
            }else if(sequence[j]=='{'){
                open.push('}');
            }else if(sequence[j]=='['){
                open.push(']');
            }else if(sequence[j]=='<'){
                open.push('>');
            }else if(sequence[j]==open.top()){
                open.pop();
            }else{
                if(sequence[j]==')'){
                    ans+=3;
                }else if(sequence[j]=='}'){
                    ans+=1197;
                }else if(sequence[j]==']'){
                    ans+=57;
                }else if(sequence[j]=='>'){
                    ans+=25137;
                }
                break;
            }
        }
    }
    
    cout<<"Ans part1:"<<ans<<endl;
}

void part2(){
    vector <long long> ans;
    for(int i=0;i<paran.size();i++){
        bool isCorrupted=false;
        string sequence=paran[i];
        stack <char> open;
        for(int j=0;j<sequence.length();j++){
            if(sequence[j]=='('){
                open.push(')');
            }else if(sequence[j]=='{'){
                open.push('}');
            }else if(sequence[j]=='['){
                open.push(']');
            }else if(sequence[j]=='<'){
                open.push('>');
            }else if(sequence[j]==open.top()){
                open.pop();
            }else{
                isCorrupted=true;
                break;
            }
        }
        if(!isCorrupted){
            long long score=0;
            while(!open.empty()){
                score*=5;
                if(open.top()==')'){
                    score+=1;
                }else if(open.top()==']'){
                    score+=2;
                }else if(open.top()=='}'){
                    score+=3;
                }else if(open.top()=='>'){
                    score+=4;
                }
                open.pop();
            }
            ans.push_back(score);
        }
        
    }

    sort(ans.begin(),ans.end());
    long long mid=ans.size()/2;
    
    cout<<"Ans part2: "<<ans[mid]<<endl;
}
int main(){
    fstream newfile;
    newfile.open("input.txt");
    string tp;
    
    
    while(getline(newfile, tp)){
        paran.push_back(tp);
    }
    part1();
    part2();
    return 0;
}
// g++ --std=c++17 -Wall -Wextra day10.cpp && ./a.out
