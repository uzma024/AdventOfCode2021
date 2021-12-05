#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void part1(){
    int array[1000][1000]={0};

    fstream newfile;
    newfile.open("input.txt");
    string tp;
    

    while(getline(newfile, tp)){
        int i=0,num=0,x1,x2,y1,y2;
        while(tp[i]!=','){
            num=num*10+(tp[i]-'0');
            i++;
        }
        x1=num;
        i++;
        num=0;
        while(tp[i]!=' '){
            num=num*10+(tp[i]-'0');
            i++;
        }
        y1=num;
        i+=4;
        num=0;
        while(tp[i]!=','){
            num=num*10+(tp[i]-'0');
            i++;
        }
        x2=num;
        i++;
        num=0;
        while(i<tp.length()){
            num=num*10+(tp[i]-'0');
            i++;
        }
        y2=num;

        if(x1==x2){
            if(y2<y1){
                while(y2<=y1){
                    array[x1][y2]++;
                    y2++;
                }
                
            }else{
                while(y1<=y2){
                    array[x1][y1]++;
                    y1++;
                }
            }
        }else if(y2==y1){
            if(x2<x1){
                while(x2<=x1){
                    array[x2][y1]++;
                    x2++;
                }
                
            }else{
                while(x1<=x2){
                    array[x1][y1]++;
                    x1++;
                }
            }
        }

    }
    int count=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(array[i][j]>=2){
                count++;
            }
        }
    }
    cout<<count;
}

void part2(){
    int array[1000][1000]={0};

    fstream newfile;
    newfile.open("input.txt");
    string tp;
    

    while(getline(newfile, tp)){
        int i=0,num=0,x1,x2,y1,y2;
        while(tp[i]!=','){
            num=num*10+(tp[i]-'0');
            i++;
        }
        x1=num;
        i++;
        num=0;
        while(tp[i]!=' '){
            num=num*10+(tp[i]-'0');
            i++;
        }
        y1=num;
        i+=4;
        num=0;
        while(tp[i]!=','){
            num=num*10+(tp[i]-'0');
            i++;
        }
        x2=num;
        i++;
        num=0;
        while(i<tp.length()){
            num=num*10+(tp[i]-'0');
            i++;
        }
        y2=num;

        if(x1==x2){
            if(y2<y1){
                while(y2<=y1){
                    array[x1][y2]++;
                    y2++;
                }
                
            }else{
                while(y1<=y2){
                    array[x1][y1]++;
                    y1++;
                }
            }
        }else if(y2==y1){
            if(x2<x1){
                while(x2<=x1){
                    array[x2][y1]++;
                    x2++;
                }
                
            }else{
                while(x1<=x2){
                    array[x1][y1]++;
                    x1++;
                }
            }
        }else if(abs(y2-y1)==abs(x2-x1)){
            if(x2-x1>0 && y2-y1>0){
                while(x1<=x2 && y1<=y2){
                    array[x1][y1]++;
                    x1++;
                    y1++;
                }
            }else if(x2-x1<0 && y2-y1<0){
                while(x2<=x1 && y2<=y1){
                    array[x2][y2]++;
                    x2++;
                    y2++;
                }
            }else if(x2-x1>0 && y2-y1<0){
                while(x1<=x2 && y1>=y2){
                    array[x1][y1]++;
                    x1++;
                    y1--;
                }
            }else if(x2-x1<0 && y2-y1>0){
                while(x1>=x2 && y1<=y2){
                    array[x1][y1]++;
                    x1--;
                    y1++;
                }
            }
        }

    }
    int count=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(array[i][j]>=2){
                count++;
            }
        }
    }
    cout<<count;
}

int main(){
    //part1();
    part2();
    return 0;
}
