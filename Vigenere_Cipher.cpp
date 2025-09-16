#include <iostream> // header files
#include <cstring>  // header files


using namespace std;


// Function to perform Vigenère encryption
void vigenere_encrypt(char src[100], const char* key) {
    int keyLength = strlen(key);
    int keyIndex = 0; // Index for the key


    for (int i = 0; src[i] != '\0'; i++) {
        char currentChar = src[i];


        // Only encrypt alphabetic characters
        if (isalpha(currentChar)) {
            char keyChar = tolower(key[keyIndex % keyLength]) - 'a'; // Get the key character
            if (isupper(currentChar)) {
                // Encrypt uppercase letters
                src[i] = (char)(((currentChar - 'A' + keyChar) % 26) + 'A');
            } else {
                // Encrypt lowercase letters
                src[i] = (char)(((currentChar - 'a' + keyChar) % 26) + 'a');
            }
            keyIndex++; // Move to the next character in the key
        }
    }
}


// Function to perform Vigenère decryption
void vigenere_decrypt(char src[100], const char* key) {
    int keyLength = strlen(key);
    int keyIndex = 0; // Index for the key


    for (int i = 0; src[i] != '\0'; i++) {
        char currentChar = src[i];


        // Only decrypt alphabetic characters
        if (isalpha(currentChar)) {
            char keyChar = tolower(key[keyIndex % keyLength]) - 'a'; // Get the key character
            if (isupper(currentChar)) {
                // Decrypt uppercase letters
                src[i] = (char)(((currentChar - 'A' - keyChar + 26) % 26) + 'A');
            } else {
                // Decrypt lowercase letters
                src[i] = (char)(((currentChar - 'a' - keyChar + 26) % 26) + 'a');
            }
            keyIndex++; // Move to the next character in the key
        }
    }
}


int main() { // Corrected to int main
    char caesar[10];
    static const char encrypt[] = "encrypt";
    static const char decrypt[] = "decrypt";
    char key[100]; // To hold the encryption key
    char src[100];
    int result1;
    int result2;


    cout << "Enter operation: encrypt or decrypt" << endl;
    cin >> caesar;


    cout << "Enter key" << endl;
    cin.ignore(); // Clear the newline character left in the input buffer
    cin.getline(key, 100); // Read the key for encryption/decryption


    cout << "Enter text to encrypt/decrypt" << endl;
    cin.getline(src, 100); // Read the text


    result1 = strcmp(caesar, encrypt); // checking if it is encryption
    result2 = strcmp(caesar, decrypt); // checking if it is decryption


    if (result1 == 0) {
        vigenere_encrypt(src, key); // Encrypt using Vigenère cipher
    }
    if (result2 == 0) {
        vigenere_decrypt(src, key); // Decrypt using Vigenère cipher
    }


    cout << "Result:" << endl;
    cout << src << endl;


    return 0; // Correctly return 0 to indicate successful completion
}
