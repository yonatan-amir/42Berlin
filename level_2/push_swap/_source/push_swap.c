#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc <= 2)
		return (1);
	stack_struct(argc, argv); // I get then node stack
	// 1. check num of args with argc
	// 2. build the stacks
	// what is made of
	// does it need new page
	// do you many nodes
	// 3. assign each to a linked list
	// 4. sort
	// if error
	// return 0
	return (0);
}

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.

// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1.

// The last element becomes the first one.

// rrr : rra and rrb at the same time.