/**
 * {7, 1}  =>  {1, 7}
 * {5, 8, 6, 3, 4}  =>  {3, 8, 6, 5, 4}
 * {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}  =>  {1, 8, 3, 6, 5, 4, 7, 2, 9, 0}
 * {5, 3, 2, 8, 1, 4}  =>  {1, 3, 2, 8, 5, 4}
 * {5, 3, 1, 8, 0}  =>  {1, 3, 5, 8, 0}
 */

#include <stdio.h>

// bubble sort
void sort_array(size_t n, int* arr) 
{
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(arr[i] > arr[j] && arr[i] & 1 && arr[j] & 1)
                {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
        }
    }
}

// to test function
void test_sort(size_t n, int* arr, const int* test)
{   
    int complete = 1;
    sort_array(n, arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != test[i]) complete = 0;
        printf("%d", arr[i]);
    }
    complete == 1 ? printf(" complete") : printf(" incomplete");
    printf("\n");
}

int main() {
    size_t size;

    int arr1[2] = {7, 1};
    size = 2;
    test_sort(size, arr1, (const int[]) {1, 7});

    int arr2[5] = {5, 8, 6, 3, 4};
    size = 5;
    test_sort(size, arr2, (const int[]) {3, 8, 6, 5, 4});

    int arr3[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    size = 10;
    test_sort(size, arr3, (const int[]) {1, 8, 3, 6, 5, 4, 7, 2, 9, 0});

    int arr4[6] = {5,3,2,8,1,4};
    size = 6;
    test_sort(size, arr4, (const int[]) {1, 3, 2, 8, 5, 4});

    int arr5[5] = {5,3,1,8,0};
    size = 5;
    test_sort(size, arr5, (const int[]) {1, 3, 5, 8, 0});

    return 0;
}