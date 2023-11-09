/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafriem <cafriem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:42:29 by cafriem           #+#    #+#             */
/*   Updated: 2023/11/09 18:02:36 by cafriem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	draw(void)
{
	
}

int	main(int argc, char *argv[])
{
	t_data	img;

	if (argc < 2)
	{
		write(2, "Failed", 6);
		exit(1);
	}
	img.mlx = mlx_init();
	init(&img);
	img.mlx_win = mlx_new_window(img.mlx, 1080, 720, argv[1]);
	img.img = mlx_new_image(img.mlx, 1080, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	openmap(argv[2]);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	legends1(&img);
	mlx_hook(img.mlx_win, 2, 1L << 2, key_press1, &img);
	mlx_loop(img.mlx);
}