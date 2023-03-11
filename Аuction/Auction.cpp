#include "Auction.h"

Auction::Auction() // создание списков людей, лотов
{
    srand(time(NULL));
    for (int i = 0; i < max_lot; i++)
    {
        lot_name[i] = 97 + rand() % 25;
    }

    
}
// деструктор : удаление человека или лота из списка аукциона

void print_list_of_lots(std::vector<string> lot_name)
{
    for (int i = 0; i < max_lot; i++)
    {
        std::cout << lot_name[i] << "\n" << std::endl;
    }
}