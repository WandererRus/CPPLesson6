// CPPLesson6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <list>

using namespace std;

class Human
{
private: 
    string name;
    string surname;
    double money;
    int time;
public:
    Human() : name{ "John" }, surname{ "Smith" }, money{ 15000.0 }, time{ 20 } {}

    Human(string n, string s, double m, int t) : name{ n }, surname{ s }, money{ m }, time{ t } {}
    
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

class CityMassive
{
private: 
    map <int,City> cities;
public:
    CityMassive(City cmassive[]) {
        for (int i = 0; i < 5; i++)
        {
            cities[i] = cmassive[i];
        }
    }

    void display() 
    {
        for (auto& city : cities)
           cout << city.second;
    }

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



    int getCityID()
    {
        return id;
    }
    string getCityName()
    {
        return name;
    }
    int getCitiesDistance(string name) 
    {
        int distance = 0;
        for (auto& kv : cities)
            if (kv.second == name) distance = kv.first;
        return distance;
    }
    list<string> getCitiesRoute() 
    {
        list<string> buflist;
        for (auto& kv : cities)
            buflist.push_back(kv.second);
        return buflist;
    }
};

class Path
{
private:
    int distanceToNeedCity = 0;
    Human human;
    City currentCity;
    City destinationCity;

    void setDistance(int value)
    {
        distanceToNeedCity = value;
    }
public:
    Path(Human h, City cc, City dc) : human{ h }, currentCity{ cc }, destinationCity{ dc } {}

    void findPaths(City MCity[])
    {        
        list<string> findedCities2;
        list<string> findedCities;
        int bufId;
        string destName = destinationCity.getCityName();
        for (int i = 0; i < 5; i++)
        {            
            if (MCity[i].getCityName() == currentCity.getCityName())
            {
                bufId = MCity[i].getCityID();
                findedCities = MCity[i].getCitiesRoute();

                for (auto& cityname : findedCities)
                    if (cityname == destName)
                    {
                       setDistance(currentCity.getCitiesDistance(cityname));
                    }
                if (!distanceToNeedCity)
                {
                    for (auto& cityname : findedCities)
                        if (cityname == destName)
                        {
                            findedCities2 = MCity[i].getCitiesRoute();
                        }
                }

            }
        }


        /*
        Проверяем список городов на наличие городов доступных из CurrentCity
        Получить города которые доступные из городов связанных с CurrentCity // NN, Bryansk
        Проверить является ли полученные города точкой назначения
           Если да то возвращаем путь
        Проверяем список городов на наличие городов доступных из CurrentCity
        Получить города которые доступные из городов связанных с CurrentCity // NN, Bryansk
        Проверить является ли полученные города точкой назначения
           Если да то возвращаем путь
        
        
        
        */
    } 

    void displayPath()
    {
        cout << distanceToNeedCity << "км\n";
    }

};



int main()
{
    setlocale(LC_ALL, "");    
    City Moskva{ 0,"Москва",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Тверь", "Нижний Новгород", "Ярославль","Казань"} };
    City NN{ 0,"Нижний Новгород",new int[5] {200,300,400,500,600},new string[5]{"Муром", "Ульяновск", "Арзамас", "Ярославль","Казань"} };
    City Voronezh{ 0,"Воронеж",new int[5] {200,300,400,500,600},new string[5]{"Брянск", "Белгород", "Ростов", "Волгоград","Саратов"} };
    City Rostov{ 0,"Ростов",new int[5] {200,300,400,500,600},new string[5]{"Краснодар", "Волгоград", "Воронеж", "Харьков","Шахты"} };
    City Brynsk{ 0,"Брянск",new int[5] {200,300,400,500,600},new string[5]{"Москва", "Воронеж", "Смоленск", "Гомель","Тула"} };

    City goroda[]{ Moskva,NN,Voronezh,Rostov,Brynsk };
    CityMassive cm(goroda);
    
    Human ivan("Ivan","Ivanov",20000.0,24);
    Path moskvavoronezh(ivan, Moskva, Voronezh);
    moskvavoronezh.findPaths(goroda);
    moskvavoronezh.displayPath();
    cm.display();

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
