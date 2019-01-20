#include <stdio.h>
#include <string.h>

#include "argv.h"

void usage()
{
	printf(
"usage: a.out [-hcd] [-x STR...] [-f FILE...] [--foo STR] [--bar STR] [--baz STR...]\n"
	);
}

int main(int argc, char **argv)
{
	char *tmp;
	LONGARG {
	if (strcmp(option, "foo") == 0) {
		tmp = GETL();
		printf("foo = %s\n", tmp);
	} else if (strcmp(option, "bar") == 0) {
		tmp = GETL();
		printf("bar = %s\n", tmp);
	} else if (strcmp(option, "baz") == 0) {
		printf("baz:");
		while (tmp = GETL()) {
			printf(" %s", tmp);
		}
		putchar('\n');
	} else {
		printf("Unkown option: %s\n", option);
		return 1;
	}

	} SHORTARG {
	case 'x':
		printf("x values:");
		while (tmp = GETS()) {
			printf(" %s", tmp);
		}
		putchar('\n');
		break;
	case 'f':
		printf("f values:");
		while (tmp = GETS()) {
			printf(" %s", tmp);
		}
		putchar('\n');
		break;
	case 'c':
		printf("received -c option\n");
		break;
	case 'd':
		printf("Received -d option\n");
		break;
	case 'h':
		usage();
		return 0;
	default:
		printf("Unknown option: %s\n", op);
		return 0;
	} ARGEND

	if (argc) {
		printf("remaining arguments: %d\n", argc);
		for (int i = 0; i < argc; i++) {
			printf("%s\n", argv[i]);
		}
	}
	return 0;
}
