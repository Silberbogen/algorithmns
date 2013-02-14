/*
Copyright (c) 2013, Sascha Biermanns
Permission to use, copy, modify, and/or distribute this software for any
purpose with or without fee is hereby granted, provided that the above
copyright notice and this permission notice appear in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

// File: test.c
// version: 2013-02-14-a

#include <stdio.h>
#include "algorithmns.h"

int main() {
    // testing for gcd
    printf("gcd of 3, 6, 12, 24, 9 = %d\n", gcd(3, 6, 12, 24, 9));
    printf("gcd of 25, 35, 50, 125 = %d\n", gcd(25, 35, 50, 125));
    printf("gcd of 1 = %d\n", gcd(1));
    // testing for lcm
    printf("lcm of 12, 36, 72 = %d\n", lcm(12, 36, 72));
    // testing for prime numbers
    printf("Primzahl: ");
    for (int i = 0; i < 200; i++) printf("%lld, ", primeNumberGenerator());
    puts("");
    resetPrimeNumberGenerator();
}
