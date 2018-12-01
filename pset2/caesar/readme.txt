TODO
-Get the key
-Get the plaintext
-Encipher
    -one character
    -entire plaintext
-Print ciphertext


-Get key from command line argument
-Turn key into integer
-Prompt for plaintext

For each character in the plaintext string
    if alphabetic
        preserve case
        shift plaintext character by key
print ciphertext

Shift characters only: isalpha
Preserve capitalization: isupper, islower

isalpha('Z') -> true
isupper('Z') -> true
islower('Z') -> false

char letter = 'Z';
if (isupper(letter))
{
    printf(letter);
}

ci = (pi + k) % 26
ci : ith ciphertext letter
pi : ith plaintext letter
k: key
% 26: remainder after dividing by 26


('A' + 2) % 26
= (65 + 2) % 26
= 67 % 26
= 15

C = 67

Alphabetical Index:

'A' + 2 = 'C'

A: 0

(0 + 2) % 26
= 2 % 26
= 2

C = 2

('Y' + 2) % 26

=(89 + 2) % 26
=91 % 26
=13

A = 65

Y: 24
(24 + 2) % 26
= 26 % 26
= 0

A= 0

Alphabet wraparound

-Start with ASCII values
-encipher: alphabetical index
-print: ASCII values

ASCII -> alphabetical
alphabetical -> ASCII

string text = "This is CS50";
text[0] -> T, text[1] -> 'h'

strlen(text) -> 12




