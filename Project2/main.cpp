/*
	2. Додайте у виняток, отриманий у вправі 1, змінну-член та метод доступу та використовуйте їх у блоці оператора catch.
*/

#include <iostream>

class MyException
{
private:
    int errorCode;
    int errorMessageCode; // Код повідомлення про помилку

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
        throw MyException(10, 404); // Наприклад, 404 представляє повідомлення про помилку "Не знайдено"
    }
    catch (const MyException& ex)
    {
        std::cerr << "Error code: " << ex.getErrorCode() << ", Message code: " << ex.getErrorMessageCode() << std::endl;
    }
    return 0;
}
