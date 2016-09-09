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
/// The Image and ImageList classes (can only be used by graphics).
/// @author Jonan

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <deque>

#include "graphics.hpp"

/// A class to control images.
class video_engine::Graphics::Image {
  public:
    /// @param[in] image_name The image's name, without the "img/" or the ".png".
    /// @param[in] alpha Alpha value of the image (0 transparent - 255 opaque).
    /// @param[in] mirror Indicates if the image is a mirror of the original.
    /// @param[in] angle Number of degrees the image is rotated.
    Image(const char *image_name, const int alpha,
          const int mirror, const int angle); // Constructor
    ~Image(void); // Destructor

    // @{
    /// Get Functions.
    char*        getName       (void) {return name;  }
    int          getAlphaValue (void) {return alpha; }
    int          getMirror     (void) {return mirror;} // NONE, X or Y
    int          getAngle      (void) {return angle; }
    SDL_Surface* getSurface    (void) {return img;   }
    // @}

    /// Indicates if the given attributes correspond to this image.
    /// @param[in] image_name The image's name, without the "img/" or the ".png".
    /// @param[in] alpha Alpha value of the image (0 transparent - 255 opaque).
    /// @param[in] mirror Indicates if the image is a mirror of the original.
    /// @param[in] angle Number of degrees the image is rotated.
    /// @return true if the attributes correspond to this image, false if not.
    bool isImage(const char *image_name, const int alpha,
                   const int mirror, const int angle);

  private:
    // Loads an image. If there's an error exits.
    void loadImage(void);

    char *name; // The fisical name of the image.
    int alpha, mirror, angle; // Indicates if the image has been modified.
    SDL_Surface *img; // Image's surface

    DISALLOW_COPY_AND_ASSIGN(Image);
};

/// A list of Image classes.
class video_engine::Graphics::ImageList {
  public:
    ImageList(void) {}; // Constructor
    ~ImageList(void); // Destructor

    /// Adds the image to the list.
    /// Loads the image and places it at the beginning of the list.
    /// @param[in] image_name The image's name, without the "img/" or the ".png".
    /// @param[in] alpha Alpha value of the image (0 transparent - 255 opaque).
    /// @param[in] mirror Indicates if the image is a mirror of the original.
    /// @param[in] angle Number of degrees the image is rotated.
    void addImage(const char *image_name, const int alpha,
                  const int mirror, const int angle);

    /// Returns an image of the list.
    /// @param[in] image The surface of the image to get.
    /// @return The image with the given surface.
    Image* getImage(SDL_Surface *image) {return findImage(image);}
    /// Returns the surface of an image in the list.
    /// @param[in] image_name The image's name, without the "img/" or the ".png".
    /// @param[in] alpha Alpha value of the image (0 transparent - 255 opaque).
    /// @param[in] mirror Indicates if the image is a mirror of the original.
    /// @param[in] angle Number of degrees the image is rotated.
    /// @return Surface of the image in the list.
    SDL_Surface* getSurface(const char *image_name, const int alpha,
                            const int mirror, const int angle);

  private:
    // Looks for an image in the list.
    Image* findImage(const char *image_name, const int alpha,
                     const int mirror, const int angle);
    // Looks for an image in the list.
    Image* findImage(SDL_Surface *image);

    std::deque<Image*> images;

    DISALLOW_COPY_AND_ASSIGN(ImageList);
};

#endif // IMAGE_HPP
