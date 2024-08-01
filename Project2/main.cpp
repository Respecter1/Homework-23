/*
	2. ������� � �������, ��������� � ����� 1, �����-���� �� ����� ������� �� �������������� �� � ����� ��������� catch.
*/

#include <iostream>

class MyException
{
private:
    int errorCode;
    int errorMessageCode; // ��� ����������� ��� �������

public:
    MyException(int code, int messageCode)
        : errorCode(code), errorMessageCode(messageCode) {}

    int getErrorCode() const
    {
        return errorCode;
    }

    int getErrorMessageCode() const
    {
        return errorMessageCode;
    }
};

int main()
{
    try
    {
        throw MyException(10, 404); // ���������, 404 ����������� ����������� ��� ������� "�� ��������"
    }
    catch (const MyException& ex)
    {
        std::cerr << "Error code: " << ex.getErrorCode() << ", Message code: " << ex.getErrorMessageCode() << std::endl;
    }
    return 0;
}
