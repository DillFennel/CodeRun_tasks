#include <iostream>

int main(){
    int n;
    std::cin>>n;
    int val[n];
    for(int i=0; i<n; i++){
        val[i] = 1;
    }
    for(int cur_div = 2; cur_div <= n; cur_div++){
        for(int i=cur_div-1; i<n; i=i+cur_div){
            val[i]++;
        }
    }
    int max_div = 0;
    for(int i=0; i<n; i++){
        if(val[i] >= val[max_div]){
            max_div = i;
        }
    }
    std::cout<<max_div+1<<std::endl<<val[max_div];
    return 0;
}