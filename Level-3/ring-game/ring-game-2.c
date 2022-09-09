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

char uppercase(char c) {
    if (c >= 'a' && c <= 'z') 
        c &= ~' '; // cut bit with value of ' ' (32) 
                   // an alternative to c -= 32
    return c; 
}

int main() {
    char inp[1000];
    char ring[] = "ring!";
    int i, j, count = 0;
    int start_count = 0, foundLetter = 0;
    scanf("%[^\n]s", inp);

    for (i = 0; inp[i] != '\0'; i++)
    {   
        if (!start_count)
        {
            for (j = 0; ring[j] != '\0'; j++)
            {
                if (inp[i + j] != ring[j] && inp[i + j] != uppercase(ring[j]))
                {
                    start_count = 0;
                    break;
                }
                start_count = 1;
            }

            if (start_count)
                i += j;
        }
        else
        {
            if (inp[i] == '?')
            {
                if (foundLetter == 1)
                    count++;
                break;
            }
            
            if (inp[i] == ' ')
            {
                if (foundLetter != 0)
                    count++;
                foundLetter = 0;
            }
            else
                foundLetter = 1;
        }
    }
    printf("%d", count);
    
    return 0;
}