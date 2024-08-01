/*
1. Запишіть блок try та оператор catch для відстеження та обробки простого виключення.
*/

#include <iostream>

int main()
{
    try
    {
        throw 10;
    }
    catch (int error)
    {
        std::cerr << "Error: " << error << std::endl;
    }
    return 0;
}
