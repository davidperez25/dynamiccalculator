#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 100

const char* operations = "+-*/";

void processInput() {
    char str[CAPACITY];
    char strcopy[CAPACITY];
    char *token;
    int numbers[CAPACITY] = {0};
    char symbols[CAPACITY] = {'\0'};
    int numberCount = 0;
    int symbolCount = 0;

    printf("?: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input\n");
        return;
    }

    str[strcspn(str, "\n")] = '\0';

    if (strcmp(str, "exit") == 0) {
        printf("Exiting...\n");
        exit(0);
    }

    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    strcpy(strcopy, str);

    token = strtok(strcopy, operations);
    while (token != NULL) {
        if (numberCount < CAPACITY) {
            numbers[numberCount++] = atoi(token);
        }
        token = strtok(NULL, operations);
    }

    token = strtok(str, "0123456789");
    while (token != NULL) {
        for (int i = 0; token[i] != '\0'; i++) {
            if (symbolCount < CAPACITY) {
                symbols[symbolCount++] = token[i];
            }
        }
        token = strtok(NULL, "0123456789");
    }

    if (numberCount == 0) {
        printf("No numbers provided.\n");
        return;
    }

    int result = numbers[0];

    for (int i = 0; i < symbolCount; i++) {
        if (symbols[i] == '+') {
            result += numbers[i + 1];
        }
        else if (symbols[i] == '-') {
            result -= numbers[i + 1];
        }
        else if (symbols[i] == '*') {
            result *= numbers[i + 1];
        }
        else if (symbols[i] == '/') {
            if (numbers[i + 1] == 0) {
                printf("Error: Division by zero.\n");
                return;
            }
            result /= numbers[i + 1];
        }
    }

    printf("%d\n", result);
}

int main() {
    while (1) {
        processInput();
    }

    return 0;
}
