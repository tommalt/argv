# argv.h - an argument parser that sucks less

```c
/* 
 * the ARGV macro points `val` to the next value for the current option,
 * and yields NULL when there is nothing more to collect
 */
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
		NEXT_ARG(); /* for flags with no values (boolean) this
		               call is necessary to avoid infinite loop */
		break;
	default:
		printf("Unrecognized option\n");
	} ARGEND;
}
```

argv.h is derived from the argument parser for the [simple terminal](https://st.suckless.org/)
# Installation
```shell
curl 'https://raw.githubusercontent.com/tommalt/argv/master/argv.h' | sudo tee /usr/local/include/argv.h >/dev/null 2>&1
```
