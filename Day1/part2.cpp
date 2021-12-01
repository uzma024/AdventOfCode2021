#include <iostream>
#include <vector>
using namespace std;

int main(){
    //PART2:
    int next;
    int ans=0;
    cin>>next;
    vector <int> v;

    while(next!=-1){
        v.push_back(next);
        cin>>next;
    }
    long prevSum=0;
    for(u_long i=0;i<v.size()-2;i++){
        long sum=v[i]+v[i+1]+v[i+2];
        cout<<sum<<endl;
        if(i>0 && sum>prevSum){
            ans++;
        }
        prevSum=sum;

    }
    cout<<ans<<endl;
    return 0;
}