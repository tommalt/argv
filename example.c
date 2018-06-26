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
	case 'c':
		printf("received -c option\n");
		break;
	default:
		printf("Unknown option: %s\n", op);
		return 0;
	} ARGEND;
	return 0;
}
