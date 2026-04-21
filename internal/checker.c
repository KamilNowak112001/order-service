#include <stdio.h>
#include <string.h>
#include <stdint.h>

void derive_key(char *input, uint8_t *out_key) {
    int len = strlen(input);

    for (int i = 0; i < 16; i++) {
        out_key[i] = input[i % len] ^ (i * 31) ^ 0x55;
    }
}

void transform(char *input, uint8_t *key, uint8_t *output) {
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        uint8_t k = key[i % 16];
        output[i] = (input[i] ^ k) + (i % 7);
    }
}

int check(uint8_t *data, int len) {
    uint8_t expected[] = {
        0x3a, 0x21, 0x2f, 0x35, 0x10, 0x0c
    };

    if (len != 6) return 0;

    for (int i = 0; i < 6; i++) {
        if (data[i] != expected[i]) return 0;
    }

    return 1;
}

int main() {
    char input[64];
    char osint_key[64];

    uint8_t key[16];
    uint8_t transformed[64];

    printf("Enter admin password: ");
    scanf("%s", input);

    printf("Enter debug key: ");
    scanf("%s", osint_key);

    derive_key(osint_key, key);
    transform(input, key, transformed);

    if (check(transformed, strlen(input))) {
        printf("flag{full_chain_compromise}\n");
    } else {
        printf("Invalid credentials\n");
    }

    return 0;
}