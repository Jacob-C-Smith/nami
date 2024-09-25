/** !
 * Nami interpreter
 * 
 * @file main.c
 * 
 * @author Jacob Smith
 */

// Standard library
#include <stdio.h>
#include <stdlib.h>

// nami
#include <nami/node.h>
#include <nami/environment.h>
#include <nami/statement.h>
#include <nami/lexer.h>

int main ( int argc, const char *argv[] )
{
    
    // Initialized data
    nami_environment *p_environment = 0;
    char *p_prompt_text = getenv("NAMI_PROMPT");
    char  _in[1024] = { 0 };
    char *p_in      = &_in;

    // Make sure there is a prompt
    p_prompt_text = (p_prompt_text) ? p_prompt_text : NAMI_PROMPT_DEFAULT;

    // Construct the environment
    if ( nami_environment_construct(&p_environment) == 0 ) return 0;
#include <nami/nami.h>

    // Print the prompt
    fprintf(stderr, "\r%s ", p_prompt_text);

    // read-eval-write loop
    while( fgets(p_in, 1024, stdin) )
    {

        // Initialized data
        nami_node *p_nami_node = (void *) 0;

        p_in[strlen(p_in) - 1] = '\0';

        // Print the prompt
        fprintf(stderr, "\r%s ", p_prompt_text);
    }

    // EOF?
    if ( feof(stdin) )
        fprintf(stderr, "\r\033[44m\033[[[[[EOF]]] <<< %s\033[0m\n", argv[0]);
    
    // Newline
    else 
        putchar('\n');

    // Success
    return EXIT_SUCCESS;
}
