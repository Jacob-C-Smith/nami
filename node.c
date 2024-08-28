/** !
 * Implements nami node
 *
 * @file node.c
 * 
 * @author Jacob Smith
 */

// Header
#include <nami/node.h>

int nami_node_create ( nami_node **pp_nami_node, enum nami_node_type_e type )
{
    
    // TODO: Argument Check
    //
    
    // Initialized data
    nami_node *p_nami_node = (void *) 0;
    
    // Allocate memory for the node
    p_nami_node = realloc(0, sizeof(nami_node));

    // Populate the node 
    *p_nami_node = (nami_node)
    {
        .type         = type,
        .pfn_evaluate = _pfn_node_evaluators[type]
    };

    // Success
    return 1;
}

int nami_node_parse ( nami_node **pp_node, char *p_text, char **pp_return_pointer )
{

    // TODO: Argument Check
    //
    
    // Initialized data
    nami_node *p_nami_node = (void *) 0;
    
    // Success
    return 1;
}
