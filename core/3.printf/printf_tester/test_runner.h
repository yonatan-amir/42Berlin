/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathanamir <jonathanamir@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 12:26:43 by yamir             #+#    #+#             */
/*   Updated: 2026/01/12 12:26:13 by jonathanami      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#endif
