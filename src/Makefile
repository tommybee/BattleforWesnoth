# This file is part of Heroes of Wesnoth.
# Copyright (C) 2007, 2008, 2009 Jon Ander Peñalba <jonan88@gmail.com>
#
# Heroes of Wesnoth is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.
#
# Heroes of Wesnoth is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Heroes of Wesnoth. If not, see <http://www.gnu.org/licenses/>

# Global variables
OBJECTS = battle.o \
          boot.o \
          cell.o \
          editor.o \
          events.o \
          game_loop.o \
          graphics.o \
          hero.o \
          image.o \
          main.o \
          map.o \
          menu.o \
          menu_main.o \
          mission.o \
          tinyxml_tinystr.o \
          tinyxml_tinyxml.o \
          tinyxml_tinyxmlerror.o \
          tinyxml_tinyxmlparser.o \
          ttf.o \
          unit.o \
          unit_animation.o \
          util.o \
          world.o \
          xml_manager.o
#SDL_LIBS = -lstdc++ -lSDL -L/mingw/lib -lSDL -lSDL_ttf -lSDL_image -lSDL_gfx
#SDL_LIBS = `sdl-config --libs` -L/mingw/lib -lSDL_gfx -lSDL_image -lSDL_mixer  -L/mingw/lib -lvorbis -lvorbisfile -lmingw32 -lSDLmain -lSDL -mwindows 
#SDL_LIBS = -static-libgcc -static-libstdc++ $(shell sdl-config --libs) -lSDL_ttf -lSDL_image -lSDL_gfx
#SDL_LIBS = -static -static-libstdc++ -static-libgcc $(shell sdl-config --libs) -lSDL_ttf -lSDL_image -lSDL_gfx
SDL_LIBS = -static -L/mingw32/lib -lmingw32 -lSDLmain -lSDL -lSDL_ttf -lfreetype -lSDL_image -lSDL_gfx -lSDL_mixer  \
			-lbz2 -lharfbuzz -lglib-2.0 -lintl -liconv -ltiff -ljpeg -llzma -lpng16 -lstdc++ -lwebp -lwinpthread -lz -larchive -lwinmm -lgdi32 -ldxguid \
			-lasprintf -lcharset -lcrypto -lcurl -lexpat -lffi -lFLAC++ -lFLAC -lfontconfig -lformw -lfreeglut_static -lgdbm -lgettextlib -lgettextpo -lgif \
			-lgio-2.0 -lglew32 -lglew32mx -lgmodule-2.0 -lgmp -lgmpxx -lgnurx -lgnutls -lgnutlsxx -lgobject-2.0 -lgthread-2.0 -lhistory -lhogweed -lidn -lisl -ljansson  \
			-ljsoncpp -llua  -llzo2  -lmenuw -lmetalink -lminizip -lmpc -lmpfr -lncurses++w -lncursesw -lnettle -lnghttp2 -logg -lopenal -lpanelw -lphysfs -lpixman-1 \
			-lreadline -lregex -lrtmp -lssh2 -lssl -lsystre -ltasn1 -ltclstub86 -ltermcap -ltheora -ltheoradec -ltheoraenc \
			-ltkstub86 -ltre -lturbojpeg -lvorbis -lvorbisenc -lvorbisfile -lwebpdecoder -lwebpdemux -lwebpmux -lole32 -lws2_32 -mwindows 

CFLAGS = -c -g -Wall
#CFLAGS = -c -g -Wall $(shell sdl-config --cflags)
CC = g++
EXE = heroes

# Headers dependencies
BATTLE = battle.hpp \
         $(MAP)

BOOT = boot.hpp

CELL = cell.hpp \
       $(UTIL)

EDITOR = editor.hpp \
         $(MAP)

EVENTS = events.hpp \
         $(UTIL)

GAME_LOOP = game_loop.hpp \
            $(UTIL)

GRAPHICS = graphics.hpp \
           $(UTIL)

HERO = hero.hpp \
       $(UNIT)

IMAGE = image.hpp \
        $(GRAPHICS)

MAP = map.hpp \
      $(GAME_LOOP) \
      $(UTIL)

MENU = menu.hpp \
       $(GAME_LOOP)

MENU_MAIN = menu_main.hpp

MISSION = mission.hpp

TIMER = timer.hpp \
        $(UTIL)

TTF = ttf.hpp \
      $(GRAPHICS)

UNIT = unit.hpp \
       $(GRAPHICS) \
       $(UTIL)

UNIT_ANIMATION = unit_animation.hpp \
                 $(UTIL)

UTIL = util.hpp

WORLD = world.hpp \
        $(MAP)

XML_MANAGER = xml_manager.hpp \
              $(UTIL)

# Build dependencies
$(EXE) : $(OBJECTS)
	$(CC) -g -Wall -o heroes $(OBJECTS) $(SDL_LIBS) 

battle.o : battle.cpp $(BATTLE) \
           $(CELL) \
           $(EVENTS) \
           $(GRAPHICS) \
           $(HERO) \
           $(UNIT_ANIMATION)
	$(CC) $(CFLAGS) battle.cpp

boot.o : boot.cpp $(BOOT) \
         $(EVENTS) \
         $(GRAPHICS) \
         $(XML_MANAGER)
	$(CC) $(CFLAGS) boot.cpp

cell.o : cell.cpp $(CELL) \
         $(GRAPHICS) \
         $(UNIT) \
         $(UTIL) \
         $(XML_MANAGER)
	$(CC) $(CFLAGS) cell.cpp

editor.o : editor.cpp $(EDITOR) \
           $(CELL) \
           $(EVENTS) \
           $(GRAPHICS) \
           $(UNIT) \
           $(UTIL)
	$(CC) $(CFLAGS) editor.cpp

events.o : events.cpp $(EVENTS) \
           $(GRAPHICS)
	$(CC) $(CFLAGS) events.cpp

game_loop.o : game_loop.cpp $(GAME_LOOP) \
              $(EVENTS) \
              $(GRAPHICS) \
              $(TIMER)
	$(CC) $(CFLAGS) game_loop.cpp

graphics.o : graphics.cpp $(GRAPHICS) \
             $(EVENTS) \
             $(IMAGE) \
             $(TIMER) \
             $(TTF)
	$(CC) $(CFLAGS) graphics.cpp

hero.o : hero.cpp $(HERO) \
         $(XML_MANAGER)
	$(CC) $(CFLAGS) hero.cpp

image.o : image.cpp $(IMAGE)
	$(CC) $(CFLAGS) image.cpp

main.o : main.cpp \
         $(BOOT) \
         $(MENU_MAIN)
	$(CC) $(CFLAGS) main.cpp

map.o : map.cpp $(MAP) \
        $(CELL) \
        $(EVENTS) \
        $(GRAPHICS) \
        $(UNIT) \
        $(UNIT_ANIMATION) \
        $(XML_MANAGER)
	$(CC) $(CFLAGS) map.cpp

menu.o : menu.cpp $(MENU) \
         $(EVENTS) \
         $(GRAPHICS)
	$(CC) $(CFLAGS) menu.cpp

menu_main.o : menu_main.cpp $(MENU_MAIN) \
              $(BATTLE) \
              $(BOOT) \
              $(EDITOR) \
              $(EVENTS) \
              $(GRAPHICS) \
              $(MENU) \
              $(MISSION)
	$(CC) $(CFLAGS) menu_main.cpp

mission.o : mission.cpp $(MISSION) \
            $(HERO) \
            $(WORLD)
	$(CC) $(CFLAGS) mission.cpp

tinyxml_tinystr.o :
	$(CC) $(CFLAGS) tinyxml/tinystr.cpp -o tinyxml_tinystr.o

tinyxml_tinyxml.o :
	$(CC) $(CFLAGS) tinyxml/tinyxml.cpp -o tinyxml_tinyxml.o

tinyxml_tinyxmlerror.o :
	$(CC) $(CFLAGS) tinyxml/tinyxmlerror.cpp -o tinyxml_tinyxmlerror.o

tinyxml_tinyxmlparser.o :
	$(CC) $(CFLAGS) tinyxml/tinyxmlparser.cpp -o tinyxml_tinyxmlparser.o

ttf.o : ttf.cpp $(TTF)
	$(CC) $(CFLAGS) ttf.cpp

unit.o : unit.cpp $(UNIT) \
         $(CELL) \
         $(UTIL) \
         $(XML_MANAGER)
	$(CC) $(CFLAGS) unit.cpp

unit_animation.o : unit_animation.cpp $(UNIT_ANIMATION) \
                   $(CELL) \
                   $(EVENTS) \
                   $(UNIT)
	$(CC) $(CFLAGS) unit_animation.cpp

util.o : util.cpp $(UTIL)
	$(CC) $(CFLAGS) util.cpp

world.o : world.cpp $(WORLD) \
          $(BATTLE) \
          $(CELL) \
          $(EVENTS) \
          $(HERO) \
          $(UNIT_ANIMATION)
	$(CC) $(CFLAGS) world.cpp

xml_manager.o : xml_manager.cpp $(XML_MANAGER) \
                $(UTIL)
	$(CC) $(CFLAGS) xml_manager.cpp

# Make options
.PHONY : all clean

all: clean
	make

clean :
	rm -f *~ $(EXE) $(OBJECTS)

