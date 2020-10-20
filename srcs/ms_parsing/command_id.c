/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-banv <ede-banv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:33:36 by ede-banv          #+#    #+#             */
/*   Updated: 2020/10/20 11:38:50 by ede-banv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*command_id(char **comm, t_exit *exit)//puisque je fais read
{
    //identifier la commande selon le 1er token
    if (!ft_strncmp(comm[0], "echo", 4))
        ;//fct vers echo
    else if (!ft_strncmp(comm[0], "cd", 2))
        ;//fct vrs cd
    else if (!ft_strncmp(comm[0], "pwd", 3))
        ;//fct vrs pwd
    else if (!ft_strncmp(comm[0], "export", 6))
        ;//fct vrs export
    else if (!ft_strncmp(comm[0], "unset", 5))
        ;//fct vrs unset
    else if (!ft_strncmp(comm[0], "env", 3))
        ;//fct vrs env
    else if (!ft_strncmp(comm[0], "exit", 4))
        exit->e = 1;
    else if (!ft_strncmp(comm[0], "./", 2))
        ;//fct vrs execution de binaire
    //chevrons aussi
    //cntrl stuff?
    //si on free comm ici est-ce que ca marcher avec pipe?
    return("done");
}

char	*pipes_id(t_cmd **cmd, t_exit *exit)
{
    int i;
    int status;
    //cette fonction va se servir de command id donc cest dans comand id que le debut de l'excecution des commandes va se faire
    //si ca se sert de comm_id

    i = 0;
    //boucle
    //  pipe
    //  dup2
    //  fork (pid dans pid de cmd)
    //  command_id
    //boucle
    //  wait_pid qui attend le pid du fils de chaque fork
    while (cmd[i]->cmd)
    {
        pipe(&cmd[i]->pipe);
        cmd[i]->pid = fork();
        if (cmd[i]->pid == 0)
        {
            if (i != 0)
                dup2(cmd[i - 1]->pipe[0], 0);
            dup2(cmd[i]->pipe[1], 1);
            command_id(cmd[i]->cmd, exit);
        }
        else if (cmd[i]->pid == -1)
            ;//erreur de fork
        i++;
    }
    i = 0;
    while (cmd[i]->cmd)
    {
        waitpid(cmd[i]->pid, &status, 0);//a voir la redaction
        close(cmd[i]->pipe[0]);
        close(cmd[i]->pipe[1]);
        //voir comment gerer les bails de pipes
        i++;
    }
    return ("done");
}