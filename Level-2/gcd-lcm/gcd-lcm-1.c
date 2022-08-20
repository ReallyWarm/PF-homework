/**
 * จงเขียนโปรแกรมรับตัวเลข 2 ตัวแล้วหาค่า หรม. และ ครน. ของตัวเลขทั้งสอง 
 * 
 * input: 9 12
 * GCD = 3
 * LCM = 36
 */

#include <stdio.h>

int main() {
    int x, y, cx, cy;
    int gcd = 0, lcm = 0;
    printf("input: ");
    scanf("%d %d", &x, &y);

    if (x != 0 && y != 0) 
    {
        // gcd
        cx = x, cy = y;
        while (cx != cy) 
        {
            if (cx > cy)
                cx -= cy;
            if (cy > cx)
                cy -= cx;
        }
        gcd = cx;

        // lcm
        cx = x, cy = y;
        while (cx != cy) 
        {
            if (cx < cy)
                cx += x;
            if (cy < cx)
                cy += y;
        }
        lcm = cx;
    }

    printf("GCD = %d\n", gcd);
    printf("LCM = %d", lcm);
    
    return 0;
}