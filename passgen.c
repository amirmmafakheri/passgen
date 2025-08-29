#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// character sets
const char *LOWER   = "abcdefghijklmnopqrstuvwxyz";
const char *UPPER   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *DIGITS  = "0123456789";
const char *SYMBOLS = "!@#$%^&*";

// combine all into one pool
char *build_pool() {
    size_t len = strlen(LOWER) + strlen(UPPER) + strlen(DIGITS) + strlen(SYMBOLS);
    char *pool = malloc(len + 1);
    if (!pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(pool, LOWER);
    strcat(pool, UPPER);
    strcat(pool, DIGITS);
    strcat(pool, SYMBOLS);
    return pool;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <length>\n", argv[0]);
        return 1;
    }

    int length = atoi(argv[1]);
    if (length <= 0) {
        fprintf(stderr, "Invalid length: %s\n", argv[1]);
        return 1;
    }

    // seed RNG
    srand((unsigned)time(NULL));

    // build pool
    char *pool = build_pool();
    size_t pool_size = strlen(pool);

    // generate password
    char *password = malloc(length + 1);
    if (!password) {
        fprintf(stderr, "Memory allocation failed\n");
        free(pool);
        return 1;
    }

    for (int i = 0; i < length; i++) {
        int idx = rand() % pool_size;
        password[i] = pool[idx];
    }
    password[length] = '\0';   // درست شد

    printf("%s\n", password);  // درست شد

    free(pool);
    free(password);
    return 0;
}
