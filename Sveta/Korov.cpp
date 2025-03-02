#include <iostream>
#include <list>

using namespace std;

bool try_len(list<int>& stoila, int korov, int len){
    int pre_stoilo = stoila.front();
    korov--; //Одну коровы поместили в первое стойло
    list<int>::iterator i = stoila.begin();
    i++;
    for(;i != stoila.end(); i++){
        if(*i >= pre_stoilo+len+1){
            korov--;
            pre_stoilo = *i;
        }
    }
    if(korov <= 0){
        return true;
    }
    return false;
}

int main(){
    int n_stoil, n_korov;
    cin>>n_stoil>>n_korov;
    list<int> stoila;
    int inp_value;
    for(int i=0; i<n_stoil; i++){
        cin>>inp_value;
        stoila.push_back(inp_value);
    }
    int l=0, r=stoila.back()-stoila.front();
    while(r - l > 1){
        if(try_len(stoila,  n_korov, (r+l)/2)){
            l = (r+l)/2;
        }
        else{
            r = (r+l)/2;
        }
    }
    cout<<l;
}