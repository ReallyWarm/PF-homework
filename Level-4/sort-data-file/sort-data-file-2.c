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
#include <string.h>

#define NUM_DATA 10

struct person
{
    int id;
    char name[20];
    char item[20];
};

void sort_data(size_t n, struct person* data)
{
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1 ; j < n ; j++)
            {
                if(data[i].id > data[j].id)
                {
                    struct person tmp = data[i];
                    data[i] = data[j];
                    data[j] = tmp;
                }
        }
    }
}

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) {
        printf("Couldn't open data file!\n");
        return 1;
    }

    struct person data[NUM_DATA];
    char buffer[1024];
    int i = 0;
    
    while (i < NUM_DATA)
    {
        if (fscanf(file ,"%d %19s %19s\n",&data[i].id, data[i].name, data[i].item) != 3) {
            printf("Error can't read line %d!\n", i);
            fclose(file);
            return 1;
        }
        // printf("%d %s %s\n", data[i].id, data[i].name, data[i].item); // print out read data
        i++;
    }
    fclose(file);

    sort_data(NUM_DATA, data);
    // for (int j = 0; j < i; j++) printf("%d %s %s\n", data[j].id, data[j].name,  data[j].item); // print out sort data

    FILE *newfile = fopen("output.txt", "w");
    if (!newfile) {
        printf("Couldn't open output file!\n");
        return 1;
    }

    char str_id[20];
    for (int j = 0; j < NUM_DATA; j++)
    {   
        sprintf(str_id, "%d", data[j].id);
        fwrite(str_id, strlen(str_id), 1, file);
        fwrite(" ", 1, 1, file);
        fwrite(data[j].name, strlen(data[j].name), 1, file);
        fwrite(" ", 1, 1, file);
        fwrite(data[j].item, strlen(data[j].item), 1, file);
        fwrite("\n", 1, 1, file);
    }
    fclose(newfile);

    return 0;
}