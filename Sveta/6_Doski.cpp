#include <iostream>
#include <list>

using namespace std;

bool check(list<int> &doski, int n_workers, int try_work){
    int cur_work = 0, n_worker_check = 1;
    for(int i: doski){
        if(cur_work + i > try_work){
            cur_work = i;
            n_worker_check++;
        }
        else{
            cur_work+=i;
        }
    }
    if(n_worker_check <= n_workers){
        return true;
    }
    return false;
}

int main(){
    int n, n_workers;
    cin>>n>>n_workers;
    list<int> doski;
    int inp_value;
    int r=0;
    for(int i=0; i<n; i++){
        cin>>inp_value;
        r+=inp_value;
        doski.push_back(inp_value);
    }
    int l=0;
    while(r-l > 1){
        if(check(doski, n_workers, (r+l)/2)){
            r = (r+l)/2;
        }
        else{
            l = (r+l)/2;
        }
    }
    cout<<r;
}