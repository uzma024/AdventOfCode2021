#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector <int> fish;

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
    long long extra=0;
    for(int i=0;i<256;i++){
        for(int j=fish.size()-1;j>=0;j--){
            if(fish[j]==0){
                if(fish.size()>=2153338313){
                    extra++;
                }
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
    cout<<2153338313+extra<<endl;

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
    part1();
    return 0;
}
