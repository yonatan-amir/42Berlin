

#ifndef CAPTURE_OUTPUT_H
# define CAPTURE_OUTPUT_H

# include "test_runner.h"

int	capture_output(int (*fn)(const char *, ...), const char *fmt, char *buffer,
		size_t buffer_size);
int	capture_output_char(int (*fn)(const char *, ...), const char *fmt,
		char *buffer, size_t buffer_size, int arg);
int	capture_output_str(int (*fn)(const char *, ...), const char *fmt,
		char *buffer, size_t buffer_size, const char *arg);
int	capture_output_ptr(int (*fn)(const char *, ...), const char *fmt,
		char *buffer, size_t buffer_size, void *arg);
int	capture_output_u(int (*fn)(const char *, ...), const char *fmt,
		char *buffer, size_t buffer_size, unsigned int arg);
int	capture_output_x(int (*fn)(const char *, ...), const char *fmt,
		char *buffer, size_t buffer_size, unsigned int arg);

#endif
