# argv.h

```c
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
```
```
$ ./a.out -c -d -x 1 2 3 -f /usr/include/stdio.h --foo fighter --bar exam --baz ooka gum
received -c option
Received -d option
x values: 1 2 3
f values: /usr/include/stdio.h
foo = fighter
bar = exam
baz: ooka gum
```

argv.h is derived from the argument parser for the [simple terminal](https://st.suckless.org/)
# Installation
```shell
curl 'https://raw.githubusercontent.com/tommalt/argv/master/argv.h' | sudo tee /usr/local/include/argv.h >/dev/null 2>&1
```

# Notes
The `LONGARG`, `SHORTARG` and `ARGEND` macros must all be called in order for it to work.
If your program does not use long options, simply leave the body blank: `LONGARG { }`.
If your program does not use short options, just handle the the `default` case of the switch statement.  

The `LONGARG` macro populates a variable `option` which points to the canonical option name.
Use this along with `strcmp` to determine the option key.  

Use `GETL` and `GETS` to get the values for long and short options, respectively. If multiple
values are expected for a given option, use a loop as shown in the example.
