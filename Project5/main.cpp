/*
	5. �����: �� ����������� � ���������� ���?
    ³������:
               - ������������ std::string ������ char*.
               - ������������ std::make_unique ��� ��������� ��'���� � ������������ ���������� ���'����.
               - �������� ������� �� ���������, �� ��������� �������� ��������� ���'��.
*/

#include <iostream>
#include <string>
#include <memory> // ��� std::unique_ptr

using namespace std;

class xOutOfMemory
{
public:
    xOutOfMemory() : theMsg(make_unique<string>("error in memory")) {}

    const char* Message() const { return theMsg->c_str(); }

private:
    unique_ptr<string> theMsg;
};

int main()
{
    try
    {
        auto var = make_unique<char>();
        if (!var)
        {
            throw xOutOfMemory();
        }
    }
    catch (const xOutOfMemory& theException)
    {
        cout << theException.Message() << endl;
    }
    catch (const bad_alloc&)
    {
        cout << "Standard bad_alloc exception caught: insufficient memory." << endl;
    }
    return 0;
}

/*
    ����� ������� ������ ���������� �������, ������ �� ������ ������� ���'��� ��� ������ ����������� ��� ������� � ��� ��������� ������� ����� ���'��.

	�� ������ ������������ �� ��������, ������� ����� if (var == 0) �� if (1), �� ������� ��������� �������.
*/

