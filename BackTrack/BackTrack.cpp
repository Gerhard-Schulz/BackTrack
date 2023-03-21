#include <stdio.h>
#include <string.h>

// Шахматная доска N × N
#define N 8

// Функция для проверки, угрожают ли два ферзя друг другу или нет
int isSafe(char mat[][N], int r, int c)
{
    // возвращаем 0, если два ферзя делят один и тот же столбец
    for (int i = 0; i < r; i++)
    {
        if (mat[i][c] == 'Q') 
        {
            return 0;
        }
    }

    // вернуть 0, если два ферзя делят одну и ту же диагональ
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j] == 'Q') 
        {
            return 0;
        }
    }

    // вернуть 0, если два ферзя делят одну и ту же диагональ /
    for (int i = r, j = c; i >= 0 && j < N; i--, j++)
    {
        if (mat[i][j] == 'Q') 
        {
            return 0;
        }
    }

    return 1;
}

void printSolution(char mat[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void nQueen(char mat[][N], int r)
{
    // если N ферзей расставлены успешно, выводим решение
    if (r == N)
    {
        printSolution(mat);
        return;
    }

    // помещаем ферзя на каждую клетку в текущем ряду r
    // и повторяться для каждого допустимого движения
    for (int i = 0; i < N; i++)
    {
        // если никакие два ферзя не угрожают друг другу
        if (isSafe(mat, r, i))
        {
            // ставим ферзя на текущую клетку
            mat[r][i] = 'Q';

            // повторить для следующей строки
            nQueen(mat, r + 1);

            // возвращаемся назад и удаляем ферзя с текущей клетки
            mat[r][i] = '-';
        }
    }
}

int main()
{
    // mat[][] отслеживает положение ферзей в текущей конфигурации
    char mat[N][N];

    // инициализируем mat[][]с помощью -
    memset(mat, '-', sizeof mat);

    nQueen(mat, 0);

    return 0;

}