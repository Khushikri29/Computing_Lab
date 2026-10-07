#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int bubble(int a[], int n)
{
    int c = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            c++;

            if (a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }

    return c;
}

int merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0, c = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r)
    {
        c++;

        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];

    return c;
}

int mergeSort(int a[], int l, int r)
{
    if (l >= r)
        return 0;

    int m = (l + r) / 2;

    int c = 0;

    c += mergeSort(a, l, m);
    c += mergeSort(a, m + 1, r);
    c += merge(a, l, m, r);

    return c;
}

int quick1(int a[], int l, int r)
{
    if (l >= r)
        return 0;

    int p = l + rand() % (r - l + 1);

    int t = a[p];
    a[p] = a[r];
    a[r] = t;

    int pivot = a[r];
    int i = l - 1;
    int c = 0;

    for (int j = l; j < r; j++)
    {
        c++;

        if (a[j] <= pivot)
        {
            i++;

            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;

    int pos = i + 1;

    c += quick1(a, l, pos - 1);
    c += quick1(a, pos + 1, r);

    return c;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s input_file algorithm\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        printf("File error\n");
        return 1;
    }

    int n = 0, x;

    while (fscanf(fp, "%d", &x) == 1)
        n++;

    rewind(fp);

    int original[n];

    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", &original[i]);

    fclose(fp);

    printf("\nInput size: %d\n", n);

    for (int k = 2; k < argc; k++)
    {
        int a[n];

        for (int i = 0; i < n; i++)
            a[i] = original[i];

        clock_t start = clock();

        int c;

        if (strcmp(argv[k], "bubble") == 0)
        {
            c = bubble(a, n);
            printf("\nBubble Sort:\n");
        }
        else if (strcmp(argv[k], "merge") == 0)
        {
            c = mergeSort(a, 0, n - 1);
            printf("\nMerge Sort:\n");
        }
        else if (strcmp(argv[k], "quick1") == 0)
        {
            c = quick1(a, 0, n - 1);
            printf("\nQuick1 Sort:\n");
        }
        else
        {
            printf("Wrong algorithm\n");
            continue;
        }

        clock_t end = clock();

        printf("Comparisons = %d\n", c);
        printf("Time = %f seconds\n",
               (double)(end - start) / CLOCKS_PER_SEC);
    }

    return 0;
}