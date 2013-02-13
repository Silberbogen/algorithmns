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

// File: algorithmns.c
// version: 2013-02-13-a

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algorithmns.h"

// ------------------------------------------------------
//  Implementation of a greatest common divisor function
// ------------------------------------------------------
// greatest common divisor for two numbers, u and v
// implementation of Euclid's Algorithm
// usage: gcd(25, 35, 50, 125); // 5
int gcd_single(int u, int v) {
    while (u > 0) {
        if ( u < v) {
            // swapping u and v
            int temp = u;
            u = v;
            v = temp;
        }
        u = u - v;
    }
    return v;
}

// greatest common divisor for a list of numbers
// at least, one number u must be given
int gcd_array(int in[]) {
    int len = sizeof in / sizeof in[0];
    int v = in[0];
    for(int i = 1; i < len; i++) v = gcd_single(in[i], v);
    return v;
}
// -------------------------------------------------------

// ------------------------------------------------------
//  Implementation of largest common multiple
// ------------------------------------------------------
// largest common multiple for two numbers, a and b
// usage: lcm(12, 36, 72, 120); // 12
int lcm_single(int a, int b) {
    if (a && b) return a * b / gcd(a, b);
    return 0;
}

// largest common multiple for a list of numbers
// at least, one number must be given
int lcm_array(int in[]) {
    int len = sizeof in / sizeof in[0];
    int j = in[0];
    for(int i = 1; i < len; i++) j = lcm_single(in[i], j);
    return j;
}
// -------------------------------------------------------


// ------------------------------------------------------
// Implementation of a prime number generator 
// ------------------------------------------------------
// Creates a generator for prime numbers
// todo: implement a threaded version

long long primeNumberGenerator(void) {
    static long long old_number = 0;
    static long long new_number = 2;
    static long long n_sieb = 1;
    static long long *sieb;

    // Handling of the special cases
    if (new_number == 2) {
        sieb = calloc(n_sieb, sizeof(long long));
        sieb[n_sieb - 1] = 2;
        old_number = 2;
        new_number = 3;
        return old_number;
    }
    // the main loop for searching the next prime number
    for (;;) {
        _Bool istPrimzahl = 1;
        for (int i = 0; i < n_sieb; i++) {
            if (new_number % sieb[i]  == 0) {
                istPrimzahl = 0;
                break;
            }
        }
        // The loop should only be left, if a next prime
        // number was found, then this new one will be
        // returned
        if (istPrimzahl) {
            // allocate (the first time), or reallocate enough memory
            n_sieb += 1;
            sieb = realloc(sieb, n_sieb * sizeof(long long));
            sieb[n_sieb - 1] = new_number;
            old_number = new_number;
            new_number += 2;
            return old_number;
        }
        new_number += 2;
    }
    // Problem! The endless loop was left!
    return 0;
}
