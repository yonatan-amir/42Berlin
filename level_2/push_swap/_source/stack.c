#include "libft.h"
#include "push_swap.h"

static t_stack	*stack_constructor(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = 1;
	if (!first_node(stack, &i, argc, argv))
	{
		free_stack(stack);
		return (NULL);
	}
	if (!stack_loop(stack, &i, argc, argv))
	{
		free_stack(stack);
		return (NULL);
	}
	return (stack);
}

static t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

static int	stack_loop(t_stack *stack, int *i, int argc, char **argv)
{
	t_node	*node;

	while (i < argc)
	{
		node = node_struct(atoi(argv[*i]), i);
		if (!node)
			return (0);
		stack->tail->next = node;
		stack->tail = node;
		stack->size += 1;
		i++;
	}
	return (1);
}

static int	free_stack(t_stack *stack)
{
	t_node	*curr_node;
	t_node	*next;

	if (!stack)
		return (0);
	curr_node = stack->head;
	while (curr_node)
	{
		next = curr_node->next;
		curr_node->next = NULL;
		free(curr_node);
		curr_node = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	free(stack);
	return (0);
}
