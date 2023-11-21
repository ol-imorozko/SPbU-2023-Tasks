#include <stdio.h>

#include "include/image.h"
#include "include/fractal.h"

int main()
{
    image_p img = create_image(300, 300);

    fill_white(img);

    fractal(img, Sierpinski_Carpet);

    save_pgm(img, "test.pgm");
    return 0;
}