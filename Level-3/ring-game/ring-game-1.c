/**
 * จงเขียนโปรแกรมแทนเกม RingRingRing! โดยมีกติกาการเล่นคือ ผู้ถามจะถามประโยคมา 1 ประโยค ผู้ตอบต้องตอบเป็นตัวเลขแทนจำนวนคำหลังจากคำว่า Ring! เช่น 
 * 
 *                  Input                        Output
 * ------------------------------------------------------
 * | RingringrInG! How many bells do you have? | 6      |
 * | ringRingRiNGring! How many bells?         | 3      |
 * | RING! Me kra ding kee aun?                | 5      |
 * ------------------------------------------------------
 * 
 * ปล.1 คำว่า ring! เป็น case-insensitive 
 * ปล.2 หลังคำว่า ring! แต่ละคำจะคั่นด้วยช่องว่างเสมอ 
 */

#include <stdio.h>
#include <string.h>

int main() {
    char inp[1000];
    int ring = 0;
    int i, count = 0;
    int start_count = 0, foundLetter = 1;
    scanf("%[^\n]s", inp);

    for (i = 0; inp[i] != '\0'; i++)
    {
        if (inp[i] == 'r' || inp[i] == 'R')
            ring = 1;
        else if (ring == 1 && (inp[i] == 'i' || inp[i] == 'I'))
            ring = 2;
        else if (ring == 2 && (inp[i] == 'n' || inp[i] == 'N'))
            ring = 3;
        else if (ring == 3 && (inp[i] == 'g' || inp[i] == 'G'))
            ring = 4;
        else if (ring == 4 && inp[i] == '!')
            start_count = 1;
        else 
            ring = 0;

        if (start_count)
        {   
            if (inp[i] == '?')
                break;
            else if (foundLetter == 0 && inp[i] != ' ')
                count++;

            if (inp[i] == ' ')
                foundLetter = 0;
            else
                foundLetter = 1;    
        }
    }
    printf("%d", count);
    
    return 0;
}