/** !
 * Nami type definitions
 * 
 * @file nami/typedef.h
 * 
 * @author Jacob Smith
 */

// Header guard
#pragma once

// Standard library
#include <stdio.h>

// Enumeration definitions
enum nami_node_type_e
{
    NAMI_INVALID,
    NAMI_STATEMENT,
    NAMI_ASSIGNMENT,
    NAMI_IDENTIFIER,
    NAMI_EXPRESSION,
    NAMI_TERM,
    NAMI_FACT,
    NAMI_NUMBER,
    NAMI_ADD_OPERATION,
    NAMI_MULTIPLY_OPERATION,
    NAMI_NODE_QUANTITY
};

// Forward declarations
struct nami_environment_s;
struct nami_node_s;
struct nami_statement_s;
struct nami_assignment_s;
struct nami_identifier_s;
struct nami_expression_s;
struct nami_term_s;
struct nami_fact_s;
struct nami_number_s;    
struct nami_add_s;
struct nami_mul_s;

// Type definitions
typedef struct nami_environment_s nami_environment;
typedef struct nami_node_s        nami_node;
typedef struct nami_statement_s   nami_statement;
typedef struct nami_assignment_s  nami_assignment;
typedef struct nami_identifier_s  nami_identifier;
typedef struct nami_expression_s  nami_expression;
typedef struct nami_term_s        nami_term;
typedef struct nami_fact_s        nami_fact;
typedef struct nami_number_s      nami_number;
typedef struct nami_add_s         nami_add;
typedef struct nami_mul_s         nami_mul;

typedef int (*fn_nami_parse)         ( nami_node *p_node, char             *p_text, char **pp_return_pointer );
typedef int (fn_nami_evaluate)       ( nami_node *p_node, nami_environment *p_environment );
typedef int (*fn_nami_code_generate) ( nami_node *p_node, FILE             *p_f );
