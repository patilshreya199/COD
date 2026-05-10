#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate gcd
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular exponentiation
long long modExp(long long base, long long exp, long long mod)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }

    return result;
}

// Function to find multiplicative inverse of e
int modInverse(int e, int phi)
{
    for (int d = 1; d < phi; d++)
    {
        if ((d * e) % phi == 1)
            return d;
    }
    return -1;
}

int main()
{
    int p, q;

    cout << "Enter two prime numbers: ";
    cin >> p >> q;

    // Step 1: Calculate n
    int n = p * q;

    // Step 2: Calculate phi(n)
    int phi = (p - 1) * (q - 1);

    // Step 3: Choose e
    int e;
    for (e = 2; e < phi; e++)
    {
        if (gcd(e, phi) == 1)
            break;
    }

    // Step 4: Calculate d
    int d = modInverse(e, phi);

    cout << "\nPublic Key (e, n): (" << e << ", " << n << ")";
    cout << "\nPrivate Key (d, n): (" << d << ", " << n << ")\n";

    // Message input
    int message;
    cout << "\nEnter message (number): ";
    cin >> message;

    // Encryption
    long long cipher = modExp(message, e, n);
    cout << "Encrypted Message: " << cipher << endl;

    // Decryption
    long long decrypted = modExp(cipher, d, n);
    cout << "Decrypted Message: " << decrypted << endl;

    return 0;
}
