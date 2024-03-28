#include "monty.h"


/**
 * tokenize - funct that take line & tokenize it
 *
 * @content: is pntr to line of file
 * @op: operation order
 *
 * Return: the rslt Token
 */

char *tokenize(char *content, __attribute__((unused)) char **op)
{
	return (strtok(content, " \n\t"));
}
