#include <stdio.h>
// Function to encrypt or decrypt the message
void processMessage(char *message, int shift, int isEncrypt) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'A' && ch <= 'Z') {
            // Process uppercase letters
            message[i] = ((ch - 'A' + (isEncrypt ? shift : -shift) + 26) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            // Process lowercase letters
            message[i] = ((ch - 'a' + (isEncrypt ? shift : -shift) + 26) % 26) + 'a';
        }
    }
int main() {
    char message[100];
    int shift;
    // Input the message
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    // Remove the newline character from the input
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '\n') {
            message[i] = '\0';
            break;
        }
    }
    // Input the shift value
    printf("Enter shift value: ");
    scanf("%d", &shift);
    // Encrypt the message
    processMessage(message, shift, 1);
    printf("Encrypted message: %s\n", message);
    // Decrypt the message
    processMessage(message, shift, 0);
    printf("Decrypted message: %s\n", message);
    return 0;
}
