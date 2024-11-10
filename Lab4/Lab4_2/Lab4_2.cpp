// Lab4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>

struct Adress
{
    std::string street;
    size_t house;
    size_t apartament;
};

struct Human
{
    std::string name;
    char male_or_female;
    std::size_t age;
    Adress adress;
};

struct City
{
    std::string title_of_city;
    std::map<size_t, std::string> streets;
};

int main()
{
    setlocale(LC_ALL, "ru");
    size_t count_of_cities;
    std::cout << "Введите количество городов\n";
    std::cin >> count_of_cities;
    std::map<size_t, City> cities;
    std::map<size_t, Human> humans;
    for (size_t i = 0; i < count_of_cities; ++i)
    {
        std::string title;
        City town;
        std::cout << "Введите название города\n";
        std::cin >> title;
        town.title_of_city = title;
        size_t count_of_streets;
        std::cout << "Введите количество улиц в городе " << i + 1 << std::endl;
        std::cin >> count_of_streets;
        for (size_t j = 0; j < count_of_streets; ++j)
        {
            std::cout << "Введите название улицы. В каждом городе хотя бы одна улица совпадает с какой-то улице в другом городе\n";
            std::string title_street;
            std::cin >> title_street;
            town.streets[j + 1] = title_street;
        }
        cities[i + 1] = town;
        size_t count_of_humans;
        std::cout << "Введите количество людей в этом городе\n";
        std::cin >> count_of_humans;
        for (size_t i = 0; i < count_of_humans; ++i)
        {
            Human hum;
            size_t age_of_human;
            char m_o_f;
            std::string name_of_human;
            std::string street_of_human;
            size_t house_of_human;
            size_t apartament_of_human;
            std::cout << "Введите имя человека\n";
            std::cin >> name_of_human;
            std::cout << "Введите пол человека\n";
            std::cin >> m_o_f;
            hum.male_or_female = m_o_f;
            hum.name = name_of_human;
            std::cout << "Введите возраст человека\n";
            std::cin >> age_of_human;
            hum.age = age_of_human;
            Adress adr;
            std::cout << "Введите адрес человека: улица (из этого города), дом, квартира(через Enter)\n";
            std::cin >> street_of_human;
            std::cin >> house_of_human;
            std::cin >> apartament_of_human;
            adr.street = street_of_human;
            adr.house = house_of_human;
            adr.apartament = apartament_of_human;
            hum.adress = adr;
            humans[i + 1] = hum;
        }
    }
    size_t count_of_prizivniki = 0;
    for (size_t j = 0; j < humans.size(); ++j)
    {
        if (humans[j].age > 17 && humans[j + 1].age < 27 && humans[j + 1].male_or_female == 'M')
        {
            ++count_of_prizivniki;
        }
    }
    std::cout << count_of_prizivniki;
}

