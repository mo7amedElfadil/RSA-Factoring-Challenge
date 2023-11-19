#include "rsa.h"

/**
 * _realloc - reeallocates a memory block using malloc and free
 * @ptr: pointer to reallocate memory of
 * @old_size: the old size of the pointer
 * @new_size: the new size of the pointer
 * Return: the reassigned pointer (Success)
 *			NULL (Failure) when malloc fails to assign or new_size is 0
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *real = NULL, *temp;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		return (malloc(new_size));
	}
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	temp = ptr;
	real = malloc(new_size);
	if (!real)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			real[i] = temp[i];
	}
	else if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			real[i] = temp[i];
	}
	free(ptr);
	return (real);
}
/**
 * _open_rsa - open a rsa file containing rsa numbers
 * @f_name: name of file
 * Return: file stream
 */
FILE *_open_rsa(char *f_name)
{
	FILE *stream;

	stream = fopen(f_name, "r");
	if (!stream)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", f_name);
		if (stream)
			fclose(stream);
		exit(EXIT_FAILURE);
	}
	else
		return (stream);
}

/**
 * _atoi - converts string to an integer
 * @s: string pointer
 *
 * Return: 0 if there're no numbers in the string,
 * otherwise return the integer
 */
longy _atolongy(char *s)
{
	longy num = 0;

	while (*s)
	{
		if (*s >= 48 && *s <= 57)
			num = (num * 10) + (*s - 48);
		s++;

	}

	return (num);
}

/**
 * is_prime - Function to check if a number is prime
 * @num: number to check
 * Return: 0 if not prime 1 if prime
 */
int is_prime(longy num)
{
	if (num <= 1)
		return (0);
	for (longy i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
			return (0);
	}
	return (1);
}

/* prime_factors_semiprime - Function to find the prime factors of a semiprime
 * @semiprime: semiprime RSA number
 * @prime_factors: int pointer to return ints
 */
void prime_factors_semiprime(longy semiprime, longy *prime_factors)
{
	for (longy i = 2; i < semiprime; ++i)
	{
		if (semiprime % i == 0 && is_prime(i))
		{
			prime_factors[0] = i;
			prime_factors[1] = semiprime / i;
			break;
		}
	}
}
