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

int main ( int argc, const char *argv[] )
{
    
    // Initialized data
    nami_environment *p_environment = 0;
    char _in[1024] = { 0 };

    // read-eval-write loop
    while( fgets(&_in, 1024, stdin) )
    {

        // Initialized data
        nami_node *p_nami_node = (void *) 0;

        // Read
        nami_node_parse(&p_nami_node, &_in, 0);

        // Eval
        p_nami_node->pfn_evaluate(p_nami_node, p_environment);

        // Write
        //
    }

    // Success
    return EXIT_SUCCESS;
}
