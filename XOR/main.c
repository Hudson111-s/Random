#include <stddef.h>
#include <stdio.h>
#include <string.h>

char *encrypt_and_decrypt(char *msg, int key, size_t msg_len) {
    for (int i = 0; i < msg_len; i++) {
        msg[i] = msg[i]^key;
    }
    
    return msg;
}

int main(void) {
    // Encrypt/decrypt.
    char msg[] = "hello";
    size_t msg_len = strlen(msg);
    int key = 67;

    char *msg_enc = encrypt_and_decrypt(msg, key, msg_len);
    printf("Encrypt = %s\n", msg_enc);
    char *msg_dec = encrypt_and_decrypt(msg_enc, key, msg_len);
    printf("Decrypt = %s\n", msg_dec);

    // Swapping variables.
    int a = 67, b = 1738;
    printf("a = %d b = %d\n", a, b);
    a ^= b; // a = 67^1738, b = 1738
    b ^= a; // a = 67^1738, b = 1738^67^1738
    a ^= b; // a = 67^1738^67, b = 67
    printf("a = %d b = %d\n", a, b);

    // Finding duplicate.
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 7, 8, 9, 10};
    size_t arr_len = 11;
    int x = 0;
    
    for (int i = 0; i < arr_len; i++) {
        x ^= i;
    }

    for (int i = 0; i < arr_len; i++) {
       x ^= arr[i];
    }

    printf("Duplicate = %d\n", x);

    return 0;
}
