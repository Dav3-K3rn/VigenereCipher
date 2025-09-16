# Vigenère Cipher in C++

This project implements the **Vigenère Cipher**, a classic method of encrypting and decrypting alphabetic text using a keyword.  
It extends the Caesar cipher by using a sequence of shifts determined by letters in a key.

---

## Features

- **Encryption**: Shifts letters based on the repeating key characters.
- **Decryption**: Reverses the process to restore the original text.
- **Case-Sensitive**: Preserves uppercase and lowercase letters.
- **Key Handling**: Automatically cycles through the key, regardless of text length.
- Ignores non-alphabetic characters (spaces, numbers, punctuation remain unchanged).

---

## How It Works

1. The user specifies the operation:
   - `encrypt`
   - `decrypt`
2. The user provides:
   - A **key** (string of letters).
   - A **text message** to encrypt or decrypt.
3. The program outputs the result.
