#include <stdio.h>
#include <ctype.h>
#include <string.h>

void identifyToken(char token[]) {
    char *keywords[] = {"int", "float", "if", "else", "return", "for", "while"};
    int i, isKeyword = 0;

    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(token, keywords[i]) == 0) {
            printf("Keyword: %s\n", token);
            isKeyword = 1;
            break;
        }
    }

    if (!isKeyword) {
        if (isdigit(token[0])) {
            printf("Number: %s\n", token);
        } else {
            printf("Identifier: %s\n", token);
        }
    }
}

int main() {
    char expression[100], token[20];
    int i, j;

    printf("Enter multiple lines of expression (type 'END' to finish):\n");

    while (1) {
        fgets(expression, sizeof(expression), stdin);
        if (strncmp(expression, "END", 3) == 0) {
            break;
        }

        i = 0; j = 0;
        while (expression[i] != '\0') {
            if (isalnum(expression[i])) {
                token[j++] = expression[i];
            } else {
                if (j > 0) {
                    token[j] = '\0';
                    identifyToken(token);
                    j = 0;
                }
                if (strchr("=+-*/;()", expression[i])) {
                    printf("Operator/Symbol: %c\n", expression[i]);
                }
            }
            i++;
        }
    }

    return 0;
}
