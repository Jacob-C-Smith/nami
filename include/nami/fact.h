/** !
 * Nami fact node 
 * 
 * @file nami/fact.h
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
struct nami_fact_s 
{
    int i; 
};

// Function declarations
// Evaluators
/** ! 
 * Evaluate a fact node
 * 
 * @param p_nami_node result
 * 
 * @return 1 on success, 0 on error
*/
int nami_evaluate_fact ( nami_node *p_nami_node, nami_environment *p_environment );
