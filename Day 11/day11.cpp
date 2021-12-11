#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

vector <vector <int> > octo;
bool flashed[10][10];

int TotalFlashes=0;

bool check(){
    bool flag=true;
    for(int i=0;i<10 && flag;i++){
        for(int j=0;j<10;j++){
            if(octo[i][j]!=0){
                flag=false;
                break;
            }
        }
    }
    return flag;
}

void printOcto(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<< octo[i][j]<<" ";
        }
        for(int j=0;j<10;j++){
            cout<<"    "<<flashed[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void flash(int i,int j){
    TotalFlashes++;
    flashed[i][j]=true;
    octo[i][j]=0;

    if(i>0 && !flashed[i-1][j]){
        octo[i-1][j]++;
        if(octo[i-1][j]>9){
            flash(i-1,j);
        }
    }
    if(i<9 && !flashed[i+1][j]){
        octo[i+1][j]++;
        if(octo[i+1][j]>9){
            flash(i+1,j);
        }
    }
    if(j<9 && !flashed[i][j+1]){
        octo[i][j+1]++;
        if(octo[i][j+1]>9){
            flash(i,j+1);
        }
    }
    if(j>0 && !flashed[i][j-1]){
        octo[i][j-1]++;
        if(octo[i][j-1]>9){
            flash(i,j-1);
        }
    }
    if(i>0 && j>0 && !flashed[i-1][j-1]){
        octo[i-1][j-1]++;
        if(octo[i-1][j-1]>9){
            flash(i-1,j-1);
        }
    }
    if(i<9 && j<9 && !flashed[i+1][j+1]){
        octo[i+1][j+1]++;
        if(octo[i+1][j+1]>9){
            flash(i+1,j+1);
        }
    }
    if(i>0 && j<9 && !flashed[i-1][j+1]){
        octo[i-1][j+1]++;
        if(octo[i-1][j+1]>9){
            flash(i-1,j+1);
        }
    }
    if(i<9 && j>0 && !flashed[i+1][j-1]){
        octo[i+1][j-1]++;
        if(octo[i+1][j-1]>9){
            flash(i+1,j-1);
        }
    }
    
}

void part2(){
    int steps=0;
    TotalFlashes=0;
    while(!check()){
        steps++;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                flashed[i][j]=false;
                octo[i][j]++;
            }
        }

        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(octo[i][j]>9 ){
                    if(!flashed[i][j]){
                        flash(i,j);
                    }
                }
            }
        }
        // printOcto();
        
    }

    cout<<"Part2= Simultaneous flash at step no: "<<steps<<endl;
    
}


int main(){
    fstream newfile;
    newfile.open("input.txt");
    string tp;
    
    
    while(getline(newfile, tp)){
        vector <int> vec;
        for(int i=0;i<10;i++){
            vec.push_back(tp[i]-'0');
        }
        octo.push_back(vec);
    }

    part2();
    return 0;
}
// g++ --std=c++17 -Wall -Wextra day11.cpp && ./a.out