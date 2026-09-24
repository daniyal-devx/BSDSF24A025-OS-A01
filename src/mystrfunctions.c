// File: src/mystrfunctions.c
#include "../include/mystrfunctions.h"

// INPUT: A string 's'
// PROCESS: Count characters one by one until we see '\0'
// OUTPUT: The total count (length)
int mystrlen(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

// INPUT: A destination buffer 'dest' and a source string 'src'
// PROCESS: Copy every character from 'src' to 'dest' including the '\0'
// OUTPUT: Returns 0 for success (standard practice)
int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Always add the stop sign at the end!
    return 0; 
}

// INPUT: 'dest', 'src', and a maximum number of characters 'n'
// PROCESS: Copy up to 'n' characters. If 'src' is shorter than 'n', fill the rest with '\0'
// OUTPUT: Returns 0 for success
int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    // Copy from src as long as we haven't hit n, and haven't hit the end of src
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    // If we copied less than n characters, fill the remaining space with '\0'
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return 0;
}

// INPUT: A destination string 'dest' and a source string 'src'
// PROCESS: Find the end of 'dest', then stick 'src' onto that end point.
// OUTPUT: Returns 0 for success
int mystrcat(char* dest, const char* src) {
    int i = 0;
    int j = 0;
    
    // Step 1: Fast-forward 'i' to the end of the dest string
    while (dest[i] != '\0') {
        i++;
    }
    
    // Step 2: Copy src into dest starting from that exact spot
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    
    dest[i] = '\0'; // Cap it off with a stop sign
    return 0;
}