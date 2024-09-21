/** !
 * Nami environment implementation
 * 
 * @file environment.c
 * 
 * @author Jacob Smith
 */

// Header
#include <nami/environment.h>

int nami_environment_create ( nami_environment **pp_nami_environment )
{

    // Argument check
    //

    // Initialized data
    nami_environment *p_nami_environment = NAMI_REALLOC(0, sizeof(nami_environment));

    // Error check
    if ( p_nami_environment == (void *) 0 ) return 0;

    // Initialize data
    memset(p_nami_environment, 0, sizeof(nami_environment));

    // Return a pointer to the caller
    *pp_nami_environment = p_nami_environment;

    // Success
    return 1;
}

int nami_environment_construct ( nami_environment **pp_nami_environment )
{
    
    // Argument check
    //

    // Initialized data
    nami_environment *p_nami_environment = (void *) 0;

    // Allocate an environment
    if ( nami_environment_create(&p_nami_environment) == 0 ) return 0;
    
    // Construct a dictionary
    if ( dict_construct(&p_nami_environment->p_dict, 512, 0) == 0 ) return 0;

    // Return a pointer to the caller
    *pp_nami_environment = p_nami_environment;

    // Success
    return 1;
}

int nami_environment_get ( nami_environment *p_nami_environment, const char *const p_key, void **pp_result )
{

    // Argument check
    // 

    // Initialized data
    const void *p_result = dict_get(p_nami_environment->p_dict, p_key);

    // Error check
    if ( p_result == (void *) 0 ) return 0;

    // Return a pointer to the caller
    *pp_result = p_result;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        { }
    }
}

int nami_environment_set ( nami_environment *p_nami_environment, const char *const p_key, void *p_value )
{
    
    // Argument check
    // 

    // Set the environment variable
    dict_add(p_nami_environment->p_dict, p_key, p_value);

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        { }
    }
}