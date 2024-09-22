#include <nami/lexer.h>

const char *p_whitespace[] =
{
    " ",
    "\n",
    "\t"
};

const char *p_letters[] = 
{
    "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
    "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"
};

const char *p_keywords[] =
{
    "wr",
    "rw",
    "then",
    "else",
    "while",
    "if",
    "begin",
    "end",
    "do",
    "rd"
};

struct
{
    char *p_string;
    char *p_textual;
    struct 
    {
        void *pfn_todo;
    } functions;
} _operators[] =
{
    [0] =
    {
        .functions =
        {
            .pfn_todo = 0
        },
        .p_string = "+",
        .p_textual = "add"
    },
    [1] = 
    {
        .functions = 
        {
            .pfn_todo = 0
        }, 
        .p_string = "-",
        .p_textual = "sub"
    },
    [2] = 
    {
        .functions = 
        {
            .pfn_todo = 0
        }, 
        .p_string = "*",
        .p_textual = "mul"
    },
    [3] = 
    {
        .functions = 
        {
            .pfn_todo = 0
        }, 
        .p_string = "/",
        .p_textual = "div"
    },
    [4] = 
    {
        .functions = 
        {
            .pfn_todo = 0
        }, 
        .p_string = "=",
        .p_textual = "mov"
    }
};

const char *p[] =
{
    "-",
    "*",
    "/",
    ";",
    "=",
    "(",
    ")",
    "<",
    "<=",
    ">",
    ">=",
    "<>",
    "==",
    "!=",
    "++",
    "--",
    "!",
    "~",
    "&",
    "*",
    "%",
    "&&",
    "||",
    "^",
    "<<",
    ">>",
    "+=",
    "-=",
    "*=",
    "/=",
    "%=",
    "<<=",
    ">>=",
    "&=",
    "^=",
    "|="
};

int nami_lexer_construct ( nami_lexer **pp_lexer )
{
    
    // Argument check
    if ( pp_lexer == (void *) 0 ) goto no_lexer;

    // Initialized data
    nami_lexer *p_lexer = NAMI_REALLOC(0, sizeof(nami_lexer));

    // Error check
    if ( p_lexer == (void *) 0 ) goto no_mem;

    // Initialize data
    memset(p_lexer, 0, sizeof(nami_lexer)); 

    // Return a pointer to the caller
    *pp_lexer = p_lexer;

    // Success
    return 1;

    // Error handling
    {
        
        // Argument check
        {
            no_lexer:
                #ifndef NDEBUG
                    log_error("[nami] [lexer] Null pointer provided for parameter \"pp_lexer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }

        // Standard library errors
        {
            no_mem:
                #ifndef NDEBUG
                    log_error("[Standard Library] Failed to allocate memory in call to function \"%s\"\n", __FUNCTION__);
                #endif
                
                // Error
                return 0;
        }
    }
}

int nami_lexer_whitespace ( char *pointer, char **return_pointer )
{

    // Argument check
    if (  pointer == (void *) 0 ) goto no_pointer;
    if ( *pointer ==       '\0' ) goto done;

    // Skip past spaces, line feed, carriage return, horizontal tab
    while (
        *pointer == ' '  ||
        *pointer == '\n' ||
        *pointer == '\r' ||
        *pointer == '\t' ||
        *pointer == '\0' 
    )
    { pointer++; };

    // Error checking
    if ( *pointer == '\0' ) return 0;
    
    done:

    // Update the pointer
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_pointer:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

        }
    }
}

int nami_lexer_comment ( char *pointer, char **return_pointer )
{
    
    // Argument check
    if (  pointer == (void *) 0 ) goto no_pointer;
    if ( *pointer ==       '\0' ) goto done;

    // Check for the correct prefix
    if ( ! ( pointer[0] == '/' || pointer [1] == '*' ) ) goto malformed_comment;

    // Skip past comments
    while (
        *pointer != '\0'        || 
        ( pointer[0] != '*' &&
          pointer[1] != '/'    ) 
    )
    { pointer++; };

    // Error checking
    if ( *pointer == '\0' ) return 0;
    
    done:

    // Update the pointer
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_pointer:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }

        // Scan errors
        {
            malformed_comment:

                #ifndef NDEBUG
                    log_error("[nami] Failed to parse comment in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }

}

int nami_lexer_identifier ( char *p_result, char *pointer, char **return_pointer )
{

    // Argument check
    if (  pointer  == (void *) 0 ) goto no_pointer;
    if ( *pointer  ==       '\0' ) goto done;
    if (  p_result == (void *) 0 ) goto no_result;

    // Initialized data
    char *initial_pointer = pointer;

    // Error checking
    if ( *pointer == '\0' ) return 0;

    done:

    // Update the pointer
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_pointer:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

            no_result:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int nami_lexer_keyword ( char *p_result, char *pointer, char **return_pointer )
{

    // Argument check
    if (  pointer  == (void *) 0 ) goto no_pointer;
    if ( *pointer  ==       '\0' ) return 0;
    if (  p_result == (void *) 0 ) goto no_result;
    if ( *pointer  == '\0' ) return 0;

    // Initialized data
    char       *initial_pointer = pointer;
    char        _keyword[256]   = { 0 };
    size_t      len             = 0;
    hash64      hash            = 0;
    const char *p_keyword_value = 0;
    
    // Scan the keyword 
    if ( sscanf(pointer, " %s", _keyword) == 0 ) return 0;

    // Compute the length of the keyword
    len = strlen(_keyword);

    // Compute the hash of the keyword
    hash = hash_crc64(_keyword, len);

    // Index the keyword
    p_keyword_value = _p_keywords[hash % ( sizeof(_p_keywords) / sizeof(const char *))];
    
    if ( p_keyword_value ==     (void *) 0 ) return 0;
    if ( strcmp(p_keyword_value, _keyword) ) return 0;

    printf("{\"keyword\":\"%s\"}\n", p_keyword_value);

    done:

    nami_lexer_whitespace(pointer + strlen(p_keyword_value), &pointer);

    // Update the pointer
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_pointer:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

            no_result:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }

        // Nami errors
        {
            unrecognized_keyword:
                #ifndef NDEBUG
                    log_error("[nami] [lexer] Unrecognized keyword \"%s\" in call to function \"%s\"\n", pointer, __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}

int nami_lexer_operator ( char *p_result, char *pointer, char **return_pointer )
{

    // Argument check
    if (  pointer  == (void *) 0 ) goto no_pointer;
    if ( *pointer  ==       '\0' ) return 0;
    if (  p_result == (void *) 0 ) goto no_result;
    if ( *pointer  == '\0' ) return 0;

    // Initialized data
    char       *initial_pointer  = pointer;
    char        _keyword[256]    = { 0 };
    size_t      len              = 0;
    hash64      hash             = 0;
    const char *p_operator_value = 0;
    
    // Scan the keyword 
    if ( sscanf(pointer, " %s", _keyword) == 0 ) return 0;

    // Compute the length of the keyword
    len = strlen(_keyword);

    // Compute the hash of the keyword
    hash = hash_crc64(_keyword, len);

    // Index the keyword
    p_operator_value = _p_operators[hash % ( sizeof(_p_operators) / sizeof(const char *))];
    
    if ( p_operator_value ==     (void *) 0 ) return 0;
    if ( strcmp(p_operator_value, _keyword) ) return 0;

    printf("{\"operator\":\"%s\"}\n", p_operator_value);

    done:

    nami_lexer_whitespace(pointer + strlen(p_operator_value), &pointer);

    // Update the pointer
    *return_pointer = pointer;

    // Success
    return 1;

    // Error handling
    {

        // Argument errors
        {
            no_pointer:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;

            no_result:
                #ifndef NDEBUG
                    log_error("[nami] Null pointer provided for parameter \"pointer\" in call to function \"%s\"\n", __FUNCTION__);
                #endif

                // Error
                return 0;
        }

        // Nami errors
        {
            unrecognized_keyword:
                #ifndef NDEBUG
                    log_error("[nami] [lexer] Unrecognized keyword \"%s\" in call to function \"%s\"\n", pointer, __FUNCTION__);
                #endif

                // Error
                return 0;
        }
    }
}
