#include <iostream>

int main() 
{
	int n, m;
    std::cin>>n>>m;
    int matrix [n][m];
    for(int i=1; i<n; i++){//Сначала заполним нулями ячейки, куда точно попасть не сможем никак
        matrix[i][0] = 0;
    }
    for(int i=1; i<m; i++){
        matrix[0][i] = 0;
    }
    matrix[0][0] = 1; //Тут мы начинаем, поэтому тут путь один
    for(int y=1; y<n; y++){
        for(int x=1; x<m; x++){
            matrix[y][x] = 0;
            if(y>1 and x>0){ //Сюда можно попасть ходом 2 вниз 1 вправо
                matrix[y][x] += matrix[y-2][x-1];
            }
            if(y>0 and x>1){ //Сюда можно попасть ходом 1 вниз 2 вправо
                matrix[y][x] += matrix[y-1][x-2];
            }
        }
    }
    std::cout<<matrix[n-1][m-1];
	return 0;
}