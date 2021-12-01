#include <iostream>
using namespace std;

int main(){
    int ans=0,prev,next;
    cin>>prev;
    cin>>next;
    while(next!=-1){
        if(next>prev){
            ans++;
        }
        prev=next;
        cin>>next;
    }
    cout << ans << endl;
    return 0;
}
// g++ --std=c++17 -Wall -Wextra day1.cpp && ./a.out  