/**
 * "din"      =>  "((("
 * "recede"   =>  "()()()"
 * "Success"  =>  ")())())"
 * "(( @"     =>  "))((" 
 * 
 * NOTE: Binary method for string with length <= 64
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

char upCase(char c) 
{
    if (c >= 'a' && c <= 'z') 
        c -= ' ';
    return c;
}

char lowCase(char c) 
{
    if (c >= 'A' && c <= 'Z')
        c += ' ';
    return c;
}

char* DuplicateEncoder(char *str) 
{
    ull diff = 0b0;
    for (int i = 0; str[i+1] != '\0'; i++)
    {
        if (!((diff >> (strlen(str)-1 - i)) & 1))
        {
            for (int j = i+1; str[j] != '\0'; j++)
            {   
                if (str[j] == upCase(str[i]) || str[j] == lowCase(str[i]))
                {
                    diff |= (((ull) 1) << (strlen(str)-1 - i));
                    diff |= (((ull) 1) << (strlen(str)-1 - j));
                }
            }
        }
    }

    char* out;
    out = (char*) malloc(strlen(str));
    for (int k = 0; k < strlen(str); k++)
    {
        if ((diff >> (strlen(str)-1 - k)) & 1)
            out[k] = ')';
        else
            out[k] = '(';
    }

    return out;
}

// to test function
void testRun(size_t n, char* str, const char* test)
{   
    int complete = 1;
    char* t_str = DuplicateEncoder(str);
    printf("%s", t_str);
    for (int i = 0; i < n; i++)
    {
        if (t_str[i] != test[i]) complete = 0;
    }
    complete == 1 ? printf(" complete") : printf(" incomplete => %s", test);
    printf("\n");
    free(t_str); // free the allocated return memory
}

int main() {

    testRun(3, "din", "(((");

    testRun(6, "recede", "()()()");

    testRun(8, "Success", ")())())");

    testRun(3, "(( @", "))((");

    testRun(14, "Prespecialized", ")()())()(()()(");

    testRun(9, "   ()(   ", "))))())))");

    // MAX String lenth
    testRun(64, "P?{SdgTa%P17M=W9%6)+&%5<?4XaQ54hZc1e)Ve1M9gfl/)/>=)XUh3`0<{MaW c", 
                ")))(()())))()))))()(()))))))()))())))()))))(()))()))()((()))))()");

    return 0;
}