/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_errors2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdussert <jdussert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 17:08:31 by jdussert          #+#    #+#             */
/*   Updated: 2020/10/26 14:23:17 by jdussert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_check_errors_line(char *line, t_all *all)
{
	if (!check_double(line, ";|"))
		return (ft_syntax_error("double", all));
	else if (!ft_error_ps(line))
		return (ft_syntax_error("ps", all));
	else if (!ft_quote_error(line))
		return (ft_syntax_error("quote", all));
	else if (!check_chevrons(line))
		return (ft_syntax_error("chevrons", all));
	return (1);
}
