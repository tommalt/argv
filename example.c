#include <stdio.h>
#include "argv.h"

int main(int argc, char **argv)
{
	char *tmp;
	ARGBEGIN {
	case 'x':
		printf("x values:");
		while (tmp = GETF()) {
			printf(" %s", tmp);
		}
		putchar('\n');
		break;
	case 'f':
		printf("f values:");
		while (tmp = GETF()) {
			printf(" %s", tmp);
		}
		putchar('\n');
		break;
	default:
		printf("default: op: %s\n", op);
		return 0;
	} ARGEND;
	return 0;
}
