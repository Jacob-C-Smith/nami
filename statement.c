#include <nami/statement.h>

int nami_parse_statement ( nami_node **pp_node, char *p_text, char **pp_return_pointer )
{

    // Argument check
    //

    // Initialized data
    nami_node *p_node = (void *) 0;
    char *p_text = p_text;

    // Allocate memory for the node
    if ( nami_node_create(&p_node, NAMI_STATEMENT) == 0 ) return 0;

    // Parse the assignment node
    if ( nami_parse_assignment(&p_node->_statement.p_assignment, p_text, &p_text) == 0 ) return 0;

    // Update the cursor
    *pp_return_pointer = p_text;

    // Return a pointer to the caller
    *pp_node = p_node;

    // Success
    return 1;
}

int nami_evaluate_statement ( nami_node *p_node, nami_environment *p_environment )
{
    
    // Argument check
    //

    // Initialized data
    //

    // Success
    return 1;
}

int nami_code_generate_statement ( nami_node *p_node, FILE *p_f )
{

    // Argument check
    //

    // Initialized data
    //

    // Success
    return 1;
}