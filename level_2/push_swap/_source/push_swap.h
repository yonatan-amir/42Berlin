/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamir <yamir@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:10:05 by yamir             #+#    #+#             */
/*   Updated: 2026/03/30 13:10:05 by yamir            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_move
{
	int				pos_b;
	int				pos_a;
	int				dir_b;
	int				dir_a;
}					t_move;
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
int					init_program(t_ps *wrapper);
void				clean_program(t_ps *wrapper);
int					sort(t_ps *wrapper);
int					parser(int **nums, int *count, int argc, char **argv);
int					*num_converter(const char *nptr, int *out_count);
int					insert_chunks(t_ps *wrapper);
int					get_target_pos(t_stack stack_a, int index);
int					get_pos(t_stack stack, t_node *target);
void				set_dirs(t_move *curr, t_ps *wrapper);
int					get_move_cost(t_move move, t_ps *wrapper);
void				sa(t_ps *wrapper);
void				sb(t_ps *wrapper);
void				ss(t_ps *wrapper);
void				pa(t_ps *wrapper);
void				pb(t_ps *wrapper);
void				ra(t_ps *wrapper);
void				rb(t_ps *wrapper);
void				rr(t_ps *wrapper);
void				rra(t_ps *wrapper);
void				rrb(t_ps *wrapper);
void				rrr(t_ps *wrapper);
int					ps_isdigit(int c);
void				ps_putstr_fd(const char *s, int fd);
char				**ps_split(const char *s, char c);
#endif
