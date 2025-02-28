#include <iostream>
#include <cmath>

using namespace std;

int n_key(int x, int y){
    if(y%x != 0){
        return 0;
    }
    if(y/x == 1){
        return 1;
    }
    int ans = 2;
    for(int i=2; i<y/x; i++){
        if((y/x)%i==0 && (((y/x)/i > i && ((y/x)/i)%i!=0) || ((y/x)/i < i && i%((y/x)/i)!=0))){
            ans++;
        }
    }
    return ans;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<n_key(x, y);
}