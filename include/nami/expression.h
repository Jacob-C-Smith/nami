/** !
 * Nami expression node 
 * 
 * @file nami/expression.h
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

// Structure definitions
struct nami_expression_s 
{
    nami_term *p_term;
    // ADD OP
    nami_expression *p_expression;
};

// Function declarations
// Evaluators
/** ! 
 * Evaluate a expression node
 * 
 * @param p_nami_node result
 * 
 * @return 1 on success, 0 on error
*/
int nami_evaluate_expression ( nami_node *p_nami_node, nami_environment *p_environment );
