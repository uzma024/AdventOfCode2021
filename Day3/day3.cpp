#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


void part1(){
    fstream newfile;
    newfile.open("input.txt");
    
    int count1[20],count0[20];
    
    for(int i=19;i>=0;i--){
        count1[i]=0;
        count0[i]=0;
    }
    // for(int i=19;i>=0;i--){
    //     cout<<count0[i]<<"  "<<count1[i]<<endl;
    // }
    int count;
    string tp;
    while(getline(newfile, tp)){
        count=tp.length();
        // cout<<tp<<endl;
        for(int i=0;i<tp.length();i++){
            if(tp[i]=='1'){
                count1[i]++;
            }else if(tp[i]=='0'){
                count0[i]++;
            }
        }
    }
    int gamma=0;
    int epsilon=0;
    
    for(int i=0;i<count;i++){
        
        if(count1[i]!=count0[i]){
            if(count1[i]>count0[i]){
                gamma=gamma*2+1;
                epsilon=epsilon*2;
            }else{
                gamma=gamma*2;
                epsilon=epsilon*2+1;
            }
        }
        
    }
    cout<<gamma*epsilon<<endl;
    newfile.close();

}

vector <string> oxygen;
vector <string> carbonDioxide;

void bitCriteriaOxygen(int n){
    int count1=0,count0=0;
    char mostcommon;
    for(int i=0;i<oxygen.size();i++){
        string s=oxygen[i];
        if(s[n]=='1'){
            count1++;
        }else{
            count0++;
        }
    }
    if(count1>=count0){
        mostcommon='1';
    }else{
        mostcommon='0';
    }
    //cout<<"mostCommon: "<<mostcommon<<endl;;
    for(int i=0;i<oxygen.size();i++){
        string s=oxygen[i];
        //cout<<s[n]<<" ";
        if(s[n]!=mostcommon){
             vector<string>::iterator it;
            it = oxygen.begin()+i;
            oxygen.erase(it);
            i--;
        }
    }
    // cout<<endl;
    // for(int i=0;i<oxygen.size();i++){
    //     cout<<i<<" "<<oxygen[i]<<endl;
    // }
    // cout<<endl;
}

void bitCriteriaCarbonDioxide(int n){
    int count1=0,count0=0;
    char leastcommon;
    for(int i=0;i<carbonDioxide.size();i++){
        string s=carbonDioxide[i];
        if(s[n]=='1'){
            count1++;
        }else{
            count0++;
        }
    }
    if(count1<count0){
        leastcommon='1';
    }else{
        leastcommon='0';
    }
    for(int i=0;i<carbonDioxide.size();i++){
        string s=carbonDioxide[i];
        if(s[n]!=leastcommon){
            vector<string>::iterator it;
            it = carbonDioxide.begin()+i;
            carbonDioxide.erase(it);
            i--;
        }
    }
}
void part2(){
    fstream newfile;
    newfile.open("input.txt");
    string tp;
    

    while(getline(newfile, tp)){
        oxygen.push_back(tp);
        carbonDioxide.push_back(tp);
    }

    int i=0;
    while(oxygen.size()>1){
        bitCriteriaOxygen(i);
        i++;
    }

    i=0;
    while(carbonDioxide.size()>1){
        bitCriteriaCarbonDioxide(i);
        i++;
    }
    
    int oxy=0,carb=0;

    for(int i=0;i<oxygen[0].length();i++){
        oxy=oxy*2+(oxygen[0][i]-'0');
        carb=carb*2+(carbonDioxide[0][i]-'0');
    }

    cout<<oxy*carb<<endl;

    newfile.close();
}


int main(){
    
    //part1();
    part2();
    return 0;
}