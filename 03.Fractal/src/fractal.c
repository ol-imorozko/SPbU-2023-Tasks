#include <assert.h>

#include "include/image.h"
#include "include/fractal.h"

void
draw_sierpinski_carpet(image_p picture, int x, int y, int size)
{
  if( size < 1 ) {
    return;
  }

  // Calculate the size of the smaller squares
  int newSize = size / 3;

  // Iterate through the 3x3 grid
  for( int i = 0; i < 3; i++ ) {
    for( int j = 0; j < 3; j++ ) {
      // Skip the middle square
      if( i == 1 && j == 1 ) {
        for( int k = y + newSize; k < y + 2 * newSize; k++ ) {
          for( int l = x + newSize; l < x + 2 * newSize; l++ ) {
            set_pixel(picture, l, k,
                      0); // Setting the middle square pixels to black (or 0)
          }
        }
      }
      else {
        draw_sierpinski_carpet(picture, x + i * newSize, y + j * newSize,
                               newSize);
      }
    }
  }
}

void
fractal(image_p picture, fractal_type type)
{
  switch( type ) {
  case Sierpinski_Carpet: {

    int size = picture->width;
    draw_sierpinski_carpet(picture, 0, 0, size);
  }
  }
}
