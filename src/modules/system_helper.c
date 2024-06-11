#include <conio.h>

void setUpScreen( void )
{
    bordercolor( BLACK );
    textcolor( GREEN );
    textbackground( BLACK );
    clrscr();
}

void resetDefaultScreen( void )
{
    bordercolor( WHITE );
    textcolor( BLACK );
    textbackground( WHITE );
    clrscr();
}