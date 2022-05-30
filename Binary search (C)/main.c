#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int search(int *nums, int size, int target);

int main(void)
{
    //Getting size of array from user
    int size = get_int("How many numbers would you like to enter? ");

    //array of input numbers
    int *numbers = malloc(sizeof(int) * size);

    //Assigning user input values into an array
    for (int i = 0; i < size; i++)
    {
        printf("Num %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    //Target to be searched, I used this approach because get_int would prompt twice
    int target;
    printf("What number would you like to look for? ");
    scanf("%d", &target);

    //The function returns the index of the target
    int index = search(numbers, size, target);

    //If not found, print an error message and terminate the program
    if (index == -1)
    {
        printf("Number is not present\n");
        return 1;
    }
    //Output the position if found
    printf("The number %d is at position %d\n", target, index + 1);
    free(numbers);
    return 0;
}


int search(int *nums, int size, int target)
{
    int left = 0,
        right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        if (target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}
