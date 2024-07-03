void setUpScreen( void );
void resetDefaultScreen( void );
#ifdef __CPM__
void cls();
void gotoyx( int row, int col ); 
void cursorOff();
#endif

#ifdef __CPM__
#define SCREEN_WIDTH 79
#else
#define SCREEN_WIDTH 41
#endif

#define SCREEN_HEIGHT 23