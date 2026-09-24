// File: src/main.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    
    char buffer1[50];
    char buffer2[50] = "Hello ";
    const char* testStr = "Operating Systems";

    // Test mystrlen
    printf("Length of '%s' is: %d\n", testStr, mystrlen(testStr));

    // Test mystrcpy
    mystrcpy(buffer1, testStr);
    printf("mystrcpy result: %s\n", buffer1);

    // Test mystrncpy (copy only first 9 characters "Operating")
    char buffer3[50];
    mystrncpy(buffer3, testStr, 9);
    buffer3[9] = '\0'; // Manually null-terminate just to be safe for printing
    printf("mystrncpy (9 chars) result: %s\n", buffer3);

    // Test mystrcat
    mystrcat(buffer2, "World!");
    printf("mystrcat result: %s\n", buffer2);


    printf("\n--- Testing File Functions ---\n");
    
    // Open the test file we created
    FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open test.txt. Did you create it?\n");
        return 1;
    }

    // Test wordCount
    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("File stats -> Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
    }

    // Reset file pointer back to the beginning of the file for mygrep
    rewind(fp);

    // Test mygrep
    char** matches = NULL;
    int match_count = mygrep(fp, "Hello", &matches);
    
    if (match_count > 0) {
        printf("Found %d lines containing 'Hello':\n", match_count);
        for (int i = 0; i < match_count; i++) {
            printf(" -> %s", matches[i]);
            free(matches[i]); // We MUST free the memory we malloc'd in mygrep!
        }
        free(matches); // Free the array itself
    } else {
        printf("No matches found or an error occurred.\n");
    }

    // Close the file when we are done
    fclose(fp);

    return 0;
}