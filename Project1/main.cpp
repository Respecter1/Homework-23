/*
1. �������� ���� try �� �������� catch ��� ���������� �� ������� �������� ����������.
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
