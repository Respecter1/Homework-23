/*
	5. Жучки: що неправильно в наступному коді?
    Відповідь:
               - Використання std::string замість char*.
               - Використання std::make_unique для створення об'єктів з автоматичним управлінням пам'яттю.
               - Передача винятків за значенням, що забезпечує коректне звільнення пам'яті.
*/

#include <iostream>
#include <string>
#include <memory> // Для std::unique_ptr

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
    Даний приклад містить потенційну помилку, подібну до спроби виділити пам'ять для показу повідомлення про помилку у разі виявлення нестачі вільної пам'яті.

	Ви можете протестувати цю програму, змінивши рядок if (var == 0) на if (1), що викликає створення винятку.
*/

