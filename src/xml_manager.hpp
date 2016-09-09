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
/// XmlManager class.
/// @author Jonan

#ifndef XML_MANAGER_HPP
#define XML_MANAGER_HPP

#include <list>

#include "util.hpp"

// @{
/// All XML files.
const char HEROES_XML_FILE[]        = "config/config_heroes.xml";
const char ITEMS_XML_FILE[]         = "config/config_items.xml";
const char SMOOTH_IMAGES_XML_FILE[] = "config/config_smooth_images.xml";
const char SMOOTH_RULES_XML_FILE[]  = "config/config_smooth_rules.xml";
const char TERRAIN_XML_FILE[]       = "config/config_terrain.xml";
const char UNITS_XML_FILE[]         = "config/config_units.xml";
// @}

class TiXmlDocument;
class TiXmlElement;
class TiXmlNode;

/// Manages all XML files.
class XmlManager {
  public:
    static XmlManager* getInstance(void); // Singleton pattern constructor
    ~XmlManager(void); // Destructor

    /// Loads a given file.
    /// @param[in] file_name File to load.
    /// @param[in] ids True if the file needs IDs set.
    void loadFile(const char *file_name, bool ids);

    // @{
    /// Get functions.
    TiXmlElement* getRootElement (const char *file_name);
    const char*   getName        (const char *id, const char *file);
    char*         getLastId      (const char *file_name);
    // @}

  private:
    XmlManager(void) {} // Constructor

    // Returns a pointer to a file.
    TiXmlDocument* getFile(const char *file_name);

    // Sets IDs to the elements of a file.
    void setIds(TiXmlDocument *file);

    std::list<TiXmlDocument*> xml_files;

    DISALLOW_COPY_AND_ASSIGN(XmlManager);
};

#endif // XML_MANAGER_HPP
