#include <iostream>
#include <list>

using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    list<int> spisok_1, spisok_2;
    int inp_val;
    for(int i=0; i<n; i++){
        cin>>inp_val;
        spisok_1.push_back(inp_val);
    }
    for(int i=0; i<m; i++){
        cin>>inp_val;
        spisok_2.push_back(inp_val);
    }
    list<int>::iterator it_1 = spisok_1.begin(), it_2 = spisok_2.begin();
    list<int> res;
    while(it_1 != spisok_1.end() || it_2 != spisok_2.end()){
        if(it_1 != spisok_1.end()){
            if(it_2 != spisok_2.end()){
                if(*it_1 < *it_2){
                    res.push_back(*it_1);
                    it_1++;
                }
                else{
                    res.push_back(*it_2);
                    it_2++;
                }
            }
            else{
                res.push_back(*it_1);
                it_1++;
            }
        }
        else{
            res.push_back(*it_2);
            it_2++;
        }
    }
    for(auto i: res){
        cout<<i<<" ";
    }
}