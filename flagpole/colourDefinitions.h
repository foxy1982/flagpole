#define colorSaturation 10

RgbColor red(colorSaturation, 0, 0);
RgbColor orange(colorSaturation, colorSaturation/2, 0);
RgbColor yellow(colorSaturation, colorSaturation, 0);
RgbColor green(0, colorSaturation, 0);
RgbColor blue(0, 0, colorSaturation);
RgbColor purple(colorSaturation, 0, colorSaturation);
RgbColor white(colorSaturation);
RgbColor black(0);

HslColor hslRed(red);
HslColor hslOrange(orange);
HslColor hslYellow(yellow);
HslColor hslGreen(green);
HslColor hslBlue(blue);
HslColor hslPurple(purple);
HslColor hslWhite(white);
HslColor hslBlack(black);
