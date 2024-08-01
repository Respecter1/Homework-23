/*
	4. Змініть код вправи 3, щоб отримати трирівневий виклик функції.
*/

#include <iostream>
#include <string>

class MyException
{
private:
    int errorCode;
    int errorMessageCode;

public:
    MyException(int code, int messageCode)
        : errorCode(code), errorMessageCode(messageCode) {}

    virtual ~MyException() {}

    int getErrorCode() const
    {
        return errorCode;
    }

    int getErrorMessageCode() const
    {
        return errorMessageCode;
    }
};

class DerivedException : public MyException
{
private:
    std::string additionalInfo;

public:
    DerivedException(int code, int messageCode, const std::string& info)
        : MyException(code, messageCode), additionalInfo(info) {}

    std::string getAdditionalInfo() const
    {
        return additionalInfo;
    }
};

void functionLevel3()
{
    throw DerivedException(10, 404, "Additional information here");
}

void functionLevel2()
{
    functionLevel3();
}

void functionLevel1()
{
    functionLevel2();
}

int main()
{
    try
    {
        functionLevel1();
    }
    catch (const DerivedException& ex)
    {
        std::cerr << "Derived Exception - Error code: " << ex.getErrorCode()
            << ", Message code: " << ex.getErrorMessageCode()
            << ", Additional info: " << ex.getAdditionalInfo() << std::endl;
    }
    catch (const MyException& ex)
    {
        std::cerr << "Base Exception - Error code: " << ex.getErrorCode()
            << ", Message code: " << ex.getErrorMessageCode() << std::endl;
    }
    return 0;
}
