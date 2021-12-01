#include <iostream>
using namespace std;

int main(){
    //PART1:
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