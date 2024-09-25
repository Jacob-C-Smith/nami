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

int nami_lexer_construct ( nami_lexer **pp_lexer, char *p_path )
{
    
    // Argument check
    if ( pp_lexer == (void *) 0 ) goto no_lexer;

    // Initialized data
    nami_lexer *p_lexer = NAMI_REALLOC(0, sizeof(nami_lexer));

    // Error check
    if ( p_lexer == (void *) 0 ) goto no_mem;

    // Initialize data
    memset(p_lexer, 0, sizeof(nami_lexer)); 

    // Store the text pointer
    p_lexer->p_file = stdin;

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

int nami_lexer_next ( nami_lexer *p_lexer )
{

    char c = fgetc(p_lexer->p_file);
    char buf[256] = { 0 };

    while (isblank(c) || c == '\n')
        c = fgetc(p_lexer->p_file);
    
    if ( ungetc(c, p_lexer->p_file) == -1 ) return 0;
    
    if ( isalpha(c) )
    {
        hash64 h = 0;
        fscanf(p_lexer->p_file, " %[A-Za-z0-9_]", &buf);
        h = hash_crc64(buf, strlen(buf));
        h %= (sizeof(_p_keywords) / sizeof(char *));

        if ( _p_keywords[h] )
        {
            if ( strcmp(_p_keywords[h], buf) == 0 )
                printf("{\"keyword\":\"%s\"}\n", buf);
            else
                printf("{\"identifier\":\"%s\"}\n", buf);
        }
        else
                printf("{\"identifier\":\"%s\"}\n", buf);
    }
    else if ( isdigit(c) )
    {
        int i = 0;
        fscanf(p_lexer->p_file, " %d", &i);
        printf("{\"integer literal\":\"%d\"}\n", i);
    }
    else if ( ispunct(c) )
    {
        if (c == '/')
        {
            char d = fgetc(p_lexer->p_file);
            if ( d == '/' )
            {
                while (c != '\n')
                {
                    c = fgetc(p_lexer->p_file);
                }
            }
            else
            {
                ungetc(d, p_lexer->p_file);
                ungetc(c, p_lexer->p_file);
            }
        }
        else if (c == '\"')
        {
            
            printf("{\"string literal\":\"");
            c = fgetc(p_lexer->p_file);
            
            do
            {
                c = fgetc(p_lexer->p_file);
                putchar(c);
            }
            while (c != '\"');

            putchar('}');
            putchar('\n');

        }
        else
        {
            hash64 h = 0;
            fscanf(p_lexer->p_file, " %[^A-Za-z0-9\". \n]s", &buf);
            h = hash_crc64(buf, strlen(buf));

            if ( _p_operators[h % (sizeof(_p_operators) / sizeof(char *))] )
            {
                if ( strcmp(_p_operators[h % (sizeof(_p_operators) / sizeof(char *))], buf) == 0 )
                    printf("{\"operator\":\"%s\"}\n", buf);
            }
            if (_p_separators[h % (sizeof(_p_separators) / sizeof(char *))])
            {
                if ( strcmp(_p_separators[h % (sizeof(_p_separators) / sizeof(char *))], buf) == 0 )
                    printf("{\"separator\":\"%s\"}\n", buf);
            }
        }
    } 
    else
    {
        fscanf(p_lexer->p_file, " %s", &buf);
        printf("{\"???\":\"%s\"}\n", buf);
    }

    return 1;
}

