#include <stdio.h>

// 快速幂取模函数
int pow_mod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 扩展欧几里得算法求模逆元
int mod_inverse(int e, int phi) {
    int old_r = e, r = phi;
    int old_s = 1, s = 0;
    while (r != 0) {
        int quotient = old_r / r;
        int temp = old_r - quotient * r;
        old_r = r;
        r = temp;
        temp = old_s - quotient * s;
        old_s = s;
        s = temp;
    }
    if (old_r != 1) return -1;
    if (old_s < 0) old_s += phi;
    return old_s;
}

int main() {
    int p = 11, q = 13, e = 7;
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    
    // 计算私钥d
    int d = mod_inverse(e, phi);
    printf("私钥d: %d\n", d);
    
    // 加密过程
    int m1 = 85, m2 = 91;
    int c1 = pow_mod(m1, e, n);
    int c2 = pow_mod(m2, e, n);
    printf("密文: m1=%d -> c1=%d\n", m1, c1);
    printf("     m2=%d -> c2=%d\n", m2, c2);
    
    // 解密过程
    int y = 123;
    int decrypted = pow_mod(y, d, n);
    printf("明文: y=%d -> 明文=%d\n", y, decrypted);
    
    return 0;
}