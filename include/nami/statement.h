/** !
 * Nami statement node 
 * 
 * @file nami/statement.h
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
#include <nami/node.h>
#include <nami/assignment.h>

// Structure definitions
struct nami_statement_s 
{
    nami_assignment *p_assignment;
};

// Function declarations
// Evaluators
/** ! 
 * Evaluate a statement node
 * 
 * @param p_nami_node result
 * 
 * @return 1 on success, 0 on error
*/
int nami_evaluate_statement ( nami_node *p_nami_node, nami_environment *p_environment );
