#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
vector <int> position;
vector <int> cost;

void part1(){
    sort(position.begin(), position.end());
    int median;
    if(position.size()%2==1){
        median=position.size()/2+1;
    }else{
        median=position.size()/2;
    }
    cout<<"median: "<<position[median]<<endl;
    int fuel=0;

    for(int i=0;i<position.size();i++){
        fuel+=(abs(position[median]-position[i]));
    }
    cout<<"Part 1 Fuel: "<<fuel<<endl;
}

void part2(){
    int sum=accumulate(position.begin(), position.end(),0);
    int mean1,mean2;

    mean1=floor((float)sum/position.size());
    mean2=ceil((float)sum/position.size());
    cout<<"mean1:"<<mean1<<endl;;
    cout<<"mean2:"<<mean2<<endl;;
    

    cout<<"position: ";
    for(int i=0;i<position.size();i++){
        cout<<position[i]<<" ";
    }
    cout<<endl;

    int fuel1=0,fuel2=0;
    cout<<"fuel1: ";
    for(int i=0;i<position.size();i++){
        int n=(abs(mean1-position[i]));
        fuel1+=(n*(n+1))/2;
        cout<<(abs(mean1-position[i]))<<" ";
    }
    cout<<endl;

    cout<<"fuel2: ";
    for(int i=0;i<position.size();i++){
        int n=(abs(mean2-position[i]));
        fuel2+=(n*(n+1))/2;
        cout<<(abs(mean2-position[i]))<<" ";
    }
    cout<<endl;

    cout<<"fuel1: "<<fuel1<<endl;
    cout<<"fuel2: "<<fuel2<<endl;
    cout<<"Part 2 Fuel: "<<min(fuel1,fuel2)<<endl;

}
int main(){
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
            position.push_back(num);
            i++;
        }
    }
    part1();
    part2();
    return 0;
}
// g++ --std=c++17 -Wall -Wextra BackspaceStringCompare.cpp && ./a.out