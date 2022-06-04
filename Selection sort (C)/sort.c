#include <stdio.h>

void sort (int size, int arr[]);

int main(void)
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        printf("Num %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sort(size, arr);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void sort (int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] <= arr[j])
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
