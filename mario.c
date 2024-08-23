#include <stdio.h>
#include <cs50.h>

int get_size(void);
void print_grid(int);

int main(void)
{
    //Get size of grid
    int n = get_size();

    // Print grid of bricks
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Enter The size of the Grids: ");
    }
    while (n < 1 || n > 8);
    return n;
}

void print_grid(int size)
{
    // Making variables
    int blankspace = size - 1 ;
    int hashtag = -1;
    // This forloop is created for the rows and columns to be printed.
    for (int i = 0; i < size; i++)
    {
        // This whileloop will print " " till the loop is required
        while (blankspace > 0)
        {
            printf(" ");
            blankspace--;
        }
        // This whileloop will print "#" till the loop is required
        while (hashtag < i)
        {
            printf("#");
            hashtag++;
        }
        printf("\n");
        // Re-assigning the values so that the outer forloop will perform accordingly.
        blankspace = size - i - 2;
        hashtag = -1;
    }
}
