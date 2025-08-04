#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int main() {
    char paragraph[MAX];
    char words[50][20];
    int count[50] = {0}, n = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, MAX, stdin);

    char *token = strtok(paragraph, " ,.-\n");

    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[n], token);
            count[n] = 1;
            n++;
        }
        token = strtok(NULL, " ,.-\n");
    }

    printf("Word Frequencies:\n");
    for (int i = 0; i < n; i++)
        printf("%s: %d\n", words[i], count[i]);

    return 0;
}
