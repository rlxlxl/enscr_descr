#include "gronspheld.h"

#include <cwctype>
#include <string>

using namespace std;

bool isRussian(const wchar_t symbol)
{
    return (symbol >= L'А' && symbol <= L'Я') || (symbol >= L'а' && symbol <= L'я');
}

wstring gronspheldTransformed(wstring &text, const string &key, bool encrypt)
{
    size_t keyLen = key.length();
    wstring result = L"";

    const int RU_ALPHABET_SIZE = 32;
    const int EN_ALPHABET_SIZE = 26;

    for (size_t symbol = 0; symbol < text.length(); ++symbol)
    {
        int shift = key[symbol % keyLen] - '0';

        if (iswspace(text[symbol]))
        {
            result += text[symbol];
        }
        else if (isRussian(text[symbol]))
        {
            wchar_t base = iswupper(text[symbol]) ? L'А' : L'а';

            if (encrypt)
            {
                result += static_cast<wchar_t>(base + (text[symbol] - base + shift) % RU_ALPHABET_SIZE);

            }
            else
            {
                result += static_cast<wchar_t>(base + (text[symbol] - base - shift + RU_ALPHABET_SIZE) % RU_ALPHABET_SIZE);

            }
        }
        else
        {
            wchar_t base = iswupper(text[symbol]) ? L'A' : L'a';

            if (encrypt)
            {
                result += static_cast<wchar_t>(base + (text[symbol] - base + shift) % EN_ALPHABET_SIZE);
            }
            else
            {
                result += static_cast<wchar_t>(base + (text[symbol] - base - shift + EN_ALPHABET_SIZE) % EN_ALPHABET_SIZE);
            }
        }
    }

    return result;
}

