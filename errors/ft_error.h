/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:24:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/04/20 15:18:23 by wmisiedjan    ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# define ERR_PARAMS -1
# define ERR_ROOM_NAME -2
# define ERR_MEM -3
# define ERR_DOUBLE_COMMANDS -4
# define ERR_INVALID_ROOM_COUNT -5
# define ERR_NO_PATHS -6
# define ERR_FILE -7
# define ERR_NO_ANTS -8
# define ERR_NO_START_END -9
# define ERR_CONN_INVALID -10
# define ERR_ROOM_CORDS -11
# define ERR_START_END -12
# define ERR_PARSE_ROOM -13
# define ERR_OTHER -99

int ft_error(int i);

#endif
