#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // To get name from the user
    string name = get_string("What is your name? ");
    // Printing the given name.
    printf("hello, %s\n", name);
    
}