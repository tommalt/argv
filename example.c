#include <stdio.h>
#include "argv.h"
int main(int argc, char **argv)
{
	char *val;
	char *argv0;
	ARGBEGIN {
	case 'c':
		printf("[c]:");
		do {
			ARGV(val)
			if (!val) break;
			printf(" %s",val);

		} while (val != NULL);
		printf("\n");
		break;
	case 'd':
		printf("[d]:");
		do {
			ARGV(val)
			if (!val) break;
			printf(" %s",val);
		} while (val != NULL);
		printf("\n");
		break;
	case 's':
		printf("[s]:");
		do {
			ARGV(val)
			if (!val) break;
			printf(" %s",val);
		} while (val != NULL);
		printf("\n");
		break;
	case 'p':
		printf("[p]:");
		do {
			ARGV(val)
			if (!val) break;
			printf(" %s",val);
		} while (val != NULL);
		printf("\n");
		break;
	case 'v':
		printf("[v]:");
		do {
			ARGV(val)
			if (!val) break;
			printf(" %s",val);
		} while (val != NULL);
		printf("\n");
		break;
	default:
		printf("Unrecognized option\n");
	} ARGEND;
}
