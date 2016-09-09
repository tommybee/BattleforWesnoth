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
/// The GameLoop class.
/// @author Jonan

#ifndef GAME_LOOP_HPP
#define GAME_LOOP_HPP

#include "util.hpp"

class Timer;

/// Creates a normal game loop.
class GameLoop {
  protected:
    GameLoop(void); // Constructor
    virtual ~GameLoop(void); // Destructor

    // Starts the loop
    void loop(void);

  private:
    bool done;
    Timer *fps;

    // Funtion that will be called inside the loop
    virtual bool frame(void) = 0;

    DISALLOW_COPY_AND_ASSIGN(GameLoop);
};

#endif // GAME_LOOP_HPP
