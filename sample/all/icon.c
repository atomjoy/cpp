/*
GIMP RGBA C-Source image dump (icon.c)

sf::RenderWindow::setIcon(gimp_image.width, gimp_image.height, gimp_image.pixel_data);
*/

static const struct {
  unsigned int   width;
  unsigned int   height;
  unsigned int   bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */
  unsigned char  pixel_data[32 * 32 * 4 + 1];
} gimp_image = {
  32, 32, 4,
  "k\177h\377k\177h\377\377\377\377\0\377\377\377\0\377\377\377\0\204`\236\201"
};
