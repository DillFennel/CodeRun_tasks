#include <iostream>

using namespace std;

int razb(int n, int min_i){
    if(n==1 || n==min_i){return 1;}
    int ans = 1;
    for(int i=min_i; i<n/2+1; i++){//Переберем такие <Что-то>+i = n, При этом учитываем, что если до этого мы уже отнимали число, сейчас мы можем отнять только больше, чтобы последовательности не повторялись
        ans += razb(n-i, i);
    }
    return ans;
}

int main(){
    cout<<razb(5, 1);
}