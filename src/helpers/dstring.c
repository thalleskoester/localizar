//
// Created by Thalles on 19/11/2019.
//

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dstring.h"

dString initString(dString content) {
    if (content == NULL) {
        dString buf = malloc(sizeof(char));
        return buf;
    }

    size_t len = strlen(content) + 1;
    dString buf = malloc(sizeof(char) * len);
    memcpy(buf, content, len);
    return buf;
}

void alterString(dString string, dString content) {
    size_t len = strlen(content) + 1;

    //Realloc if new size is lower?
    string = realloc(string, sizeof(char) * len);
    memcpy(string, content, len);
}

void concatStr(dString string, dString append) {
    size_t strLen = strlen(string), appendLen = strlen(append);
    string = realloc(string, sizeof(char) * (strLen + appendLen + 1));
    strcat(string, append);
}

void freeString(dString string) {
    free(string);
}

dStringVector initStringVector(unsigned int size) {
    dStringVector buf = malloc(sizeof(dString) * size);

    for (unsigned int i = 0; i < size; ++i) {
        buf[i] = initString(NULL);
    }

    return buf;
}

void copyStringVector(dStringVector vector, unsigned int size, dStringVector content) {
    for (unsigned int i = 0; i < size; ++i) {
        alterString(vector[i], content[i]);
    }
}

void freeStringVector(dStringVector vector, unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        free(vector[i]);
    }
    free(vector);
}

dString strToLower(dString string) {
    for (size_t i = 0; i < strlen(string); ++i) {
        string[i] = (char) tolower((int) string[i]);
    }
    return string;
}

dString strToUpper(dString string) {
    for (size_t i = 0; i < strlen(string); ++i) {
        string[i] = (char) toupper((int) string[i]);
    }
    return string;
}

void applyFuncToStrings(dStringVector vector, unsigned int size, dString (*func)(dString)) {
    for (unsigned int i = 0; i < size; ++i) {
        vector[i] = func(vector[i]);
    }
}

void removeSubstr(dString string, dString remove) {
    size_t length = strlen(remove);
    while ((string = strstr(string, remove))) {
        memmove(string, string + length, 1 + strlen(string + length));
    }
}

int countAppearances(dString string, dString token) {
    unsigned int sizeOfToken = strlen(token);
    dString positionOfToken = string;
    int i = 0;

    for (i; (positionOfToken = strstr(positionOfToken, token)) != NULL; ++i) {
        positionOfToken = positionOfToken + sizeOfToken;
    }

    return i;
}

void explode(dString string, dString delimiter, dStringVector result) {
    dString tok;
    int i = 0;

    tok = strtok(string, delimiter);
    while (tok != NULL) {
        result[i] = initString(tok);
        tok = strtok(NULL, delimiter);
        i = i + 1;
    }
}

void implode(dStringVector vector, unsigned int size, dString glue, dString result) {
    for (unsigned int i = 0; i < size; ++i) {
        strcat(result, vector[i]);
        if ((i + 1) < size) {
            strcat(result, glue);
        }
    }
}
