#include <iostream>
#include <string>
#include <vector>
#include <list>

int main() 
{
	std::list<int> ans;
	int t;
	std::cin>>t;
	int n, k;
	int curr_sum, max_sum;
	std::list<int> thrown;
	std::list<int> thrown_over;
	std::vector<int> docs;
	int left, right;
	bool found_flag;
	for(int t1=0; t1<t; t1++){
		std::cin>>n>>k;
		docs.clear();
		std::cin>>max_sum;
		docs.push_back(max_sum);
		for(int i=1; i<n; i++){ //Попрбуем взять по одному документу
			std::cin>>curr_sum;
			if(max_sum < curr_sum){
				max_sum = curr_sum;
			}
			docs.push_back(curr_sum);
		}
		for(int n_docs=6; n_docs <= n; n_docs++){//Перебираем возможное кол-во элементов в выборки
			thrown.clear();
			thrown_over.clear();
			curr_sum = 0;
			for(int i=0; i<n_docs; i++){ //Наполняем первую выборку
				if(docs[i] >= 0){
					curr_sum += docs[i];
				}
				else{
					if(thrown.empty()){
						thrown.push_back(i);
					}
					else{
						auto docs_iter = thrown.begin();
						while(docs_iter != thrown.end() and docs[*docs_iter] <= docs[i]){
							docs_iter++;
						}
						thrown.insert(docs_iter, i);
						if(thrown.size() > k){
							curr_sum += docs[thrown.back()];
							auto docs_iter = thrown_over.begin();
							while(docs_iter != thrown_over.end() and docs[*docs_iter] <= docs[thrown.back()]){
								docs_iter++;
							}
							thrown_over.insert(docs_iter, thrown.back());
							thrown.pop_back();
						}
					}
				}
			}
			if(curr_sum > max_sum){
				max_sum = curr_sum;
			}
			left = 0; right = n_docs-1;
			do{
				//Двигаем левое
				if(docs[left] >= 0){
					curr_sum -= docs[left];
				}
				else{
					found_flag = 0;
					for(auto i = thrown.begin(); i != thrown.end(); i++){
						if(*i == left){
							found_flag = 1;
							thrown.erase(i);
							if(not(thrown_over.empty())){
								auto docs_iter = thrown.begin();
								while(docs_iter != thrown.end() and docs[*docs_iter] <= docs[thrown_over.front()]){
									docs_iter++;
								}
								thrown.insert(docs_iter, thrown_over.front());
								curr_sum-=docs[thrown_over.front()];
								thrown_over.pop_front();
							}
							break;
						}
					}
					if(not(found_flag)){
						curr_sum-=docs[left];
					}

					for(auto i = thrown_over.begin(); i != thrown_over.end(); i++){
						if(*i == left){
							thrown_over.erase(i);
							break;
						}
					}
				}
				left = (left+1)%n;
				//Двигаем правое
				right = (right+1)%n;
				if(docs[right] >= 0){
					curr_sum += docs[right];
				}
				else{
					if(thrown.empty()){
						thrown.push_back(right);
					}
					else{
						auto docs_iter = thrown.begin();
						while(docs_iter != thrown.end() and docs[*docs_iter] <= docs[right]){
							docs_iter++;
						}
						thrown.insert(docs_iter, right);
						if(thrown.size() > k){
							curr_sum += docs[thrown.back()];
							if(thrown_over.empty()){
								thrown_over.push_back(thrown.back());
							}
							else{
								docs_iter = thrown_over.begin();
								while(docs_iter != thrown_over.end() and docs[*docs_iter] <= docs[thrown.back()]){
									docs_iter++;
								}
								thrown_over.insert(docs_iter, thrown.back());
							}
							thrown.pop_back();
						}
					}
				}
                if(max_sum < curr_sum){
                    max_sum = curr_sum;
                }
			}while(left != 0 or right != n_docs-1);
		}
		ans.push_back(max_sum);
	}
	for(auto i: ans){
		std::cout<<i<<std::endl;
	}

	return 0;
}