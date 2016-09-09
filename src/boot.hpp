/*
This file is part of Heroes of Wesnoth.
Copyright (C) 2007, 2008, 2009 Jon Ander Peñalba <jonan88@gmail.com>

Heroes of Wesnoth is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License version 3 as
published by the Free Software Foundation.

Heroes of Wesnoth is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Heroes of Wesnoth. If not, see <http://www.gnu.org/licenses/>
*/

/// @file
/// Functions to boot and quit the game.
/// @author Jonan

#ifndef BOOT_HPP
#define BOOT_HPP

/// Starts the engine and loads the main images.
/// @param[in] fullscreen Indicates if it's supposed to run on fullscreen.
/// @param[in] width Screen's width.
/// @param[in] height Screen's height.
void boot(const bool fullscreen, const int width, const int height);

/// Exits the game.
void quit(void);

#endif // BOOT_HPP
