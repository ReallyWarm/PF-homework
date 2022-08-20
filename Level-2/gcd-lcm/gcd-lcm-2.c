/**
 * จงเขียนโปรแกรมรับตัวเลข 2 ตัวแล้วหาค่า หรม. และ ครน. ของตัวเลขทั้งสอง 
 * 
 * input: 9 12
 * GCD = 3
 * LCM = 36
 */

#include <stdio.h>

int main() {
    int x, y, cx, cy, tmp_x;
    int gcd = 0, lcm = 0;
    printf("input: ");
    scanf("%d %d", &x, &y);

    if (x != 0 && y != 0) 
    {
        // gcd
        cx = x, cy = y;
        while (cy != 0) 
        {
            tmp_x = cx;
            cx = cy;
            cy = tmp_x % cy;
        }
        gcd = cx;

        // lcm
        lcm = (x * y) / gcd;
    }

    printf("GCD = %d\n", gcd);
    printf("LCM = %d", lcm);
    
    return 0;
}