def is_prime(n):
    """Check if a number is prime."""
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def prime_factors_semiprime(semiprime):
    from math import sqrt as sq
    """Find the prime factors of a semiprime."""
    prime_factors = []
    for i in range(2, int(sq(semiprime)) + 1):
        if semiprime % i == 0:
            prime_factors.append(i)
            prime_factors.append(semiprime // i)
            break  
    return prime_factors

def do_it():
    import sys
    f_name = sys.argv[1]
    with open(f_name) as fp:
        while True:
            line = fp.readline()
            if not line:
                break
            try:
                semiprime = int(line.strip())
                prime_factors = prime_factors_semiprime(semiprime)
                if (len(prime_factors) == 2):
                    print("{:d}={:d}*{:d}".format(semiprime, prime_factors[1], prime_factors[0]))
            except Exception:
                pass


if __name__ == "__main__":
    import sys
    if (len(sys.argv) == 2):
        do_it()    
