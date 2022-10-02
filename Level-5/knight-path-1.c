/**
 * knight("a3", "b5") --> 1
 * knight("a1", "c1") --> 2
 * knight("a1", "f1") --> 3
 * knight("a1", "f3") --> 3
 * knight("a1", "f4") --> 4
 * knight("a1", "f7") --> 5
 */

#include <stdio.h>

void nextMove(int b[8][8], int i, int j, int move)
{
    if (i - 2 >= 0) {
        if (b[i-2][j-1] == 9  && j-1 >= 0)
            b[i-2][j-1] = move + 1;

        if (b[i-2][j+1] == 9  && j+1 < 8)
            b[i-2][j+1] = move + 1;
    }
    if (i + 2 < 8) {
        if (b[i+2][j-1] == 9 && j-1 >= 0)
            b[i+2][j-1] = move + 1;

        if (b[i+2][j+1] == 9 && j+1 < 8)
            b[i+2][j+1] = move + 1;
    }
    if (j - 2 >= 0) {
        if (b[i-1][j-2] == 9 && i-1 >= 0)
            b[i-1][j-2] = move + 1;

        if (b[i+1][j-2] == 9 && i+1 < 8)
            b[i+1][j-2] = move + 1;
    }
    if (j + 2 < 8) {
        if (b[i-1][j+2] == 9 && i-1 >= 0)
            b[i-1][j+2] = move + 1;

        if (b[i+1][j+2] == 9 && i+1 < 8)
            b[i+1][j+2] = move + 1;
    }
}

short knight(const char *s, const char *e)
{
    int b[8][8];
    int srow, scol, erow, ecol;

    scol = s[0] - 'a';
    srow = s[1] - '1';
    ecol = e[0] - 'a';
    erow = e[1] - '1';

    if (scol < 0 || scol >= 8 || srow < 0 || srow >= 8 ||
        ecol < 0 || ecol >= 8 || erow < 0 || erow >= 8)
        return -1;

    for (int i = 0; i < 8; i++)   
    { 
        for (int j = 0; j < 8; j++)
        {
            if (i == srow && j == scol)
                b[i][j] = 0;
            else
                b[i][j] = 9;
        }
    }

    int move = 0;
    while (b[erow][ecol] == 9)
    {
        for (int i = 0; i < 8 && b[erow][ecol] == 9; i++) 
        {
            for (int j = 0; j < 8 && b[erow][ecol] == 9; j++) 
            {
                if (b[i][j] == move) {
                    nextMove(b, i, j, move);
                }
            } 
        }
        move++;
    }

    return move;
}

void testRun(short test, short ans)
{
    printf("%d", test);
    if (test != ans)
        printf(" should be %d\n", ans);
    else
        printf(" correct\n");
}

int main()
{   
    testRun(knight("a2", "a2"), 0);
    testRun(knight("a3", "b5"), 1);
    testRun(knight("a1", "c1"), 2);
    testRun(knight("a1", "f1"), 3);
    testRun(knight("a1", "f3"), 3);
    testRun(knight("a1", "f4"), 4);
    testRun(knight("a1", "f7"), 5);
    testRun(knight("a1", "h8"), 6);

    return 0;
}