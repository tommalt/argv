# argv.h

argv.h is **The Solution** to command line argument parsing

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
	case 'c':
		printf("[c]:");
		do {
			ARGV(val)
			if (!val) break;
			printf(" %s",val);

		} while (val != NULL);
		printf("\n");
		break;
	case 'x':
		/* saving the values */
		char **values = /* ... */
		do {
			ARGV(val)
			if (!val) break;
			values_push(&values, val);  /* or something like this */
		} while (val != NULL);
		break;
	case 'h':
		printf("No help available\n");
		return 1;
	default:
		printf("Unrecognized option\n");
		return 1;
	} ARGEND;
run:
	//...
}
```

