#ifndef RSA_H
#define RSA_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>
typedef unsigned long long int longy;
FILE *_open_rsa(char *f_name);
void _rev_string(char *s);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
longy _atolongy(char *s);
int is_prime(longy num);
void prime_factors_semiprime(longy semiprime, longy *prime_factors);
#endif
