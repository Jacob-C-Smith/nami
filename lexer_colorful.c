/** !
 * Nami lexer pretty print
 * 
 * @file main.c
 * 
 * @author Jacob Smith
 */

// Standard library
#include <stdio.h>
#include <stdlib.h>

// json module
#include <json/json.h>

int main ( int argc, const char *argv[] )
{

    // Initialized data
    char  _in[1024] = { 0 };
    char *p_in      = &_in;

    // read-eval-write loop
    while( fgets(p_in, 1024, stdin) )
    {

        // Initialized data
        json_value *p_value = (void *) 0 ;

        // Parse the json value
        json_value_parse(p_in,0,&p_value);

        // Error check
        if ( p_value->type != JSON_VALUE_OBJECT ) continue;
        
        if      ( dict_get(p_value->object, "identifier"     ) ) printf("\033[93m");
        else if ( dict_get(p_value->object, "keyword"        ) ) printf("\033[95m");
        else if ( dict_get(p_value->object, "separator"      ) ) printf("\033[94m");
        else if ( dict_get(p_value->object, "operator"       ) ) printf("\033[94m");
        else if ( dict_get(p_value->object, "string literal" ) ) printf("\033[91m");
        else if ( dict_get(p_value->object, "number literal" ) ) printf("\033[90m");
        else if ( dict_get(p_value->object, "integer literal") ) printf("\033[90m");
        else if ( dict_get(p_value->object, "comment"        ) ) printf("\033[92m");
            
        
        // Print the token
        json_value_print(p_value);

        // Restore the color.
        printf("\033[0m\n");

        // Free the value
        json_value_free(p_value);
    }

    // EOF?
    if ( feof(stdin) )
        fprintf(stderr, "\r\033[44m\033[[[[[EOF]]] >>> %s\033[0m\n", argv[0]);
    
    // Newline
    else 
        putchar('\n');

    // Success
    return EXIT_SUCCESS;
}
