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
/// The Ttf class (can only be used by graphics).
/// @author Jonan

#ifndef TTF_HPP
#define TTF_HPP

#include "graphics.hpp"

typedef struct _TTF_Font TTF_Font;

/// @todo Add options to change color, size, etc.

/// Represents text on the screen.
class video_engine::Graphics::Ttf {
  public:
    Ttf(void); // Constructor
    ~Ttf(void); // Destrucor

    /// Writes a text into a surface.
    /// @param[in] text A string with the text to write.
    /// @param[in] surface The surface where to draw the text.
    /// @param[in] x The x coordinate of the top left corner of the text.
    /// @param[in] y The y coordinate of the top left corner of the text.
    void write(const char *text, SDL_Surface *surface, const int x, const int y);
    /// Writes a text centered in a surface.
    /// @param[in] text A string with the text to write.
    /// @param[in] surface The surface where to draw the text.
    /// @param[in] left_x The x coordinate of the left margen of the text.
    /// @param[in] right_x The x coordinate of the right margen of the text.
    /// @param[in] top_y The y coordinate of the top margen of the text.
    /// @param[in] bottom_y The y coordinate of the bottom margen of the text.
    void writeCentered(const char *text, SDL_Surface *surface,
                       const int left_x, const int right_x,
                       const int top_y, const int bottom_y);

  private:
    TTF_Font *font;
    SDL_Surface *text_surface;
    SDL_Rect position;
    SDL_Color color;

    DISALLOW_COPY_AND_ASSIGN(Ttf);
};

#endif // TTF_HPP
