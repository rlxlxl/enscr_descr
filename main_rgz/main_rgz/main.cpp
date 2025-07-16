#include "gronspheld.h"
#include "matrix.h"

#include <iostream>
#include <locale>
#include <cwctype>
#include <string>


using namespace std;



int main()
{
    locale::global(locale("ru_RU.UTF-8"));
    wcin.imbue(locale());
    wcout.imbue(locale());

    wstring text = L"яяяя";
    string key = "123";

    wcout << gronspheldTransformed(text, key, false) << endl; // Дешифрование
    simpleMatrixEcrypt("3124", L"математика", true);
}
