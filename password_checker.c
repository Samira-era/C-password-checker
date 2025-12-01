// password_checker.c
// Simple password strength checker in C.
// Checks: length >= 8, lowercase, uppercase, digit, special character.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int has_lower(const char *pwd) {
    for (int i = 0; pwd[i] != '\0'; i++) {
        if (islower((unsigned char)pwd[i])) {
            return 1;
        }
    }
    return 0;
}

int has_upper(const char *pwd) {
    for (int i = 0; pwd[i] != '\0'; i++) {
        if (isupper((unsigned char)pwd[i])) {
            return 1;
        }
    }
    return 0;
}

int has_digit(const char *pwd) {
    for (int i = 0; pwd[i] != '\0'; i++) {
        if (isdigit((unsigned char)pwd[i])) {
            return 1;
        }
    }
    return 0;
}

int has_special(const char *pwd) {
    const char *specials = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    for (int i = 0; pwd[i] != '\0'; i++) {
        for (int j = 0; specials[j] != '\0'; j++) {
            if (pwd[i] == specials[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main(void) {
    char password[256];

    printf("=== Password Strength Checker (C) ===\n");
    printf("Enter a password to check: ");

    // use fgets so spaces/symbols are allowed
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // remove newline if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("You didn't type anything. Please run the program again.\n");
        return 0;
    }

    int score = 0;

    int length_ok = (len >= 8);
    int lower_ok  = has_lower(password);
    int upper_ok  = has_upper(password);
    int digit_ok  = has_digit(password);
    int special_ok = has_special(password);

    if (length_ok) score++;
    if (lower_ok)  score++;
    if (upper_ok)  score++;
    if (digit_ok)  score++;
    if (special_ok) score++;

    const char *strength;
    if (score <= 2) {
        strength = "Weak";
    } else if (score == 3 || score == 4) {
        strength = "Medium";
    } else {
        strength = "Strong";
    }

    printf("\nOverall strength: %s\n", strength);

    // simple suggestions
    if (!length_ok || !lower_ok || !upper_ok || !digit_ok || !special_ok) {
        printf("Suggestions to improve:\n");
        if (!length_ok) {
            printf("• Make it at least 8 characters long.\n");
        }
        if (!lower_ok) {
            printf("• Add at least one lowercase letter (a-z).\n");
        }
        if (!upper_ok) {
            printf("• Add at least one uppercase letter (A-Z).\n");
        }
        if (!digit_ok) {
            printf("• Add at least one digit (0-9).\n");
        }
        if (!special_ok) {
            printf("• Add at least one special character (e.g. !, ?, #, $, %).\n");
        }
    } else {
        printf("Nice! Your password meets all the basic criteria.\n");
    }

    return 0;
}
