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
    
    // Argument Check
    if ( pp_nami_node == (void *) 0 ) goto no_node;
    
    // Initialized data
    nami_node *p_nami_node = (void *) 0;
    
    // Allocate memory for the node
    p_nami_node = NAMI_REALLOC(0, sizeof(nami_node));

    // Populate the node 
    *p_nami_node = (nami_node)
    {
        .type         = type,
        .pfn_evaluate = _pfn_node_evaluators[type]
    };

    // Success
    return 1;

    // Error handling
    {

        // Argument check
        {
            no_node:
                #ifndef NDEBUG
                    log_error("[nami] [node] Null pointer provided for parameter \"pp_nami_node\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
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
