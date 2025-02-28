#include <iostream>
#include <bitset>

using namespace std;
int main(){
    int a = 32;
    bitset<5> b(a); //Превращаем int в bitset. Важно указать размер
    cout<<a<<" "<<b<<endl;
    cout<<"Count: "<<b.count()<<endl;
    cout<<"All: "<<b.all()<<endl;
    cout<<"Any: "<<b.any()<<endl;
    cout<<"Flip: "<<b.flip()<<endl;
    cout<<"None: "<<b.none()<<endl;
    b.reset();
    cout<<b<<": None: "<<b.none()<<endl;
    b.set(2);
    cout<<b<<endl;
    b.set();
    cout<<b<<endl;
}
/*

bitset<размер битсет> a(число) - создает битсет из числа
bitset.all() - проверяет, все ли элементы равны 1
bitset,any() - проверяет, равен ли единницы хотя бы один элемент
bitset.none() - проверяет, равны ли все элементы нулю
bitset.reset() - зануляет биты
bitset.set() - приводит к единице все или один бит
bitset.flip() - меняет 1 на 0 и 0 на 1

*/