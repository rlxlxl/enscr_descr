#include "matrix.h"

#include <string>
#include <cwctype>
#include <vector>
#include <iostream>

using namespace std;

void simpleMatrixEcrypt(const string& key, const wstring& text, bool encrypt)
{
    wstring result = L"";
    
    int colm = key.size(); // число столбцов
    int rows = ceil(static_cast<double>(text.length()) / colm); // число строк
    
    if (encrypt)
    {
        vector<vector<wchar_t>> matrix(rows, vector<wchar_t>(colm, L'.')); // ← L'.'
        
        for (int i = 0; i < text.length(); ++i)
        {
            int row = i / colm;
            int col = i % colm;
            matrix[row][col] = text[i];
        }
        
        wcout << "Результат шифровки: ";
        
        for (int order = 1; order <= colm; ++order)
        {
            for (int col = 0; col < colm; ++col)
            {
                if ((key[col] - '0') == order)
                {
                    for (int row = 0; row < rows; ++row)
                    {
                        if (matrix[row][col] != L'.')
                        {
                            result += matrix[row][col];
                        }
                    }
                }
            }
        }
        wcout << result << endl;
    }
    else
    {
        vector<vector<wchar_t>> matrix(rows, vector<wchar_t>(colm, L'.'));
        int index = 0;

        for (int order = 1; order <= colm; ++order)
        {
            for (int col = 0; col < colm; ++col)
            {
                if ((key[col] - '0') == order)
                {
                    for (int row = 0; row < rows; ++row)
                    {
                        if (row * colm + col < text.length())
                        {
                            if (index < text.length())
                            {
                                matrix[row][col] = text[index++];
                            }
                        }
                    }
                }
            }
        }
        wcout << L"Результат дешифровки: ";
        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < colm; ++col)
            {
                if (matrix[row][col] != L'.')
                {
                    result += matrix[row][col];
                }
            }
        }

        wcout << result << endl;
    }
}

