#include <stdio.h>
#include <string.h>

int main(void) {
	char text[32];
	if (fgets(text, sizeof text, stdin) == NULL)
{
        puts("input error"); return 1;
    }
    size_t pos = strspn(text, "\n");
    if (text[pos] == '\n') text[pos] = '\0';
    if (strlen(text) > 30) {
        puts("Too long"); return 1;
    }
    int spaces = 0;
    int numbers = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            ++numbers;
        } else if (text[i] == ' ') {
            ++spaces;
        }
    }
    printf("Цифр: %d, Пробелов: %d\n", numbers, spaces);

    return 0;
}