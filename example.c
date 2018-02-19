#include <stdio.h>
#include "argv.h"
int main(int argc, char **argv)
{
	char *val;
	char *argv0;
	ARGBEGIN {
	case 'a':
		printf("[a]:");
		while (HAS_ARGS()) {
			val = NEXT_ARG();
			printf(" %s",val);
		}
		printf("\n");
		break;
	case 'r':
		printf("[r]:");
		while (HAS_ARGS()) {
			val = NEXT_ARG();
			printf(" %s",val);
		}
		printf("\n");
		break;
	case 'g':
		printf("[g]:");
		while (HAS_ARGS()) {
			val = NEXT_ARG();
			printf(" %s",val);
		}
		printf("\n");
		break;
	case 'v':
		printf("[v]:");
		while (HAS_ARGS()) {
			val = NEXT_ARG();
			printf(" %s",val);
		}
		printf("\n");
		break;
	case 'b':
		NEXT_ARG();
		break;
	default:
		printf("Unrecognized option\n");
	} ARGEND;
}
