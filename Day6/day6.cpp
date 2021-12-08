#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector <long long> fish;

void part1(){
    long long extra=0;
    for(int i=0;i<80;i++){
        for(int j=fish.size()-1;j>=0;j--){
            if(fish[j]==0){
                fish.push_back(8);
                fish[j]=6;
            }else{
                fish[j]--;
            }
        }
        // for(int j=0;j<fish.size();j++){
        //     cout<<fish[j]<<" ";
        // }
        // cout<<endl;
    }
    cout<<fish.size()<<endl;

}
void part2(){
    vector <long long> ans(9,0);
    for(int i=0;i<fish.size();i++){
        ans[fish[i]]++;
    }
    int days;
    cout<<"ENTER DAYS:";
    cin>>days;
    for(int i=0;i<days;i++){
        long long temp=ans[0];
        for(int j=1;j<9;j++){
            ans[j-1]=ans[j];
        }
        ans[8]=temp;
        ans[6]+=temp;
    }
    long long sum=0;
    for(int i=0;i<9;i++){
        sum+=ans[i];
    }

    cout<<"ans part2: "<<sum<<endl;

}
int main(){
    //int array[1000][1000]={0};
    
    fstream newfile;
    newfile.open("input.txt");
    string tp;
    

    while(getline(newfile, tp)){
        int i=0;
        while(i<tp.length()){
            int num=0;
            while(i<tp.length() && tp[i]!=','){
                num=num*10+(tp[i]-'0');
                i++;
            }
            fish.push_back(num);
            i++;
        }
    }

    for(int j=0;j<fish.size();j++){
        cout<<fish[j]<<" ";
    }
    cout<<endl;
    cout<<fish.size()<<endl;
    part2();
    return 0;
}
// g++ --std=c++17 -Wall -Wextra day6.cpp && ./a.out