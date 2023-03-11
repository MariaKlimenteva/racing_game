#include <iostream>
#include <memory>
#include <string>
#include <vector>

class User
{
 public:
    User();
    void Make_bet(int lot_name, int bid); //метод - сделать ставку
    std::vector<string> lots;
}

class Lot //один лот, описание этого состояния
{
 public:
    Lot(); //конструктор
    int lot_value = 1; //начальная цена лота, которая изменяется потом
    void Introduce(string lot_name, int lot_value);
    std::vector<string> users;
}

class Auction
{
 public:
    Auction();
    int max_lot = 15;
    std::vector<string> lot_name;
    void print_list_of_lots(std::vector<string> lot_name);
}

//vector::push_back - вставить элемент в конец вектора