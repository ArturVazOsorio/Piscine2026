#include <unistd.h>

/* Funções de Impressão */
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

/* Lógica de Contagem de Visibilidade */
int	count_visible(int *line)
{
	int	count;
	int	max_h;
	int	i;

	count = 0;
	max_h = 0;
	i = 0;
	while (i < 4)
	{
		if (line[i] > max_h)
		{
			count++;
			max_h = line[i];
		}
		i++;
	}
	return (count);
}

int	count_visible_rev(int *line)
{
	int	temp[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		temp[i] = line[3 - i];
		i++;
	}
	return (count_visible(temp));
}

/* Validações de Colunas e Linhas */
int	check_cols(int grid[4][4], int *clues)
{
	int	i;
	int	j;
	int	temp[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp[j] = grid[j][i];
			j++;
		}
		if (count_visible(temp) != clues[i])
			return (0);
		if (count_visible_rev(temp) != clues[i + 4])
			return (0);
		i++;
	}
	return (1);
}

int	check_rows(int grid[4][4], int *clues)
{
	int	i;
	if (check_cols(grid, clues) == 0)
		return (0);
	i = 0;
	while (i < 4)
	{
		if (count_visible(grid[i]) != clues[i + 8])
			return (0);
		if (count_visible_rev(grid[i]) != clues[i + 12])
			return (0);
		i++;
	}
	return (1);
}

/* Verificação de segurança (Quadrado Latino) */
int	is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

/* Backtracking Principal */
int	solve(int grid[4][4], int *clues, int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_rows(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

/* Parsing e Main */
int	main(int argc, char **argv)
{
	int	grid[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	int	clues[16];
	int	i;
	int	j;

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[1][i] && j < 16)
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
			clues[j++] = argv[1][i] - '0';
		i++;
	}
	if (j != 16 || !solve(grid, clues, 0))
		ft_putstr("Error\n");
	else
		print_grid(grid);
	return (0);
}

