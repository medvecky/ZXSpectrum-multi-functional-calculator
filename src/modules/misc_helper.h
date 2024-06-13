#define MAX_INPUT_LENGTH 80

void header( void );
void getUserInput( char * argumentString );
void handleArgumentString( char * argumentString );
int handleToken( char * token );
int handleNumber( char * token );
int handleOperator( char * token );