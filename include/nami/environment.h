/** !
 * Nami environment 
 * 
 * @file nami/environment.h
 * 
 * @author Jacob Smith
 */

// Header guard
#pragma once

// Standard library
#include <stdio.h>

// dict module
#include <dict/dict.h>

// nami 
#include <nami/typedef.h>
#include <nami/nami.h>

// Preprocessor defines
#define NAMI_ENVIRONMENT_ID_NAME_LENGTH 63 + 1

// Structure definitions
struct nami_environment_s 
{
    dict *p_dict;
};

// Function declarations
// Allocators
/** ! 
 * Allocate a nami environment
 * 
 * @param pp_nami_environment result
 * 
 * @return 1 on success, 0 on error
*/
int nami_environment_create ( nami_environment **pp_nami_environment );

// Constructors
/** ! 
 * Construct a nami environment
 * 
 * @param pp_nami_environment result
 * 
 * @return 1 on success, 0 on error
*/
int nami_environment_construct ( nami_environment **pp_nami_environment );

// Accessors
/** ! 
 * Set an environment variable
 * 
 * @param p_nami_environment the environment
 * @param p_key              the key
 * @param pp_result          the result
 * 
 * @return 1 on success, 0 on error
*/
int nami_environment_get ( nami_environment *p_nami_environment, const char *const p_key, void **pp_result );

// Mutators
/** ! 
 * Set an environment variable
 * 
 * @param p_nami_environment the environment
 * @param p_key              the key
 * @param p_value            the value
 * 
 * @return 1 on success, 0 on error
*/
int nami_environment_set ( nami_environment *p_nami_environment, const char *const p_key, void *p_value );
