#!/usr/bin/python3
import random
from math import sqrt as sq
import sys

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def prime_factors_semiprime(semiprime):
    prime_factors = []
    for i in range(2, int(sq(semiprime)) + 1):
        if semiprime % i == 0:
            prime_factors.append(i)
            prime_factors.append(semiprime // i)
            break
    return prime_factors


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def pollards_rho(n):
    if n < 2:
        return None
    x = random.randint(2, n - 2)
    y = x
    d = 1

    while d == 1:
        x = (x * x + 1) % n
        y = (y * y + 1) % n
        y = (y * y + 1) % n
        d = gcd(abs(x - y), n)

    return d

def factorize_semiprime(semiprime):
    factor1 = pollards_rho(semiprime)
    if not factor1:
        return None
    factor2 = semiprime // factor1
    return factor1, factor2

def check_file():
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        exit()

def read_file_all(f_name):
    with open(f_name, "r") as fp:
        file = fp.read()
    file_content = file.splitlines()
    for line in file_content:
        try:
            semiprime = int(line.strip())
            if semiprime < 1000:
                prime_factors = sorted(prime_factors_semiprime(semiprime))
            else:
                prime_factors = sorted(list(factorize_semiprime(semiprime)))
            if len(prime_factors) == 2:
                print("{:d}={:d}*{:d}".format(semiprime, prime_factors[1], prime_factors[0]))
        except Exception as e:
            print(f"Error processing line: {e}")


def read_file_lines(f_name):
    with open(f_name, "r") as fp:
        while True:
            prime_factors = []
            line = fp.readline()
            if not line:
                break
            try:
                semiprime = int(line.strip())
                if semiprime < 1000:
                    prime_factors = sorted(prime_factors_semiprime(semiprime))
                else:
                    prime_factors = sorted(list(factorize_semiprime(semiprime)))
                if len(prime_factors) == 2:
                    print("{:d}={:d}*{:d}".format(semiprime, prime_factors[1], prime_factors[0]))
            except Exception as e:
                print(f"Error processing line: {e}")


def do_it():
    f_name = sys.argv[1]
    # read_file_all(f_name)
    read_file_lines(f_name)


if __name__ == "__main__":
    check_file()
    if (len(sys.argv) == 2):
        do_it()
