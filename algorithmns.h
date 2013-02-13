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

// File: algorithmns.h
// version: 2013-02-13-a

#ifndef _ALGORITHMNS_H
#define _ALGORITHMNS_H

// ------------------------------------------------------
//  Implementation of a greatest common divisor function
// ------------------------------------------------------
// First the declaration of the greatest common divisor
// function, returning the gcd as integer from a given
// array of integers
int gcd_array(int in[]);
// and now the macro for easily calling our gcd function
#define gcd(...) gcd_array( (int[]){__VA_ARGS__} )
// -------------------------------------------------------


// ------------------------------------------------------
//  Implementation of largest common multiple
// ------------------------------------------------------
// First the declaration of the largest common multiple
// function, returning the lcm as integer from a given
// array of integers
int lcm_array(int in[]);
// and now the macro for easily calling our lcm function
#define lcm(...) lcm_array( (int[]){__VA_ARGS__} )
// -------------------------------------------------------


#endif // _ALGORITHMNS_H
