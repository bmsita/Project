#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *input, char *result) {
    int len = strlen(input);
    for (int i = len - 1; i >= 0; i--) {
        *result = input[i];
        result++;
    }
    *result = '\0';
}

void toUpperCase(char *input, char *result) {
    while (*input) {
        *result = toupper(*input);
        input++;
        result++;
    }
    *result = '\0';
}

void toLowerCase(char *input, char *result) {
    while (*input) {
        *result = tolower(*input);
        input++;
        result++;
    }
    *result = '\0';
}

void toggleCase(char *input, char *result) {
    while (*input) {
        if (isupper(*input)) {
            *result = tolower(*input);
        } else if (islower(*input)) {
            *result = toupper(*input);
        } else {
            *result = *input;
        }
        input++;
        result++;
    }
    *result = '\0';
}

void concatenate(char *first, char *second, char *result) {
    while (*first) {
        *result = *first;
        result++;
        first++;
    }
    while (*second) {
        *result = *second;
        result++;
        second++;
    }
    *result = '\0';
}

int main() {
    char str1[101], str2[101];
    char reversed[101], upper[101], lower[101], toggled[101], combined[202];
    char choice;

    printf("Enter the first string (max 100 characters): ");
    fgets(str1, 101, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Do you want to enter a second string? (y/n): ");
    scanf(" %c", &choice);
    getchar();

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the second string (max 100 characters): ");
        fgets(str2, 101, stdin);
        str2[strcspn(str2, "\n")] = '\0';
    } else {
        str2[0] = '\0';
    }

    reverseString(str1, reversed);
    toUpperCase(str1, upper);
    toLowerCase(str1, lower);
    toggleCase(str1, toggled);
    if (strlen(str2) > 0) {
        concatenate(str1, str2, combined);
    }

    FILE *file = fopen("string_operations_output.txt", "w");
    if (file == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    fprintf(file, "----- String Operations Result -----\n\n");
    fprintf(file, "Original String       : %s\n", str1);
    fprintf(file, "Reversed String       : %s\n", reversed);
    fprintf(file, "Upper Case            : %s\n", upper);
    fprintf(file, "Lower Case            : %s\n", lower);
    fprintf(file, "Toggle Case           : %s\n", toggled);
    if (strlen(str2) > 0) {
        fprintf(file, "Second String         : %s\n", str2);
        fprintf(file, "Concatenated String   : %s\n", combined);
    }

    fclose(file);
    printf("\nAll operations completed! Check 'string_operations_output.txt'\n");

    return 0;
}