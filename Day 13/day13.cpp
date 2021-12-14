#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<vector <int> >fold;
int maxX=INT_MIN,maxY=INT_MIN;
int grid[1500][1500];   

void print(){
    for(int i=0;i<=maxY;i++){
        for(int j=0;j<=maxX;j++){
            if(grid[i][j]==1){
                cout<<'#';
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void PaperFold(int corr,int pos){
    if(corr==0 && maxX>=pos){
        for(int i=1;i+pos<=maxX && pos-i>=0;i++){
            for(int j=0;j<=maxY;j++){
                if(grid[j][pos-i]==0 && grid[j][pos+i]==1){
                    grid[j][pos-i]=1;
                }
            }
        }
        maxX=pos-1;
    }
    else if(corr==1 && maxY>=pos){
        for(int i=1;i+pos<=maxY && pos-i>=0;i++){
            for(int j=0;j<=maxX;j++){
                if(grid[pos-i][j]==0 && grid[pos+i][j]==1){
                    grid[pos-i][j]=1;
                }
                
            }
        }
        maxY=pos-1;
    }
    
}

int count(){
    int countOfDots=0;
    for(int i=0;i<=maxY;i++){
        for(int j=0;j<=maxX;j++){
            if(grid[i][j]==1){
                countOfDots++;
            }
        }
    }
    return countOfDots;
}
void part1(){
    PaperFold(fold[0][0],fold[0][1]);
    print();
    cout <<"Ans:"<<count()<<endl;
}
void part2(){
    for(int i=0;i<fold.size();i++){
        PaperFold(fold[i][0],fold[i][1]);
    }
    print();
    cout <<"Ans:"<<count()<<endl;
}

int main(){
    fstream newfile;
    newfile.open("input.txt");
    string tp;
   
    /*  x/y  shift
    x=0;
    y=1;
    */

    while(getline(newfile, tp)){
        if(tp[0]!='f'){
            int x=0,y=0,i=0;
            while(tp[i]!=','){
                x=x*10+(tp[i]-'0');
                i++;
            }
            i++;
            while(i<tp.length()){
                y=y*10+(tp[i]-'0');
                i++;
            }
            // cout<<x<<" "<<y<<endl;
            maxX=max(x,maxX);
            maxY=max(y,maxY);
            grid[y][x]=1;
        }else{
            int n=0, i=13;
            while(i<tp.length()){
                n=n*10+(tp[i]-'0');
                i++;
            }
            vector <int> v;
            if( tp[11]=='x'){
                v.push_back(0);
                v.push_back(n);
            }else if( tp[11]=='y'){
                v.push_back(1);
                v.push_back(n);
            }
            fold.push_back(v);
        }
    }
    // part1();
    part2();
    return 0;
}
