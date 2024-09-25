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

/**!
 * Return the size of a file IF buffer == 0 ELSE read a file into buffer
 * 
 * @param path path to the file
 * @param buffer buffer
 * @param binary_mode "wb" IF true ELSE "w"
 * 
 * @return 1 on success, 0 on error
 */
size_t load_file ( const char *path, void *buffer, bool binary_mode );

int main ( int argc, const char *argv[] )
{
    
    // Initialized data
    nami_lexer *p_lexer = (void *) 0;
    char  _in[4096] = { 0 };
    char *p_in = &_in;
    int r = 1;

    nami_lexer_construct(&p_lexer, "resources/lexer/example/main.nami");

    while(nami_lexer_next(p_lexer));

    // // EOF?
    //if ( feof(stdin) )
        fprintf(stderr, "\r\033[44m\033[[[[[EOF]]] >>> %s\033[0m\n", argv[0]);
    // // Newline
    // else 
    //     putchar('\n');

    // Success
    return EXIT_SUCCESS;
}

size_t load_file ( const char *path, void *buffer, bool binary_mode )
{

    // Argument checking 
    if ( path == 0 ) goto no_path;

    // Initialized data
    size_t  ret = 0;
    FILE   *f   = fopen(path, (binary_mode) ? "rb" : "r");
    
    // Check if file is valid
    if ( f == NULL ) goto invalid_file;

    // Find file size and prep for read
    fseek(f, 0, SEEK_END);
    ret = (size_t) ftell(f);
    fseek(f, 0, SEEK_SET);
    
    // Read to data
    if ( buffer ) 
        ret = fread(buffer, 1, ret, f);

    // The file is no longer needed
    fclose(f);
    
    // Success
    return ret;

    // Error handling
    {

        // Argument errors
        {
            no_path:
                #ifndef NDEBUG
                    log_error("[json] Null path provided to function \"%s\n", __FUNCTION__);
                #endif

            // Error
            return 0;
        }

        // File errors
        {
            invalid_file:
                #ifndef NDEBUG
                    printf("[Standard library] Failed to load file \"%s\". %s\n",path, strerror(errno));
                #endif

            // Error
            return 0;
        }
    }
}
