/*
 * argv.h - an argument parser that sucks even less.
 * derived from https://st.suckless.org/
 * by Tom Maltese
 */ 

#ifndef ARGV_H__
#define ARGV_H__

extern char *argv0;

#define ARGBEGIN \
for (argv0 = *argv, argv++, argc--;\
     argv[0] && argv[0][0] == '-' && argv[0][1] ; ) {\
		char *valp_;\
		int brk_ = 0;\
		if (argv[0][1] == '-' && argv[0][2] == '\0'){\
		        argv++;\
		        argc--;\
		        break;\
		}\
		for (valp_= (*argv) + 1; *valp_ && !brk_; valp_++){\
			switch (*valp_)
#define ARGEND \
		if (argc > 0) {\
			--argc, ++argv;\
		}\
	}\
}
#define COZY_ARG() (argv[0][0] == '-' && argv[0][2] != '\0') ? \
                     (1) :\
		     (0)
#define HAS_ARGS() ((COZY_ARG()) || (argv[1] && argv[1][0] != '-') ? \
                     (1) :\
		     (--argc, ++argv, 0))
#define NEXT_ARG() (brk_ ? (--argc, *++argv) :\
                     (COZY_ARG()) ? (brk_ = 1, *argv + 2) : (--argc, *++argv))

#endif  /* ARGV_H__ */
