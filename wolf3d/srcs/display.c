/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:52:38 by maboye            #+#    #+#             */
/*   Updated: 2020/01/07 18:12:52 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		remove_objects(t_wolf *data)
{
	t_object	*tmp;
	t_object	*head;

	head = data->object;
	while (data->object && data->object->dead == 1)
	{
		data->pfdata.list[data->object->i].bobstacle = 0;
		tmp = data->object->next;
		ft_memdel((void **)&data->object);
		data->object = tmp;
		head = data->object;
	}
	while (data->object)
	{
		tmp = data->object;
		data->object = data->object->next;
		while (data->object && data->object->dead == 1)
		{
			data->pfdata.list[data->object->i].bobstacle = 0;
			tmp->next = data->object->next;
			ft_memdel((void **)&data->object);
			data->object = tmp->next;
		}
	}
	data->object = head;
}

static void		textures(t_wolf *data)
{
	int				i;
	unsigned int	*pixels;
	SDL_Rect		rect;

	rect.h = W_HEIGHT / 2;
	rect.w = W_WIDTH;
	rect.x = 0;
	rect.y = W_HEIGHT / 2;
	SDL_RenderCopy(data->renderer, data->bgf, NULL, &rect);
	rect.h = W_HEIGHT;
	rect.y = 0;
	SDL_LockSurface(data->screen);
	data->window = SDL_CreateTextureFromSurface(data->renderer, data->screen);
	SDL_RenderCopy(data->renderer, data->window, NULL, &rect);
	pixels = (unsigned int *)data->screen->pixels;
	i = -1;
	while (++i < W_WIDTH * W_HEIGHT)
		pixels[i] = 0x000000;
	SDL_UnlockSurface(data->screen);
}

void			get_fps(t_wolf *d)
{
	d->oldtime = d->time;
	d->time = SDL_GetTicks();
	d->frametime = (d->time - d->oldtime) / 1000.0;
	d->fps = 1.0 / d->frametime;
	d->mv_speed = d->frametime * 5.0;
	d->rot_speed = d->frametime * 3.0;
}

void			display(t_wolf *data)
{
	raycasting(data);
	monsters(data);
	objects(data, data->monster);
	objects(data, data->object);
	remove_objects(data);
	weapons(data);
	textures(data);
	cursor(data);
	health(data);
	if (data->key[KM])
		minimap(data);
	SDL_RenderPresent(data->renderer);
	SDL_DestroyTexture(data->window);
	get_fps(data);
}
