/** !
 * High level nami functionality
 * 
 * @file nami/nami.h
 * 
 * @author Jacob Smith
 */

// Header guard
#pragma once

// Standard library
#include <stdio.h>
#include <stdlib.h>

// nami 
#include <nami/typedef.h>

// Preprocessor definitions
#define NAMI_PROMPT_DEFAULT "nami > "

// Platform dependent macros
#ifdef _WIN64
#define DLLEXPORT extern __declspec(dllexport)
#else
#define DLLEXPORT
#endif

// Set the reallocator for the dict submodule
#ifdef DICT_REALLOC
    #undef DICT_REALLOC
    #define DICT_REALLOC(p, sz) realloc(p, sz)
#endif

// Set the reallocator for the array submodule
#ifdef ARRAY_REALLOC
    #undef ARRAY_REALLOC
    #define ARRAY_REALLOC(p, sz) realloc(p, sz)
#endif

// Set the reallocator for the json submodule
#ifdef JSON_REALLOC
    #undef JSON_REALLOC
    #define JSON_REALLOC(p, sz) realloc(p, sz)
#endif

// Memory management macro
#ifndef NAMI_REALLOC
    #define NAMI_REALLOC(p, sz) realloc(p,sz)
    #define NAMI_FREE(p) free(p)
#endif
