//Решение не прошло по времени
#include <iostream>
#include <vector>

int main() 
{
	int n;
	std::cin>>n;

	std::vector<std::pair<int, int>> podons;
	int x, y;
	for(int i=0; i<n; i++){
		std::cin>>x>>y;
		if(x < y){// Если x < y, меняем их местами
			y = y+x;
			x = y-x;
			y = y-x;
		}
	}
    flag = 0;
		for(auto i_podon = big_podons.begin(); i_podon != big_podons.end();){
			if(i_podon->first > x && i_podon->second > y){ // Мы можем положить новый поддон в старый
				flag = 1;
				break;
			}
			if(i_podon->first < x && i_podon->second < y){ // мы можем положить поддон, который до этого не могли, в новый поддон
                del_iter = i_podon;
                i_podon++;
				big_podons.erase(del_iter);
			}
            else{
                i_podon++;
            }
		}
		if(not(flag)){
			big_podons.push_back({x, y});
		}
	std::cout<<big_podons.size()<<std::endl;
	return 0;
}

#if 0
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main1() {
    int n, tmp1, tmp2;

    cin >> n;
    vector<pair<int, int>> pallets;
    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2;
        pallets.emplace_back(tmp1, tmp2);
        pallets.emplace_back(tmp2, tmp1);
    }

    sort(pallets.begin(), pallets.end(),
         [](const pair<int, int> & a, const pair<int, int> & b)
         {
             if (a.second == b.second) {
                 return a.first > b.first;
             }
             return a.second < b.second;
         });

    int ans = 0, max_cur = pallets[pallets.size() - 1].first;
    set<pair<int, int>> already;

    for (int i = pallets.size() - 1; i >= 0; i--) {
        auto p = pallets[i];

        if (p.first >= max_cur && already.count(p) == 0) {
            ans++;
            already.insert({p.second, p.first});
        }
        max_cur = max(max_cur, p.first);
    }
    return ans;
}

int main() {
    cout << main1();
    return 0;
}
#endif
/*
5
2 3
3 2
1 5
5 1
2 2
*/