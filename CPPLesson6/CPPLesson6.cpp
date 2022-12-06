// CPPLesson6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>

using namespace std;

class Human
{

};

class Aircraft
{

};

class Bus
{

};

class Car
{

};

class Train
{

};


class City
{
private:
    int id;
    string name;
    map<int, string> cities;
public:
    City(int cityid, string cityname, int distance[5], string citys[5]) : id{cityid}, name{ cityname } {
        
        for (int i = 0; i < 5; i++)
        {
            cities[distance[i]] = citys[i];
        }
    }

    friend ostream& operator<<(ostream& out, const City& city)
    {
        out << city.name << " id: " << city.id << "\n";
        out << "Доступные города: \n";
        for (auto& kv : city.cities)
            out << kv.second << ":" << kv.first << "км\n" ;       
        return out;
    }
};

class Path
{

};



int main()
{
    setlocale(LC_ALL, "");    
    City Moskva{ 0,"Москва",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Тверь", "Нижний Новгород", "Ярославль","Казань"} };
    City NN{ 0,"Нижний Новгород",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Тверь", "Нижний Новгород", "Ярославль","Казань"} };
    City Voronezh{ 0,"Воронеж",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Тверь", "Нижний Новгород", "Ярославль","Казань"} };
    City Rostov{ 0,"Ростов",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Тверь", "Нижний Новгород", "Ярославль","Шахты"} };
    City Brynsk{ 0,"Брянск",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Тверь", "Нижний Новгород", "Ярославль","Казань"} };

    City goroda[]{ Moskva,NN,Voronezh,Rostov,Brynsk };

    cout << goroda;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
