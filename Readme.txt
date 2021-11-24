Name   - Nithyapriya S
RollNo - CS21M510
mail   - nithyapriya1997@gmail.com

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
To generate binary - gcc Elgamal.c -o main

Command:  main.exe
Usage:
    Choose: a (get key, encrypt and decrypt)
            s (set prime number q and generator a)
            e (encrypt)
            d (decrypt)
            k (set private, public key)
            x (exit)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Case 1:

Choose: a (get key, encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? s
Type prime number q: 9962437
Type generator a: 2

Choose: a (get key, encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? k
Type private key: 65454
Public key is: 845750

Choose: a (get key, encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? a
Type secret number to send: 453453

***************************Encryption***************************

Original Message                 : 453453
Prime number q used              : 9962437
Primitive root a used            : 2
Public key y used                : 845750
Primitive root a used            : 2
Encrypted message (c1, c2)       : (9496584, 7749431)

***************************Decryption***************************

Message to be decrypted (c1, c2) : (9496584, 7749431)
Prime number q used              : 9962437
Private key y used               : 65454
Decrypted secret message         : 453453

Choose: a (get key, encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? x

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Case 2:

Choose: a (get key, encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? a
Type secret number to send: 7656421

***************************Encryption***************************

Original Message                 : 7656421
Prime number q used              : 99977197
Primitive root a used            : 3
Public key y used                : 80678288
Primitive root a used            : 3
Encrypted message (c1, c2)       : (22381124, 98586669)

***************************Decryption***************************

Message to be decrypted (c1, c2) : (22381124, 98586669)
Prime number q used              : 99977197
Private key y used               : 53582
Decrypted secret message         : 7656421

Choose: a (get key, encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? x