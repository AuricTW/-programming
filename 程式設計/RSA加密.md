`尚未完成 預計完成時間(3/20)`  
RSA是一種非對稱加密算法，用於加密和解密數據。它基於大數分解問題，這是一種在大多數情況下被認為是不可解的數學問題。RSA算法依賴於兩個大質數之間的乘積難以分解。它包含三個主要步驟：生成公鑰和私鑰、加密和解密。

生成公鑰和私鑰
選擇兩個大質數p和q，並計算n = p * q。
計算phi(n) = (p-1) * (q-1)。
選擇一個整數e，1 < e < phi(n)，並且e和phi(n)互質。
計算d，滿足(d * e) % phi(n) = 1。這裡，d是私鑰。
公鑰是(e, n)，私鑰是(d, n)。

加密  
  + 將明文轉換為數字m，其中m < n。  
  + 計算密文c = m^e mod n。
  
解密  
  + 接收到密文c。  
  + 計算明文m = c^d mod n。  
```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int is_prime(int );
int gcd(int , int );
int generate_key(int *, int *, int *, int , int );
int encrypt(int , int , int );
int decrypt(int , int , int );

int main() {
    int p, q, e, d, n, m, c, m_decrypt;
    printf("輸入質數 p: ");
    scanf("%d", &p);
    while (!is_prime(p)) {  //判斷p是否為質數
        printf("輸入錯誤, 請輸入一個質數: ");
        scanf("%d", &p);
    }
    printf("Enter the value of q: ");
    scanf("%d", &q);
    while (!is_prime(q)) {  //判斷p是否為質數
        printf("輸入錯誤, 請輸入一個質數: ");
        scanf("%d", &q);
    }
    generate_key(&e, &d, &n, p, q);
    printf("公鑰: (%d, %d)\n", e, n);
    printf("私鑰: (%d, %d)\n", d, n);
    printf("輸入要加密的數值 m: ");
    scanf("%d", &m);
    c = encrypt(m, e, n);
    printf("密文: %d\n", c);
    m_decrypt = decrypt(c, d, n);
    printf("Decrypted message: %d\n", m_decrypt);
    return 0;
}

int is_prime(int n) {
    int i;
    if (n <= 1) {
        return 0;
    }
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int generate_key(int *e, int *d, int *n, int p, int q) {
    int phi, i;
    *n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        *e = rand() % (phi - 2) + 2;
    } while (gcd(*e, phi) != 1);
    i = 1;
    while (((phi * i) + 1) % *e != 0) {
        i++;
    }
    *d = ((phi * i) + 1) / *e;
}

int encrypt(int m, int e, int n) {
    int c = 1;
    int i;
    for (i = 0; i < e; i++) {
        c = (c * m) % n;
    }
    return c;
}

int decrypt(int c, int d, int n) {
    int m = 1;
    int i;
    for (i = 0; i < d; i++) {
        m = (m * c) % n;
    }
    return m;
}
```
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Step 1: Select two large prime numbers p and q
    int p, q;
    printf("Enter two large prime numbers p and q:\n");
    scanf("%d %d", &p, &q);

    // Step 2: Calculate n = p * q
    int n = p * q;

    // Step 3: Calculate phi(n) = (p-1) * (q-1)
    int phi = (p - 1) * (q - 1);

    // Step 4: Select an integer e, 1 < e < phi(n), and e and phi(n) are coprime
    int e;
    printf("Enter an integer e such that 1 < e < phi(n) and e is coprime with phi(n):\n");
    scanf("%d", &e);

    // Step 5: Calculate d, such that (d * e) % phi(n) = 1
    int k = 1;
    int d;
    while (1) {
        d = (k * phi + 1) / e;
        if ((d * e) % phi == 1) {
            break;
        }
        k++;
    }

    // Step 6: Print the public and private keys
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    // Step 7: Encrypt a message M using the public key
    int M;
    printf("Enter a message M to be encrypted:\n");
    scanf("%d", &M);
    int C = fmod(pow(M, e), n);
    printf("Encrypted message: %d\n", C);

    // Step 8: Decrypt the message using the private key
    int D = fmod(pow(C, d), n);
    printf("Decrypted message: %d\n", D);

    return 0;
}
