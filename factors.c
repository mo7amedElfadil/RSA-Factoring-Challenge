
#include "rsa.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 * @ac: argument count
 * @av:argument vector
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	FILE *stream;
	char *input;
	size_t len = 120;
	int line = 0, line_number = 1;
	longy semiprime = 0;
	longy prime_factors[2] = {0};

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: factores <file>\n");
		exit(EXIT_FAILURE);
	}
	stream = _open_rsa(av[1]);

	input = malloc(len);
	if (!input)
		dprintf(STDERR_FILENO, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	line = getline(&input, &len, stream);
	while (line >= 0)
	{
		semiprime = _atolongy(input);
		prime_factors_semiprime(semiprime, prime_factors);
		dprintf(STDOUT_FILENO, "%llu=%llu*%llu\n", semiprime,
				prime_factors[1], prime_factors[0]);

		line = getline(&input, &len, stream);
		line_number++;
	}

	dprintf(STDOUT_FILENO, "\n");

	return (0);
}





