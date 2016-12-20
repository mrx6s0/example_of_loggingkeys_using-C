//* almost a keylogger */
//*the basic struct */

#include <stdio.h>  // input/output standard
#include <termios.h> // to terminal stuffs
#include <unistd.h>  // *nix only
#include <malloc.h>
#include <sys/tipes.h>
#include <sys/stat.h>
#include <string.h>

#define EXIT_SUCCESS

int main(void)


{

    ///* struct of fuction getchar(); */

    struct termios term, term_orig;
    tcgetattr(STDIN_FILENO, &term);
    term_orig = term;
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);



    ///* code here... implement your own //
    // this is just a example of the use of the function. 

    char *key; 

    log:

    key = getpass(""); // get keys
    fprintf("\nkeys pressed: %s\n",key);


    if (key == '^')
    
    {

        ferror("Error...");
        return -1;

    }

    else 

    {


    printf("\n\n");

    goto log; // loop.

    return 0;

    }

    ///* Remember to set back, or your commands won't echo! */

    tcsetattr(STDIN_FILENO, TCSANOW, &term_orig);

    return EXIT_SUCCESS;

    }
