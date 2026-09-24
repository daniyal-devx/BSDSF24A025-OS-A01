// File: src/myfilefunctions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// INPUT: A file pointer, and addresses to store the final counts.
// PROCESS: Read character by character. Count spaces/newlines to find words.
// OUTPUT: Updates lines, words, chars. Returns 0 on success.
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (file == NULL) {
        return 1; // Return failure if file doesn't exist
    }

    *lines = 0;
    *words = 0;
    *chars = 0;
    
    int ch;
    int in_word = 0; // Acts as a boolean: 0 means false, 1 means true

    // fgetc grabs one character. EOF means "End Of File"
    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;

        if (ch == '\n') {
            (*lines)++;
        }

        // Check if the character is whitespace
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            in_word = 0; // We are outside a word
        } else if (in_word == 0) {
            in_word = 1; // We just started a new word!
            (*words)++;
        }
    }
    return 0; 
}

// INPUT: File pointer, a search string, and a 3D pointer to hold our array of matching lines.
// PROCESS: Read line by line. If search_str is in the line, save it.
// OUTPUT: Returns the number of matches found, or -1 on error.
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (fp == NULL || search_str == NULL || matches == NULL) {
        return -1;
    }

    int capacity = 10; // Start by making room for 10 matches
    int count = 0;
    
    // Ask the OS for memory to hold our string pointers
    *matches = malloc(capacity * sizeof(char*));
    if (*matches == NULL) return -1; 

    char buffer[1024]; // Temporary bucket to hold a line (up to 1024 chars)

    // fgets reads one line at a time into 'buffer'
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        
        // strstr checks if search_str is inside the buffer
        if (strstr(buffer, search_str) != NULL) {
            
            // If we run out of space, double the capacity!
            if (count >= capacity) {
                capacity *= 2;
                *matches = realloc(*matches, capacity * sizeof(char*));
            }

            // Allocate memory for this specific line and copy it over
            (*matches)[count] = malloc(strlen(buffer) + 1);
            strcpy((*matches)[count], buffer);
            
            count++;
        }
    }
    return count;
}