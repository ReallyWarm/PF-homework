/**
 * "din"      =>  "((("
 * "recede"   =>  "()()()"
 * "Success"  =>  ")())())"
 * "(( @"     =>  "))((" 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char *DuplicateEncoder(char *str)
{
    int found = 0;
    char* c_str;
    c_str = (char*) malloc(strlen(str)+1);
    strcpy(c_str, str);

    for (int i = 0; c_str[i+1] != '\0'; i++)
    {
        if (c_str[i] != -1)
        {
            for (int j = i+1; c_str[j] != '\0'; j++)
            {
                if (c_str[j] == upCase(c_str[i]) || c_str[j] == lowCase(c_str[i]))
                {   
                    c_str[j] = -1;
                    found = 1;
                }
            }
        }
        if (found) 
            c_str[i] = -1;
        found = 0;
    }

    for (int k = 0; c_str[k] != '\0'; k++)
    {
        if (c_str[k] == -1)
            c_str[k] = ')';
        else
            c_str[k] = '(';     
    }

    return c_str;
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

    testRun(100, "P?{SdgTa%P17M=W9%6)+&%5<?4XaQ54hZc1e)Ve1Mh9bgfl/)/>=)XUh3`0<{MaW c12=hbl lM}QXTa/^36l}OP&+0M*l04N(e", 
                 ")))(())))))())))))))))))))))))))())))()))))))())))()))())()))))))))()))))))))))))())))()))))()))(()");

    return 0;
}