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
/// The Battle class and functions to create battles.
/// @author Jonan

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "map.hpp"

class Hero;

/// Controls all the aspects of a battle.
class Battle : public Map {
  public:
    /// @param[in] player The player's hero.
    /// @param[in] enemies Array with all the enemies.
    /// @param[in] num_enemies Number of enemies in the array.
    /// @param[in] terrain Type of terrain.
    Battle(Hero &player, Unit **enemies, int num_enemies, const char *terrain); // Constructor
    /// @param[in] player The player's hero.
    /// @param[in] enemy The enemy's hero.
    /// @param[in] terrain Type of terrain.
    Battle(Hero &player, Hero &enemy, const char *terrain); // Constructor

    /// Starts the battle.
    virtual void start(void);

    /// Returns true if the battle was won.
    /// @return true if the battle was won, false if it wasn't.
    bool win(void) {return creatures[PLAYER];}

  private:
    static const int MAX_TEAM_UNITS = 9;     // Not counting the hero.
    static const int MAX_BATTLE_UNITS = 20;
    static const int TURN = 10;              // Agility needed to get a turn

    static const int PLAYER =  0;
    static const int ENEMY  = 10;

    // Things to do no matter what constructor was called.
    void init(Hero &player_hero, const char *terrain);

    // Put a hero and his units in the map.
    void setHero(Hero &hero, const int facing_side);

    // Controls the units not controled by the player.
    void ai(void);

    // Makes the selected creature attack the unit in the given cell.
    virtual void attack(Cell &cell);

    // Function to execute when the mouse is over a cell.
    virtual void mouseOverCell(const int x, const int y);
    // Function to execute when the user left clicks on a cell.
    virtual void mouseLeftClick(const int x, const int y);

    // Starts the next turn.
    virtual void nextTurn(void);

    // Deletes a creature.
    void deleteCreature(Unit &creature);

    // This function is executed in the main loop. If
    // it returns true, the loop ends, else it continues.
    virtual bool frame(void);

    Unit *creatures[MAX_BATTLE_UNITS];
    int turn_progress[MAX_BATTLE_UNITS];

    DISALLOW_COPY_AND_ASSIGN(Battle);
};

// @{
/// Functions to create and start battles (return true if won)
void createDefaultBattle(void);
bool createBattle(Hero &player, const char *enemy_type, const char *terrain_type);
bool createBattle(Hero &player, Hero &enemy, const char *terrain_type);
// @}

#endif // BATTLE_HPP
