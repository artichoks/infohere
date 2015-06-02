#ifndef ERROR_CHECK_H_
#define ERROR_CHECK_H_


#include <cerrno>
#include <cstdio>


#define ERRNO_CLEAR					errno = 0
#define ERRNO_EXIT_IF_ERROR(msg)			\
	if (errno != 0)							\
	{										\
		perror(msg);						\
		return;								\
	}


#endif /* ERROR_CHECK_H_ */
