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
/// 
/// @author Jonan

#ifndef UNIT_ANIMATION_HPP
#define UNIT_ANIMATION_HPP

#include "util.hpp"

// Types of animations
enum {ATTACK, DIE, MOVE};

class Cell;
class Unit;

/// 
class UnitAnimation {
  public:
    UnitAnimation(void) : animation_in_progress(false) {} // Constructor
    ~UnitAnimation(void) {} // Destructor

    // @{
    /// Get functions.
    int   getType          (void) {return type;          }
    Unit* getUnit          (void) {return unit;          }
    Cell* getFinalPosition (void) {return final_position;}
    // @}

    /// Returns true if there's an animation in progress.
    /// @return True if there's an animation in progress.
    bool animationInProgress(void) {return animation_in_progress;}

    /// Starts a new animation.
    /// @param[in] type Type of animation.
    /// @param[in] unit Unit to animate.
    /// @param[in] cell Some types of animations need to specify a cell.
    void startNewAnimation(int type, Unit &unit, Cell *cell = NULL);

    /// Performs all needed actions in a frame of the animation.
    /// @return True if this was the last frame of the animation.
    bool frame(void);

  private:
    static const int FRAMES_PER_MOVE = 4;

    // Starts a given animation.
    void startAnimation(int type);

    Unit *unit;
    Cell *initial_position, *final_position;
    bool cells_connected;

    int type, state;
    int frames;

    bool animation_in_progress;

    // To move the unit
    int *path;
    int movements, actual_move;

    DISALLOW_COPY_AND_ASSIGN(UnitAnimation);
};

#endif // UNIT_ANIMATION_HPP
