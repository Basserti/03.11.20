/*
 * ExampleWindow.cc
 *
 *  Created on: 3 нояб. 2020 г.
 *      Author: Лев
 */
#include "ExampleWindow.h"

#include <stdexcept>
#include <SDL2/SDL_image.h>

ExampleWindow::ExampleWindow(int width, int height)
: Window(width, height),
  	_plane_x(1500), _plane_y(200),
	_plane_x1(500),_plane_y1(200),
	_plane_x2(800), _plane_y2(200),
	_cloud_x(100),_cloud_x1(700),_cloud_x2(1900),
	_tree_x(0),_tree_x1(1400),_plant_x(0),
	_mount_x(0)
{
	_plane = std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(_renderer.get(), "img/plane.png"),
			SDL_DestroyTexture);
	if (_plane == nullptr)
		throw std::runtime_error(
				std::string("Не удалось загрузить plane: ") +
				std::string(SDL_GetError()));

	_sun = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "img/sun.png"),
				SDL_DestroyTexture);
		if (_sun == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить sun: ") +
					std::string(SDL_GetError()));

	_cloud = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "img/cloud.png"),
				SDL_DestroyTexture);
		if (_cloud == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить cloud: ") +
					std::string(SDL_GetError()));

	_plant = std::shared_ptr<SDL_Texture>(
				IMG_LoadTexture(_renderer.get(), "img/plant.png"),
				SDL_DestroyTexture);
		if (_plant == nullptr)
			throw std::runtime_error(
					std::string("Не удалось загрузить plant: ") +
					std::string(SDL_GetError()));

	_mount = std::shared_ptr<SDL_Texture>(
					IMG_LoadTexture(_renderer.get(), "img/mount.png"),
					SDL_DestroyTexture);
			if (_mount == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить mount: ") +
						std::string(SDL_GetError()));

	_tree = std::shared_ptr<SDL_Texture>(
					IMG_LoadTexture(_renderer.get(), "img/tree.png"),
					SDL_DestroyTexture);
			if (_tree == nullptr)
				throw std::runtime_error(
						std::string("Не удалось загрузить tree: ") +
						std::string(SDL_GetError()));

}

void ExampleWindow::render()
{
	//background
	SDL_SetRenderDrawColor(_renderer.get(), 183, 255, 230, 255);
	SDL_RenderClear(_renderer.get());

	//1
	//sun
		SDL_Rect sun_rect { 1700, 0, 256, 256 };
		SDL_RenderCopy(_renderer.get(), _sun.get(), nullptr, &sun_rect);
	//cloud
		SDL_Rect cloud_rect { _cloud_x, 0, 400, 400 };
		SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect);
	//mount
		SDL_Rect mount_rect { _mount_x, 500, 1920*2, 256*2 };
		SDL_RenderCopy(_renderer.get(), _mount.get(), nullptr, &mount_rect);
	//plane
		SDL_Rect plane_rect { _plane_x, _plane_y, 128, 128 };
		SDL_RenderCopy(_renderer.get(), _plane.get(), nullptr, &plane_rect);

	//2
	//plane1
		SDL_Rect plane_rect1 { _plane_x1, _plane_y1, 170, 170 };
		SDL_RenderCopy(_renderer.get(), _plane.get(), nullptr, &plane_rect1);
	//cloud2
		SDL_Rect cloud_rect1 { _cloud_x1, 0, 500, 500 };
		SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect1);
	//tree
		SDL_Rect tree_rect { _tree_x, 800, 256, 256 };
		SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree_rect);

	//3
	//plant2
		SDL_Rect plant_rect { _plant_x, 880, 1920*2, 200 };
		SDL_RenderCopy(_renderer.get(), _plant.get(), nullptr, &plant_rect);
	//cloud2
		SDL_Rect cloud_rect2 { _cloud_x2, 500, 256, 200 };
		SDL_RenderCopy(_renderer.get(), _cloud.get(), nullptr, &cloud_rect2);
	//tree2
		SDL_Rect tree_rect1 { _tree_x1, 500, 256*2, 256*2 };
		SDL_RenderCopy(_renderer.get(), _tree.get(), nullptr, &tree_rect1);
	//plane2
		SDL_Rect plane_rect2 { _plane_x2, _plane_y2, 256, 256 };
		SDL_RenderCopy(_renderer.get(), _plane.get(), nullptr, &plane_rect2);



}

void ExampleWindow::do_logic()
{
	_plane_x += 1;
		if (_plane_x >= width())
			_plane_x = -128;
	_cloud_x -= 1;
		if (_cloud_x <= -width())
			_cloud_x = 1920;
	_mount_x -= 3;
	if (_mount_x <= -width()-640)
		_mount_x = 0;



	_plane_x1 += 2;
		if (_plane_x1 >= width())
			_plane_x1 = -128;
	_cloud_x1 -= 2;
		if (_cloud_x1 <= -width())
			_cloud_x1 = 1920;
	_tree_x -= 2;
		if (_tree_x <= -width())
			_tree_x = 1920;



	_plane_x2 += 3;
		if (_plane_x2 >= width())
			_plane_x2 = -256;
	_cloud_x2 -= 3;
		if (_cloud_x2 <= -width())
			_cloud_x2 = 1920;
	_tree_x1 -= 3;
		if (_tree_x1 <= -width())
			_tree_x1 = 1920;
	_plant_x -= 3;
		if (_plant_x <= -width())
			_plant_x = 0;



}

void ExampleWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_DOWN])
		_plane_y += 6;
	if (keys[SDL_SCANCODE_UP])
		_plane_y -= 6;
}




