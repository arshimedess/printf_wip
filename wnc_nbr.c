/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wnc_nbr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahossein <ahossein@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/27 15:29:52 by ahossein      #+#    #+#                 */
/*   Updated: 2026/10/27 15:30:31 by ahossein      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	wnc_nbr(int n, int fd)
{
	int		num;
	long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		write(fd, "-", 1);
		tmp = tmp * -1;
	}
	if (tmp >= 0 && tmp <= 9)
	{
		num = tmp + '0';
		write(fd, &num, 1);
	}
	else
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
}