#include <stdio.h>
#include <string.h>

int main() {

    char string[100];
    printf("Enter the string: ");
    fgets(string, 100, stdin);

    // Subtract 2 because of '\0' and '\n' 
    for (int i = strlen(string) - 2; i >= 0; i--)
    {
        printf("%c", string[i]);
    }

    printf("\n");
    return 0;
}
