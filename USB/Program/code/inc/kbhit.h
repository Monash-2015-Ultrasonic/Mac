#include <termios.h>

#ifndef _KBHIT_H_
#define _KBHIT_H_

class keyboard
{
public:
    keyboard();
    ~keyboard();
    int     kbhit();
    int     getch();
    
private:
    struct  termios initial_settings, new_settings;
    int     peek_character;
};

#endif
