#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    FILE *fp = fopen("input.txt", "w");

    if (fp == NULL)
    {
        printf("File error\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++)
        fprintf(fp, "%d\n", rand());

    fclose(fp);

    printf("%d random numbers generated\n", n);

    return 0;
}
/* gcc generator.c -o generator
./generator.exe 10
cat input.txt */
//./testSort.sh -i 10 -x 50 -s 10 bubble merge quick1 /* gcc assgH02.c -o assgH02

./assgH02.exe input.txt bubble

./assgH02.exe input.txt merge

./assgH02.exe input.txt bubble merge

./assgH02.exe input.txt quick1

./assgH02.exe input.txt bubble merge quick1

./generator.exe 30*/