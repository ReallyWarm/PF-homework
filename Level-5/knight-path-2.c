/**
 * knight("a3", "b5") --> 1
 * knight("a1", "c1") --> 2
 * knight("a1", "f1") --> 3
 * knight("a1", "f3") --> 3
 * knight("a1", "f4") --> 4
 * knight("a1", "f7") --> 5
 */

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool findPath(int scol, int srow, int ecol, int erow, short move)
{
    if (move < 0) 
        return false;

    // Found path
    if (scol == ecol && srow == erow)
        return true;

    const int difcol[8] = {-1, 1,-1, 1,-2,-2, 2, 2 };
    const int difrow[8] = {-2,-2, 2, 2,-1, 1,-1, 1 };

    for (int i = 0; i < 8; i++)
    {
        int ncol = scol + difcol[i];
        int nrow = srow + difrow[i];

        // If not outside of board
        if (scol >= 0 && scol < 8 && srow >= 0 && srow < 8) {
            bool found = findPath(ncol, nrow, ecol, erow, move-1);
            if (found)
                return true;
        }
    }
    return false;
}

short knight(char s[2], char e[2])
{
    int srow, scol, erow, ecol;

    scol = s[0] - 'a';
    srow = s[1] - '1';
    ecol = e[0] - 'a';
    erow = e[1] - '1';

    short move = 0;
    while (true)
    {
        bool done = findPath(scol, srow, ecol, erow, move);
        if (done)
            return move;
        move++;
    }
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