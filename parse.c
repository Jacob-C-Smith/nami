#include <nami/parse.h>

int nami_parse_whitespace ( char *pointer, char **return_pointer )
{

    // Argument check
    if (  pointer == (void *) 0 ) goto no_pointer;
    if ( *pointer ==       '\0' ) goto done;

    // Skip past spaces, line feed, carriage return, horizontal tab
    while (
        *pointer == ' '  ||
        *pointer == '\n' ||
        *pointer == '\r' ||
        *pointer == '\t' ||
        *pointer == '\0' 
    )
    { pointer++; };

    // Error checking
    if ( *pointer == '\0' ) return 0;
    
    done:

    // Update the pointer
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_pointer:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

        }
    }
}

int nami_parse_node ( nami_node **pp_nami_node, char *pointer, char **return_pointer )
{

    // Argument check
    if ( pp_nami_node == (void *) 0 ) goto no_node;

    // Initialized data


    // Return the updated cursor to the caller
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_node:
                #ifndef NDEBUG
                    log_error("[nami] [parse] Null pointer provided for parameter \"pp_nami_node\" ")
                #endif

                // Error
                return 0;
        }
    }
}