/** !
 * Nami node 
 * 
 * @file nami/node.h
 * 
 * @author Jacob Smith
 */

// Header guard
#pragma once

// Standard library
#include <stdio.h>

// nami 
#include <nami/typedef.h>
#include <nami/nami.h>
#include <nami/statement.h>
#include <nami/assignment.h>
#include <nami/expression.h>
#include <nami/term.h>
#include <nami/fact.h>

struct nami_node_s 
{
    enum nami_node_type_e type;

    fn_nami_evaluate *pfn_evaluate;
    
    union
    {
        struct nami_statement_s  _statement;
        struct nami_assignment_s _assignment;
//      struct nami_identifier_s _identifier;
        struct nami_expression_s _expression;
        struct nami_term_s       _term;
        struct nami_fact_s       _fact;
//      struct nami_number_s     _number;
//      struct nami_add_s        _add;
//      struct nami_mul_s        _mul;
    };
};

// Constant data
const char *_node_type_names [ ] =
{
    [NAMI_INVALID]            = "Invalid",
    [NAMI_STATEMENT]          = "Statement",
    [NAMI_ASSIGNMENT]         = "Assignment",
    [NAMI_IDENTIFIER]         = "Identifier",
    [NAMI_EXPRESSION]         = "Expression",
    [NAMI_TERM]               = "Term",
    [NAMI_FACT]               = "Fact",
    [NAMI_NUMBER]             = "Number",
    [NAMI_ADD_OPERATION]      = "Add",
    [NAMI_MULTIPLY_OPERATION] = "Multiply"
};

const fn_nami_evaluate *_pfn_node_evaluators [ ] =
{
    [NAMI_INVALID]            = (fn_nami_evaluate *) 0,
    [NAMI_STATEMENT]          = (fn_nami_evaluate *) nami_evaluate_statement,
    [NAMI_ASSIGNMENT]         = (fn_nami_evaluate *) nami_evaluate_assignment,
    [NAMI_IDENTIFIER]         = (fn_nami_evaluate *) 0,
    [NAMI_EXPRESSION]         = (fn_nami_evaluate *) nami_evaluate_expression,
    [NAMI_TERM]               = (fn_nami_evaluate *) nami_evaluate_term,
    [NAMI_FACT]               = (fn_nami_evaluate *) nami_evaluate_fact,
    [NAMI_NUMBER]             = (fn_nami_evaluate *) 0,
    [NAMI_ADD_OPERATION]      = (fn_nami_evaluate *) 0,
    [NAMI_MULTIPLY_OPERATION] = (fn_nami_evaluate *) 0
};

const fn_nami_parse *_pfn_node_parsers [ ] =
{
    [NAMI_INVALID]            = (fn_nami_parse *) 0,
    [NAMI_STATEMENT]          = (fn_nami_parse *) nami_parse_statement,
    [NAMI_ASSIGNMENT]         = (fn_nami_parse *) nami_evaluate_assignment,
    [NAMI_IDENTIFIER]         = (fn_nami_parse *) 0,
    [NAMI_EXPRESSION]         = (fn_nami_parse *) nami_evaluate_expression,
    [NAMI_TERM]               = (fn_nami_parse *) nami_evaluate_term,
    [NAMI_FACT]               = (fn_nami_parse *) nami_evaluate_fact,
    [NAMI_NUMBER]             = (fn_nami_parse *) 0,
    [NAMI_ADD_OPERATION]      = (fn_nami_parse *) 0,
    [NAMI_MULTIPLY_OPERATION] = (fn_nami_parse *) 0
};

// Function declarations
// Allocators
/** ! 
 * Allocate a node
 * 
 * @param pp_nami_node result
 * 
 * @return 1 on success, 0 on error
*/
int nami_node_create ( nami_node **pp_nami_node, enum nami_node_type_e type );
