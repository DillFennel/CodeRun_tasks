#include <iostream>
#include <list>

using namespace std;

int main(){
    int n;
    cin>>n;
    list<pair<int, int>> otrezki;
    int l, r;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        otrezki.push_back({l, r});
    }
    otrezki.sort();
    int dots = 0;
    int step=otrezki.front().first;
    int go_to =otrezki.front().second;
    while(not(otrezki.empty())){
        if(step == go_to){
            dots++;
            if(otrezki.empty()){
                break;
            }
            if(otrezki.front().first == step){
                otrezki.pop_front();
                if(otrezki.empty()){
                    break;
                }
            }
            step = otrezki.front().first;
            go_to = otrezki.front().second;
            otrezki.pop_front();
        }
        if(step == otrezki.front().first){
            if(otrezki.front().second < go_to){
                go_to = otrezki.front().second;
            }
            otrezki.pop_front();
        }
        step++;
    }
    cout<<dots;
}