/*
 * argv.h - an argument parser that sucks even less.
 * derived work of https://st.suckless.org/
 * by Tom Maltese
 */ 

#ifndef ARGV_H__
#define ARGV_H__

#define ARGBEGIN \
int ac; \
char **av; \
for (ac = argc - 1, av = argv + 1; \
     ac && *av && av[0][0] == '-'; ac--, av++) { \
	int brk = 0; \
	char *op; \
	if (av[0][1] == '-') { \
		ac--; av++; \
		break; \
	} \
	for (op = (*av) + 1; *op && !brk; op++) { \
		switch (*op)
#define ARGEND \
	}\
}

#define GETF() \
((!brk && !av[1]) || (av[1] && av[1][0] == '-')) ? (brk = 1, (void*)0x0) : \
(!brk  &&   op[1] != '\0')                       ? (brk = 1, (av[0] + 1)) : \
                                                   (brk = 1, --ac, *(++av))
#endif  /* ARGV_H__ */

