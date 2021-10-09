#include <stdio.h>
int main()
{
    char c;
    char str[1000];
    char str1[1000];

    scanf("%c", &c);
    scanf("%s", str);
    scanf("%[\n]%*c");
    scanf("%[^\n]%*c", str1);

    printf("%c", c);
    printf("%s", str);

    // fgets(str1, 1000, stdin);

    // printf("%s\n", str1);
}