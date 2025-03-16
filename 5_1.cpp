#include <iostream>
#include <vector>

int min(int a, int b){
    if(a > b){
        return b;
    }
    return a;
}
int main(){
    int n;
    std::cin>>n;

    int koup_num [n][n];
    int price;
    std::cin>>price;
    koup_num[0][0] = price;
    if(price > 100){
        koup_num[0][1]=price;
    }
    else{
        koup_num[0][1]=-1;
    }
    for(int day = 1; day<n; day++){
        std::cin>>price;
        koup_num[day][0] = koup_num[day-1][0];
        if(price>100){
            for(int k=1; k<day; k++){
                koup_num[day][k] = min(koup_num[day-1][k-1] + price, koup_num[day-1][k+1]);
            }
            koup_num[day][-2] = koup_num[day-1][-1]+price;
            koup_num[day][-1] = koup_num[day-1][-1]+price;
        }
        else{
            for(int k=1; k<day; k++){
                koup_num[day][k] = min(koup_num[day-1][k-1] + price, koup_num[day-1][k+1]);
            }
            koup_num[day][-2] = koup_num[day-1][-1]+price;
        }
    }
    
}