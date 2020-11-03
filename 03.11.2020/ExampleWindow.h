/*
 * ExampleWindow.h
 *
 *  Created on: 3 нояб. 2020 г.
 *      Author: Лев
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"

class ExampleWindow: public Window
{
protected:
	std::shared_ptr<SDL_Texture> _plane;
	std::shared_ptr<SDL_Texture> _sun;
	std::shared_ptr<SDL_Texture> _cloud;
	std::shared_ptr<SDL_Texture> _plant;
	std::shared_ptr<SDL_Texture> _mount;
	std::shared_ptr<SDL_Texture> _tree;
	int _plane_x, _plane_y,
	_plane_x1,_plane_y1,
	_plane_x2, _plane_y2,
	_cloud_x,_cloud_x1,_cloud_x2,
	_tree_x,_tree_x1,_plant_x,
	_mount_x;

public:
	ExampleWindow(
			int width = DEFAULT_WIDTH,
			int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void render() override;
	virtual void do_logic() override;
	virtual void handle_keys(const Uint8 *keys) override;
};


#endif /* EXAMPLEWINDOW_H_ */
