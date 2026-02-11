
#ifndef TEST_RUNNER_H
# define TEST_RUNNER_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define RESET "\033[0m"

typedef struct s_test_case
{
	const char	*name;
	int			(*run)(void);
}				t_test_case;

int				test_literal(void);
int				test_percent(void);
int				test_char(void);
int				test_string(void);
int				test_int(void);
int				test_ptr(void);
int				test_u(void);
int				test_upperx(void);
int				test_x(void);
int				test_bonus(void);

#endif
