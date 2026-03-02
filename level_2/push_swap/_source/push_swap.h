#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;

}					t_node;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;

}					t_stack;

typedef struct s_ps
{
	t_stack			a;
	t_stack			b;
}					t_ps;

int					build_program(t_ps *wrapper, int *nums, int count);
void				clean_program(t_ps *wrapper);
int					sort(t_ps *wrapper);
int					parser(int **nums, int *count, int argc, char **argv);
int					*num_converter(const char *nptr, int *out_count);
#endif
