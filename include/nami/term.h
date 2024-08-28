/** !
 * Nami term node 
 * 
 * @file nami/term.h
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

#define NAMI_ENVIRONMENT_ID_NAME_LENGTH 63 + 1

// Structure definitions
struct nami_term_s 
{
    char _id[NAMI_ENVIRONMENT_ID_NAME_LENGTH];
    nami_expression *p_expression;
};

// Function declarations
// Evaluators
/** ! 
 * Evaluate an term node
 * 
 * @param p_nami_node result
 * 
 * @return 1 on success, 0 on error
*/
int nami_evaluate_term ( nami_node *p_nami_node, nami_environment *p_environment );
