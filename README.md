# argv.h - an argument parser that sucks less

```c
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
```

argv.h is derived from the argument parser for the [simple terminal](https://st.suckless.org/)
# Installation
```shell
curl 'https://raw.githubusercontent.com/tommalt/argv/master/argv.h' | sudo tee /usr/local/include/argv.h >/dev/null 2>&1
```
