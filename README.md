# Password Strength Checker (C)

This is a simple **C program** that checks how strong a password is.

You type a password, and the program:
- Checks the length
- Looks for lowercase, uppercase, digits, and special characters
- Rates it as **Weak**, **Medium**, or **Strong**
- Shows simple suggestions to improve it

## 1. What the Program Does (Step by Step)

1. The program prints a title:
    `=== Password Strength Checker (C) ===`

2. It asks the user:
    `Enter a password to check:`

3. It reads the password from the keyboard using `fgets()`.

4. It removes the newline (`\n`) at the end so the password is clean.

5. It checks five rules:
   - Is the password at least **8 characters long**?
   - Does it contain a **lowercase letter** (a–z)?
   - Does it contain an **uppercase letter** (A–Z)?
   - Does it contain a **digit** (0–9)?
   - Does it contain a **special character** like `!`, `?`, `#`, `$`, `%`, etc.?

6. For every rule that is true, it adds **1 point** to the score.

7. Based on the total score (0–5), it decides:
   - **Weak** → 0–2 points  
   - **Medium** → 3–4 points  
   - **Strong** → 5 points  

8. It prints the overall strength:
   - Example: `Overall strength: Medium`

9. If any rule is missing, it prints suggestions:
   - Example: “Make it at least 8 characters long.”
   - Example: “Add at least one digit (0–9).”

10. If all rules are met, it prints:
    - `Nice! Your password meets all the basic criteria.`


## 2. How the Code Is Organized

- The program uses standard C headers:
  - `#include <stdio.h>`
  - `#include <string.h>`
  - `#include <ctype.h>`

- There are helper functions:
  - `has_lower()` → checks for lowercase letters  
  - `has_upper()` → checks for uppercase letters  
  - `has_digit()` → checks for numbers  
  - `has_special()` → checks for special characters  

- `main()` does the main work:
  1. Prints the title and asks for the password  
  2. Reads input into a `char password[256]`  
  3. Calls the helper functions  
  4. Calculates the score and prints strength + suggestions  

## 3. Example Outputs

Input: abc

=== Password Strength Checker (C) ===
Enter a password to check: abc

Overall strength: Weak
Suggestions to improve:
• Make it at least 8 characters long.
• Add at least one uppercase letter (A-Z).
• Add at least one digit (0-9).
• Add at least one special character (e.g. !, ?, #, $, %).
