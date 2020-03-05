/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:24:11 by wmisiedj       #+#    #+#                */
/*   Updated: 2020/03/05 14:34:57 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_ERRORS_H
# define FT_LEM_IN_ERRORS_H

#define ERR_PARAMS 1
#define ERR_ROOM_NAME 2
#define ERR_MEM 3
#define ERR_DOUBLE_COMMANDS 4
#define ERR_INVALID_ROOM_COUNT 5
#define	ERR_NO_PATHS 6
#define ERR_OTHER -1

int     ft_error(int i);

# endif