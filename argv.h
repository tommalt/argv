/*
 * argv.h - an argument parser that sucks less.
 * derived from https://st.suckless.org/
 * by Tom Maltese
 */ 

#ifndef ARGV_H__
#define ARGV_H__

extern char *argv0;

#define ARGBEGIN \
for (argv0 = *argv, argv++, argc--;\
     (argc > 0) && argv[0] && argv[0][0] ; ) { \
		char c;\
		char *valp_;\
		if (argv[0][1] == '-' && argv[0][2] == '\0') {\
		        argv++;\
		        argc--;\
		        break;\
		}\
		for (valp_= *argv;\
		     valp_ && *valp_; ) {\
			c = valp_[1];\
			if (valp_[2] == '\0'){\
				--argc;\
				valp_ = *++argv;\
			} else {\
				valp_ += 2;\
			}\
			switch(c)
#define ARGEND \
	}\
}
#define ARGV(val) do {\
	if (valp_ == (char*)0){\
		val = (char*)0;\
		break;\
	} else if (valp_[0] == '-') {\
		val = (char*)0;\
	} else {\
		val = valp_;\
	}\
	--argc, ++argv;\
	if (*argv != NULL && **argv == '-')\
		valp_ = NULL;\
	else\
		valp_ = *argv;\
} while (0);


#endif  /* ARGV_H__ */
