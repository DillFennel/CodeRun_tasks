#include <iostream>
#include <string>

int max(int a, int b){ //Функция для поиска максимума из двух переменных
    if(a > b){
        return a;
    }
    return b;
}
int main(){
    int n, m;
    std::cin>>n>>m; //Вводим размер массива
    int matrix[n][m]; //Создаем массив
    for(int y = 0; y<n; y++){
        for(int x = 0; x<m; x++){
            std::cin>>matrix[y][x]; //Зановим новое значение в массив
            if(y != 0){
                if(x != 0){//Есть пути и сверху, и слева
                    matrix[y][x] += max(matrix[y-1][x], matrix[y][x-1]);
                }
                else{
                    matrix[y][x] += matrix[y-1][x]; //Есть путь только сверху
                }
            }
            else{
                if(x != 0){
                    matrix[y][x] += matrix[y][x-1]; //Есть путь только слева
                }
            }
        }
    }
    std::cout<<matrix[n-1][m-1]<<std::endl;
    int y = n-1;
    int x = m-1;
    std::string path = ""; //Наш путь. Так как идем с конца в начало, заносим элементы справа налево
    while(y != 0 or x != 0){
        if(y != 0){
            if(x != 0 and matrix[y-1][x] < matrix[y][x-1]){
                path = "R " + path;
                x--;
            }
            else{
                path = "D " + path;
                y--;
            }
        }
        else{
            path = "R " + path;
            x--;
        }
    }
    
    std::cout<<path<<std::endl;
}