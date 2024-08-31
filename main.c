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
#include <nami/nami.h>
#include <nami/node.h>
#include <nami/environment.h>
#include <nami/statement.h>

int main ( int argc, const char *argv[] )
{
    
    // Initialized data
    nami_environment *p_environment = 0;
    char *p_prompt_text = getenv("NAMI_PROMPT");
    char _in[1024] = { 0 };

    // Make sure there is a prompt
    p_prompt_text = (p_prompt_text) ? p_prompt_text : NAMI_PROMPT_DEFAULT;

    // Construct the environment
    if ( nami_environment_construct(&p_environment) == 0 ) return 0;

    // Print the prompt
    printf("%s ", p_prompt_text);

    // read-eval-write loop
    while( fgets(&_in, 1024, stdin) )
    {

        // Initialized data
        nami_node *p_nami_node = (void *) 0;

        // Read
        nami_parse_statement(&p_nami_node, &_in, 0);

        // Eval
        p_nami_node->pfn_evaluate(p_nami_node, p_environment);

        // Write
        //

        // Print the prompt
        printf("%s ", p_prompt_text);
    }

    // EOF?
    if ( feof(stdin) )
        printf("\r\033[44m\033[[[[[EOF]]]\033[0m\n");
    
    // Newline
    else 
        putchar('\n');

    // Success
    return EXIT_SUCCESS;
}
