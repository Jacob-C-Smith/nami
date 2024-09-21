/** !
 * Nami lexer
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
    char  _in[1024] = { 0 };
    char *p_in      = &_in;
    int r = 1;

    // Read text; write tokens
    while( fgets(p_in, 1024, stdin) )
    {

        // Initialized data
        nami_node *p_nami_node = (void *) 0;

        // Store a null terminator on the input buffer
        p_in[strlen(p_in) - 1] = '\0';

        // Parse the line as a sequence of keywords
        while ( *p_in != '\0' )
        {
            if ( p_in[0] == '\"' )
            {
                json_value *p_value = 0;
                r = json_value_parse(p_in, &p_in, &p_value);
                if ( p_value->type == JSON_VALUE_STRING )
                    printf("{\"string literal\":\"%s\"}\n", p_value->string);

                json_value_free(p_value);
            }
            else if ( p_in[0] == '{' )
            {
                json_value *p_value = 0;
                r = json_value_parse(p_in, &p_in, &p_value);
                if ( p_value->type == JSON_VALUE_OBJECT )
                {
                    printf("{\"object literal\":");
                    json_value_print(p_value);
                    printf("}\n");
                }
            
                json_value_free(p_value);
            }
            else if ( p_in[0] == '[' )
            {
                json_value *p_value = 0;
                r = json_value_parse(p_in, &p_in, &p_value);
                if ( p_value->type == JSON_VALUE_ARRAY )
                {
                    printf("{\"array literal\":");
                    json_value_print(p_value);
                    printf("}\n");
                }
            
                json_value_free(p_value);
            }
            else if ( isdigit(p_in[0]) )
            {
                json_value *p_value = 0;
                r = json_value_parse(p_in, &p_in, &p_value);
                if ( p_value->type == JSON_VALUE_NUMBER )
                    printf("{\"number literal\":%g}\n", p_value->number);
                else if ( p_value->type == JSON_VALUE_INTEGER )
                    printf("{\"integer literal\":%d}\n", p_value->integer);

                json_value_free(p_value);

            }
            else if ( ispunct(p_in[0]) )
                r = nami_lexer_operator((char *)1, p_in, &p_in); 
            else if ( isalpha(p_in[0]) )
                r = nami_lexer_keyword((char *)1, p_in, &p_in); 
        };
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
