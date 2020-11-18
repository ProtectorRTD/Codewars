// Check that the situation is correct.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdbool.h>

bool is_it_possible(const char* field)
{
    int count = 0, countd = 0, d = 0, b = 0, gap = 0;
    int player1 = 0, player2 = 0;
    for (int k = 0; k < strlen(field); k++)
    {
        if (field[k] == 'X') d++, count++;
        if (field[k] == '0') b++, countd++;
    }
    if (count - countd > 1 || countd > count) return false;
    for (int i = 0; i < 3; i++)
    {
        if (field[i] == 'X' && field[i + 3] == 'X' && field[i + 6] == 'X') player1++;
        if (field[i] == '0' && field[i + 3] == '0' && field[i + 6] == '0') player2++;
    }
    if (field[0] == 'X' && field[4] == 'X' && field[8] == 'X') player1++;
    if (field[0] == '0' && field[4] == '0' && field[8] == '0') player2++;
    if (field[2] == 'X' && field[4] == 'X' && field[6] == 'X') player1++;
    if (field[2] == '0' && field[4] == '0' && field[6] == '0') player2++;
    for (int i = 0; i < strlen(field); i += 3)
    {
        d = 0, b = 0;
        for (int j = i; j < i + 3; j++)
        {
            if (field[j] == 'X') d++;
            if (field[j] == '_') gap++;
            if (field[j] == '0') b++;
        }
        if (d == 3) player1++;
        if (b == 3) player2++;
    }
    if (player1 == 0 && player2 == 0) return true;
    if (player1 >= 1 && player2 == 0 && count != countd) return true;
    if (player2 >= 1 && player1 == 0 && count == countd) return true;
    else
    {
        return false;
    }
}

