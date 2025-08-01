#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *input, char *result) {
    char *end = input + strlen(input) - 1;
    while (end >= input) {
        *result++ = *end--;
    }
    *result = '\0';
}

void toUpperCase(char *input, char *result) {
    while (*input) {
        *result++ = toupper(*input++);
    }
    *result = '\0';
}

void toLowerCase(char *input, char *result) {
    while (*input) {
        *result++ = tolower(*input++);
    }
    *result = '\0';
}

void toggleCase(char *input, char *result) {
    while (*input) {
        if (isupper(*input))
            *result = tolower(*input);
        else if (islower(*input))
            *result = toupper(*input);
        else
            *result = *input;
        input++;
        result++;
    }
    *result = '\0';
}

void concatenate(char *first, char *second, char *result) {
    while (*first) {
        *result++ = *first++;
    }
    while (*second) {
        *result++ = *second++;
    }
    *result = '\0';
}

void getValidStringInput(const char *prompt, char *buffer, int maxLength) {
    while (1) {
        printf("%s", prompt);
        fgets(buffer, maxLength, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strlen(buffer) == 0) {
            printf("Input was empty. Please enter a valid string.\n");
        } else {
            break;
        }
    }
}

void printStringOperations(char *label, char *str) {
    char reversed[101], upper[101], lower[101], toggled[101];
    reverseString(str, reversed);
    toUpperCase(str, upper);
    toLowerCase(str, lower);
    toggleCase(str, toggled);

    printf("\n----- String Operations on %s -----\n", label);
    printf("%s String      : %s\n", label, str);
    printf("Reversed       : %s\n", reversed);
    printf("Upper Case     : %s\n", upper);
    printf("Lower Case     : %s\n", lower);
    printf("Toggle Case    : %s\n", toggled);
}

void saveOperationsToFile(char *str1, char *str2, int hasSecond, char *combined) {
    FILE *file = fopen("string_operations_output.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file to save results!\n");
        return;
    }

    char reversed[101], upper[101], lower[101], toggled[101];

    fprintf(file, "----String Operations Reports----\n\n");

    reverseString(str1, reversed);
    toUpperCase(str1, upper);
    toLowerCase(str1, lower);
    toggleCase(str1, toggled);

    fprintf(file, "First String          : %s\n", str1);
    fprintf(file, "Reversed              : %s\n", reversed);
    fprintf(file, "Upper Case            : %s\n", upper);
    fprintf(file, "Lower Case            : %s\n", lower);
    fprintf(file, "Toggle Case           : %s\n\n", toggled);

    if (hasSecond) {
        reverseString(str2, reversed);
        toUpperCase(str2, upper);
        toLowerCase(str2, lower);
        toggleCase(str2, toggled);

        fprintf(file, "Second String         : %s\n", str2);
        fprintf(file, "Reversed              : %s\n", reversed);
        fprintf(file, "Upper Case            : %s\n", upper);
        fprintf(file, "Lower Case            : %s\n", lower);
        fprintf(file, "Toggle Case           : %s\n\n", toggled);

        fprintf(file, "Concatenated String   : %s\n", combined);
    }

    fclose(file);
    printf("\nAll operations saved successfully in 'string_operations_output.txt'\n");
}

int main() {
    char str1[101], str2[101];
    char combined[202];
    char choice, saveChoice;
    int hasSecond = 0;

    getValidStringInput("Enter the first string (max 100 characters): ", str1, sizeof(str1));
    printStringOperations("First", str1);

    printf("\nDo you want to enter a second string for concatenation? (y/n): ");
    scanf(" %c", &choice);
    getchar();

    if (choice == 'y' || choice == 'Y') {
        getValidStringInput("Enter the second string (max 100 characters): ", str2, sizeof(str2));
        printStringOperations("Second", str2);
        hasSecond = 1;

        concatenate(str1, str2, combined);
        printf("\n----- Combined Operation -----\n");
        printf("Concatenated String   : %s\n", combined);
    }

    printf("\nDo you want to save the operations to a file? (y/n): ");
    scanf(" %c", &saveChoice);
    getchar();

    if (saveChoice == 'y' || saveChoice == 'Y') {
        saveOperationsToFile(str1, str2, hasSecond, combined);
    } else {
        printf("\nFile save skipped by user.\n");
    }

    return 0;
}