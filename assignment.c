#include <nami/assignment.h>

int nami_evaluate_assignment ( nami_node *p_nami_node, nami_environment *p_environment )
{
    
    // Argument check
    //

    // Initialized data
    //

    // Success
    return 1;
}

int nami_parse_assignment ( nami_node **pp_node, char *p_text, char **pp_return_pointer )
{

    // Argument check
    //

    // External functions
    extern int nami_node_create ( nami_node **pp_nami_node, enum nami_node_type_e type );

    // Initialized data
    nami_node *p_node = (void *) 0;

    // Allocate memory for the node
    if ( nami_node_create(&p_node, NAMI_ASSIGNMENT) == 0 ) return 0;

    // Consume whitespaces
    //if ( nami_parse_whitespace(p_text, &p_text) == 0 ) return 0;

    // Parse the assignment node
    //if ( nami_parse_assignment(&p_node, p_text, &p_text) == 0 ) return 0;

    // Update the cursor
    *pp_return_pointer = p_text;

    // Return a pointer to the caller
    *pp_node = p_node;

    // Success
    return 1;
}