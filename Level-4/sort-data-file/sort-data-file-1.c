/**
 * EXAMPLE DATA FILE
 * 1 Hale Pen
 * 10 Ben Watch
 * 4 Peter Spider
 * 8 Jim Banana
 * 
 * EXAMPLE OUTPUT FILE
 * 1 Hale Pen
 * 4 Peter Spider
 * 8 Jim Banana
 * 10 Ben Watch
 */

#include <stdio.h>
#include <stdlib.h>

struct person
{
    int id;
    char name[20];
    char item[20];
};

int compare(const void* s1, const void* s2)
{
    struct person *c1 = (struct person *)s1;
    struct person *c2 = (struct person *)s2;
    return c1->id - c2->id;
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Couldn't open data file!\n");
        return 1;
    }

    struct person data[10];
    char buffer[1024];
    int i = 0;

    while (fgets(buffer, 1024, file)) 
    {
        if (sscanf(buffer, "%d %19s %19s", &data[i].id, data[i].name, data[i].item) != 3) {
            printf("Error can't read line %d!\n", i+1);
            fclose(file);
            return 1;
        }
        // printf("%d %s %s\n", data[i].id, data[i].name, data[i].item); // print out read data
        i++;
    }
    fclose(file);

    qsort(data, i, sizeof(struct person), compare);
    // for (int j = 0; j < i; j++) printf("%d %s %s\n", data[j].id, data[j].name,  data[j].item); // print out sort data

    FILE *newfile = fopen("output.txt", "w");
    if (!newfile) {
        printf("Couldn't open output file!\n");
        return 1;
    }

    for (int j = 0; j < i; j++) 
    {
        fprintf(newfile,"%d %s %s\n", data[j].id, data[j].name, data[j].item);
    }
    fclose(newfile);

    return 0;
}