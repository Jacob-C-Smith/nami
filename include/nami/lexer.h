/** !
 * Nami lexerner 
 * 
 * @file nami/lexer.h
 * 
 * @author Jacob Smith
 */

// Header guard
#pragma once

// Standard library
#include <stdio.h>

// dict module
#include <dict/dict.h>

// json module
#include <json/json.h>

// nami 
#include <nami/typedef.h>
#include <nami/nami.h>
#include <nami/lexer_lut.h>

enum nami_token_type_e
{
    NAMI_TOKEN_TYPE_NUMERIC_LITERAL,
    NAMI_TOKEN_CHARACTER_LITERAL,
    NAMI_TOKEN_NUMBER_LITERAL,
    NAMI_TOKEN_STRING_LITERAL,
    NAMI_TOKEN_KEYWORD_LITERAL,
    NAMI_TOKEN_IDENTIFIER_LITERAL,
    NAMI_TOKEN_OPERATOR
};

// Structure definitions
struct nami_lexer_s
{
    int i;
};

struct nami_token_s
{
    enum nami_token_type_e _type;

    union
    {
        struct 
        {
            json_value *p_number;
        } numeric_literal;

        char _character_literal;

        struct
        {
            json_value *p_string;
        };
        
        struct 
        {
            
        } keyword;
    };
};

/** !
 * Scan whitespaces in nami text 
 * 
 * @param p_pointer pointer to nami text
 * @param pp_result null if discarding result else pointer to end of whitespace
 * 
 * @return 1 on success, 0 on error
 */
int nami_lexer_whitespace ( char *pointer, char **return_pointer );

int nami_lexer_comment ( char *pointer, char **return_pointer );

int nami_lexer_identifier ( char *p_result, char *pointer, char **return_pointer );

int nami_lexer_keyword ( char *p_result, char *pointer, char **return_pointer );

int nami_lexer_operator ( char *p_result, char *pointer, char **return_pointer );
