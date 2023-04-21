#ifndef CONFIG_H
#define CONFIG_H

#define HEIGHT 20
#define WIDTH 20
#define clear() printf("\e[1;1H\e[2J")
#define DEAD "\x1b[48;5;248m  \x1b[0m"
#define ALIVE "\x1b[48;5;154m  \x1b[0m"

#endif // CONFIG_H