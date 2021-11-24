#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <unistd.h>

//GCD using Euclids algorithm
unsigned long long int GCD(unsigned long long int a, unsigned long long int b)
{
    if(a==0)
    {
        return b;
    }
    else if(b == 0)
    {
            return a;
    }
    return GCD(a%b, a);
}


unsigned long long int modInverse(unsigned long long int a, unsigned long long int m)
{
    for (unsigned long long  int x = 1; x < m; x++)
    {
        if (((a%m) * (x%m)) % m == 1)
        {
            return x;
        }
    }
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
unsigned long long int power(unsigned long long int d, unsigned long long int e, unsigned long long int p)
{
    unsigned long long int res=1;
    while(e>0) {
        if(e%2==1) {
            res=(res*d)%p;
        }
        d=(d*d)%p;
        e=e/2;
    }
    return res;
} 

unsigned long long int randomNumber(unsigned long long int q)
{
    unsigned long long int randNo =  rand();
    while (GCD(q, randNo) != 1)
        randNo = rand();
}

int IsPrime(unsigned long long int n)
{
    int flag =1;
    // Iterate from 2 to sqrt(n)
    for (unsigned long long int i = 2; i <= sqrt(n); i++)
    {
 
        // If n is divisible by any number between
        // 2 and n/2, it is not prime
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    return flag;
}


int encrypt(unsigned long long int msg, unsigned long long int q, unsigned long long int y,
    unsigned long long int a, unsigned long long int* c1, unsigned long long int* c2)
{
    unsigned long long int k, K;
    
    if(msg > q)
    {
        printf("Message %llu should be less than q %llu ", msg, q);
        return 1;  
    }

    printf("\n***************************Encryption***************************\n");
    printf("\nOriginal Message                 : %llu", msg);
    printf("\nPrime number q used              : %llu", q);
    printf("\nPrimitive root a used            : %llu", a);
    printf("\nPublic key y used                : %llu", y);
    printf("\nPrimitive root a used            : %llu", a);

    //Select random integer k < q
    k=rand()%(q-1)+1;

    //Calculate K = (YA)k mod q
    K = power(y, k, q);
    //Calculate C1 = ak mod q
    *c1=power(a, k, q);
    //Calculate C2 = KM mod q
    *c2=(msg*K) % q;

    printf("\nEncrypted message (c1, c2)       : (%llu, %llu)", *c1, *c2);
    return 0;
}

unsigned long long int  decrypt(unsigned long long int c1, unsigned long long int c2, unsigned long long int x, unsigned long long int q)
{
    unsigned long long int K, KInv, decM;

    printf("\n\n***************************Decryption***************************\n");
    printf("\nMessage to be decrypted (c1, c2) : (%llu, %llu)", c1, c2);
    printf("\nPrime number q used              : %llu", q);
    printf("\nPrivate key y used               : %llu", x);

    ///Calculate K = (C1)XA mod q
    K=power(c1, x, q);

    //Plaintext: M = (C2 * KIInv) mod q
    KInv = modInverse(K, q);

    decM=(c2 * KInv) % q;

    printf("\nDecrypted secret message         : %llu\n", decM);

    return decM;
}

unsigned long long int getPublicKey(unsigned long long int q, unsigned long long int a,unsigned long long int x)
{   unsigned long long int y = power(a, x, q);
    return y;
}
int main(int argc, char *argv[]) 
{
    unsigned long long int msg, q, a, x, y, c1, c2;
    char choice;
    q = 999999999999989;
    msg = 12345;
    a = 3;
    x = 53582;
    y = getPublicKey(q, a, x);
    if(!IsPrime(q))
    {
        printf("Q should be prime number. Given %llu. Exiting....", q);
        return 0;
    }

    while(1)
    {
        printf("\nChoose: a (encrypt and decrypt) | s (set prime number q and generator a) | e (encrypt) | d (decrypt) | k (set private, public key) | x (exit)? ");
        scanf("%s", &choice);
        switch(choice) {
            case 'a':
                printf("Type secret number to send: ");
                scanf("%llu", &msg);

                int res = encrypt(msg, q, y, a, &c1, &c2);
                if(res != 0) continue;

                decrypt(c1, c2, x, q);
                break;
            case 'k':
                printf("Type private key: ");
                scanf("%llu", &x);
                y = getPublicKey(q, a, x);
                printf("Public key is: %llu\n", y);
                break;
            case 's':
                printf("Type prime number q: ");
                scanf("%llu", &q);
                printf("Type generator a: ");
                scanf("%llu", &a);
                break;
            case 'e':
                printf("Type secret number to send: ");
                scanf("%llu", &msg);
                printf("Type recipient's public key: ");
                scanf("%llu", &y);

                encrypt(msg, q, y, a, &c1, &c2);
                break;
            case 'd':
                printf("Type the recieved message in the form (a,b): ");
                scanf("%llu %llu", &c1, &c2);
                printf("Type in your private key: ");
                scanf("%llu", &x);

                decrypt(c1, c2, x, q);
                break;          
            case 'x':
            default:
                return 0;
                break;
        }
    }
    return 0;
}