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
/// General utilities.
/// @author Jonan

#ifndef UTIL_HPP
#define UTIL_HPP

#include <deque>
#include <string>

class SDL_Surface;

/// A macro to disallow the copy constructor and operator= functions.
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

/// Struct to store coordinates.
struct Coordinates {
  int x;
  int y;
};

/// Stores information of special terrains
struct SpecialImage {
  std::deque<SDL_Surface*> image_list;
  Coordinates position;
  unsigned int frame;
  int num_frames_per_sprite;
};

// @{
/// Use this functions when operating width IDs (unit types, terrain types, etc.)
void increaseId(std::string &id);
void decreaseId(std::string &id);
// @}

#endif // UTIL_HPP
