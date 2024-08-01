/*
	3. Успадкуйте новий виняток від виключення, отриманого у вправі 2
    . Змініть блок оператора catch таким чином, щоб у ньому відбувалася обробка як похідного
    , так і базового виключення.
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

int main()
{
    try
    {
        throw DerivedException(10, 404, "Additional information here");
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
