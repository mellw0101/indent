#include "../include/prototypes.h"

/** Stuff that needs to be shared with the rest of indent. Documented in
 * indent.h.  */
char *token;
char *token_end;

#define alphanum 1
#define opchar   3

/* typedef struct
{
    char      *rwd;
    rwcodes_ty rwcode;
} templ_ty; */

/** Pointer to a vector of keywords specified by the user.  */
static templ_t *user_specials = 0;

/** Allocated size of user_specials.  */
static unsigned int user_specials_max = 0;

/** Index in user_specials of the first unused entry.  */
static unsigned int user_specials_idx = 0;

char chartype[] = {
/* this is used to facilitate the decision of
 * what type (alphanumeric, operator) each
 * character is */
#ifndef CHARSET_EBCDIC

    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1,
    3, 3, 0, 0, 0, 3, 3, 0, 3, 0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 3, 3, 3, 3, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 3, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 3, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

#else  /* CHARSET_EBCDIC */
    /*
     * The following table was generated by the program given just below
     */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*| .......| */
    0, 0, 0, 0, 3, 0, 3, 3, /*|..`.<(+|| */
    3, 0, 0, 0, 0, 0, 0, 0, /*|&.......| */
    0, 0, 3, 1, 3, 0, 0, 0, /*|..!$*);.| */
    3, 3, 0, 0, 0, 0, 0, 0, /*|-/......| */
    0, 0, 3, 0, 3, 1, 3, 3, /*|..^,%_>?| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 3, 0, /*|..:#@'="| */
    0, 1, 1, 1, 1, 1, 1, 1, /*|.abcdefg| */
    1, 1, 0, 0, 0, 0, 0, 0, /*|hi......| */
    0, 1, 1, 1, 1, 1, 1, 1, /*|.jklmnop| */
    1, 1, 0, 0, 0, 0, 0, 0, /*|qr......| */
    0, 0, 1, 1, 1, 1, 1, 1, /*|..stuvwx| */
    1, 1, 0, 0, 0, 0, 0, 0, /*|yz......| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|........| */
    0, 0, 0, 0, 0, 0, 0, 0, /*|...[\]..| */
    0, 1, 1, 1, 1, 1, 1, 1, /*|.ABCDEFG| */
    1, 1, 0, 0, 0, 0, 0, 0, /*|HI......| */
    0, 1, 1, 1, 1, 1, 1, 1, /*|.JKLMNOP| */
    1, 1, 0, 0, 0, 0, 0, 0, /*|QR......| */
    0, 0, 1, 1, 1, 1, 1, 1, /*|..STUVWX| */
    1, 1, 0, 0, 0, 0, 0, 0, /*|YZ......| */
    1, 1, 1, 1, 1, 1, 1, 1, /*|01234567| */
    1, 1, 0, 0, 0, 0, 0, 3, /*|89.{.}.~| */
#endif /* CHARSET_EBCDIC */
};

#if 0
/**
 * The table above was generated by the following program from
 * the ASCII version of the chartype[] array above, where the
 * unsigned char os_toascii[] array can be found in the source
 * for the Apache Web Server version 1.3.x, in the directories...
 *  src/os/bs2000/ebcdic.c    for the SIEMENS BS2000 mainframes,
 *  src/os/tpf/ebcdic.c       for the IBM TPF server line.
 * The following table was created for BS2000 EBCDIC character set,
 * but the few non-zero places should be compatible with IBM's EBCDIC.
 */
int main (void)
{
    const int GAP = 8;
    int i;
    int j;
    for (i = 0; i < 256; i += GAP)
    {
        printf ("  ");
        for (j = 0; j < GAP; ++j)
        {
           printf ("%d, ", chartype[os_toascii[i + j]]);
        }
        printf (" /*|");
        for (j = 0; j < GAP; ++j)
        {
           printf ("%c"typedef struct
            {
    char      *rwd;
    rwcodes_ty rwcode;
} templ_ty;
, isprint (i + j) ? (i + j) : '.');
        }
        printf ("|*/\n");
    }
    return 0;
}
#endif

/* Include code generated by gperf */
static templ_t *is_reserved(register const char *str, register size_t len);
#include "gperf.c"

/* Include code generated by gperf for C++ keyword set */
#undef MIN_HASH_VALUE /* remove old defs */
#undef MAX_HASH_VALUE
#undef TOTAL_KEYWORDS
#undef MIN_WORD_LENGTH
#undef MAX_WORD_LENGTH

static templ_t *is_reserved_cc(register const char *str, register size_t len);
#include "gperf-cc.c"

extern codes_t
lexi(void)
{
    /* This is set to 1 if the current token forces a following operator to be unary */
    int unary_delim = false;
    /* The last token type returned */
    static codes_t last_code = code_eof;
    /* Set to 1 if the last token was 'struct'. */
    static int l_struct = 0;
    /* Set to 1 if the last token was `enum'. */
    static int l_enum = 0;
    /* Internal code to be returned. */
    codes_t code;
    /* The delimiter character for a string. */
    char qchar;
    char tmpchar[2];
    /* Tell world that this token started in column 1 iff the last thing scanned was nl */
    parser_state_tos->col_1       = parser_state_tos->last_nl;
    parser_state_tos->last_saw_nl = parser_state_tos->last_nl;
    parser_state_tos->last_nl     = false;
    if (buf_ptr >= buf_end)
    {
        fill_buffer();
    }
    if (*buf_ptr == ' ' || *buf_ptr == TAB)
    {
        parser_state_tos->col_1 = false;
        /* Adjusts 'buf_ptr'. */
        skip_buffered_space();
    }
    /** INCREDIBLY IMPORTANT WARNING!!!
     
        Note that subsequent calls to `fill_buffer ()' may switch `buf_ptr'
        to a different buffer.  Thus when `token_end' gets set later, it
        may be pointing into a different buffer than `token'.
     */
    token = buf_ptr;
    /* Scan an alphanumeric token. */
    if ((!((buf_ptr[0] == 'L') && ((buf_ptr[1] == '"') || (buf_ptr[1] == '\''))) && /* Not a wide string */
         !(settings.gettext_strings && (buf_ptr[0] == '_') && (buf_ptr[1] == '(') &&
           (buf_ptr[2] == '"')) &&                                                  /* Not a gettext string */
         !(settings.gettext_strings && (buf_ptr[0] == 'N') && (buf_ptr[1] == '_') && (buf_ptr[2] == '(') &&
           (buf_ptr[3] == '"')) &&                                                  /* Not a gettext noop string */
         (chartype[0xff & (int)*buf_ptr] == alphanum)) ||
        ((buf_ptr[0] == '.') && isdigit(buf_ptr[1])))
    {
        /* We have a character or number. */
        templ_t *p;
        /**
         * Because the influence of a return on indenting (different from standard
         * identifiers) extends only to permitting a cast just after it, the next
         * string or number found after the return should remove its influence to
         * prevent mistaken identification of casts later on.
         */
        if (parser_state_tos->last_rw == rw_return)
        {
            parser_state_tos->last_rw = rw_none;
        }
        /* decimal, octal, hex, binary and floating point number format */
        if (isdigit(*buf_ptr) || ((buf_ptr[0] == '.') && isdigit(buf_ptr[1])))
        {
            int seendot = 0, seenexp = 0, ishexa = 0, isbinary = 0;
            if (*buf_ptr == '0')
            {
                if ((buf_ptr[1] == 'x') || (buf_ptr[1] == 'X'))
                {
                    ishexa = 1;
                    buf_ptr += 1;
                }
                else if ((buf_ptr[1] == 'b') || (buf_ptr[1] == 'B'))
                {
                    isbinary = 1;
                    buf_ptr += 1;
                }
            }
            while (1)
            {
                if (*buf_ptr == '.')
                {
                    if (seendot)
                    {
                        break;
                    }
                    else
                    {
                        seendot++;
                    }
                }
                buf_ptr++;
                if (!((ishexa && !seenexp && isxdigit(*buf_ptr)) ||
                      (isbinary && !seenexp && (*buf_ptr == '0' || *buf_ptr == '1')) ||
                      ((!(ishexa || isbinary) || seenexp) && isdigit(*buf_ptr))) &&
                    *buf_ptr != '.')
                {
                    if ((ishexa ? (*buf_ptr != 'P' && *buf_ptr != 'p') : (*buf_ptr != 'E' && *buf_ptr != 'e')) ||
                        seenexp)
                    {
                        break;
                    }
                    else
                    {
                        seenexp++;
                        seendot++;
                        buf_ptr++;
                        if (*buf_ptr == '+' || *buf_ptr == '-')
                        {
                            buf_ptr++;
                        }
                    }
                }
            }
            if (*buf_ptr == 'F' || *buf_ptr == 'f' || *buf_ptr == 'i' || *buf_ptr == 'j')
            {
                buf_ptr++;
            }
            else if (*buf_ptr == 'D' || *buf_ptr == 'd')
            {
                if (buf_ptr[1] == 'F' || buf_ptr[1] == 'f' || buf_ptr[1] == 'D' || buf_ptr[1] == 'd' ||
                    buf_ptr[1] == 'L' || buf_ptr[1] == 'l')
                {
                    buf_ptr += 2;
                }
            }
            else
            {
                while (*buf_ptr == 'U' || *buf_ptr == 'u' || *buf_ptr == 'L' || *buf_ptr == 'l')
                {
                    buf_ptr++;
                }
            }
        }
        else
        {
            while (chartype[0xff & (int)*buf_ptr] == alphanum)
            {
                /* Copy it over. */
                buf_ptr++;
                if (buf_ptr >= buf_end)
                {
                    fill_buffer();
                }
            }
        }
        token_end = buf_ptr;
        if (token_end - token == 13 && !strncmp(token, "__attribute__", 13))
        {
            last_code                  = decl;
            parser_state_tos->last_u_d = true;
            return (attribute);
        }
        /* Adjusts 'buf_ptr'. */
        skip_buffered_space();
        /* Handle operator declarations. */
        if (token_end - token == 8 && !strncmp(token, "operator", 8))
        {
            while (chartype[0xff & (int)*buf_ptr] == opchar)
            {
                buf_ptr++;
                if (buf_ptr >= buf_end)
                {
                    fill_buffer();
                }
            }
            token_end = buf_ptr;
            /* adjusts buf_ptr */
            skip_buffered_space();
        }
        parser_state_tos->its_a_keyword  = false;
        parser_state_tos->sizeof_keyword = false;
        /* if last token was 'struct', then this token should be treated as a declaration */
        if (l_struct)
        {
            l_struct                   = false;
            last_code                  = ident;
            parser_state_tos->last_u_d = true;
            if (parser_state_tos->last_token == cpp_operator)
            {
                return overloaded;
            }
            return (decl);
        }
        /* Operator after indentifier is binary */
        parser_state_tos->last_u_d = false;
        last_code                  = ident;
        /* Check whether the token is a reserved word.  Use perfect hashing... */
        if (settings.c_plus_plus)
        {
            p = is_reserved_cc(token, token_end - token);
        }
        else
        {
            p = is_reserved(token, token_end - token);
        }
        if ((p == NULL) && (user_specials != 0))
        {
            for (p = &user_specials[0]; p < &user_specials[0] + user_specials_idx; p++)
            {
                char *q = token;
                char *r = p->rwd;
                /**
                 * This string compare is a little nonstandard because token
                 * ends at the character before token_end and p->rwd is
                 * null-terminated.
                 */
                while (1)
                {
                    /**
                     * If we have come to the end of both the keyword in
                     * user_specials and the keyword in token they are equal.
                     */
                    if (q >= token_end && !*r)
                    {
                        goto found_keyword;
                    }
                    /* If we have come to the end of just one, they are not equal. */
                    if (q >= token_end || !*r)
                    {
                        break;
                    }
                    /* If the characters in corresponding characters are not
                     * equal, the strings are not equal.  */
                    if (*q++ != *r++)
                    {
                        break;
                    }
                }
            }
            /* Didn't find anything in user_specials. */
            p = NULL;
        }
    found_keyword:
        if (p)
        {
            /* we have a keyword */
            codes_t value;
            value                           = ident;
            parser_state_tos->its_a_keyword = true;
            parser_state_tos->last_u_d      = true;
            parser_state_tos->last_rw       = p->rwcode;
            parser_state_tos->last_rw_depth = parser_state_tos->paren_depth;
            switch (p->rwcode)
            {
                /* C++ operator overloading. */
                case rw_operator :
                    value                                      = cpp_operator;
                    parser_state_tos->in_parameter_declaration = 1;
                    break;
                /* it is a switch */
                case rw_switch :
                    value = (swstmt);
                    break;
                /* a case or default */
                case rw_case :
                    value = (casestmt);
                    break;
                case rw_enum :
                    l_enum = true; /* reset on '(' ')' '{' '}' or ';' */
                                   /* fall through */
                /* a "struct" */
                case rw_struct_like :
                    if (parser_state_tos->p_l_follow &&
                        !(parser_state_tos->noncast_mask & 1 << parser_state_tos->p_l_follow))
                    /* inside parens: cast */
                    {
                        parser_state_tos->cast_mask |= 1 << parser_state_tos->p_l_follow;
                        break;
                    }
                    l_struct = true;
                    /* fall through */
                    /* Next time around, we will want to know that we have had a 'struct' */
                /* one of the declaration keywords */
                case rw_decl :
                    if (parser_state_tos->p_l_follow &&
                        !(parser_state_tos->noncast_mask & 1 << parser_state_tos->p_l_follow))
                    /* inside parens: cast */
                    {
                        parser_state_tos->cast_mask |= 1 << parser_state_tos->p_l_follow;
                        break;
                    }
                    last_code = decl;
                    value     = (decl);
                    break;

                /* if, while, for */
                case rw_sp_paren :
                    value = (sp_paren);
                    if (*token == 'i' && parser_state_tos->last_token == sp_else)
                    {
                        parser_state_tos->i_l_follow -= settings.ind_size;
                    }
                    break;

                /* do */
                case rw_sp_nparen :
                    value = (sp_nparen);
                    break;

                /* else */
                case rw_sp_else :
                    value = (sp_else);
                    break;

                case rw_sizeof :
                    parser_state_tos->sizeof_keyword = true;
                    value                            = (ident);
                    break;

                case rw_return :
                case rw_break :
                /* all others are treated like any other identifier */
                default :
                    value = (ident);
            }
            /* end of switch */
            if (parser_state_tos->last_token == cpp_operator)
            {
                return overloaded;
            }
            return value;
        }
        /* end of if (found_it) */
        else if ((*buf_ptr == '(') && (parser_state_tos->tos <= 1) && (parser_state_tos->ind_level == 0) &&
                 (parser_state_tos->paren_depth == 0))
        {
            /* We have found something which might be the name in a function definition. */
            char *tp;
            int   paren_count = 1;
            /**
             * If the return type of this function definition was not defined
             * with a -T commandline option, then the output of indent would
             * alternate on subsequent calls.  In order to avoid that we try
             * to detect that case here and make a minimal change to cause
             * the correct behaviour.
             */
            if (parser_state_tos->last_token == ident && parser_state_tos->last_saw_nl)
            {
                parser_state_tos->in_decl = true;
            }
            /* Skip to the matching ')'.  */
            for (tp = buf_ptr + 1; (paren_count > 0) && (tp < in_prog + in_prog_size); tp++)
            {
                if (buf_ptr >= buf_end)
                {
                    fill_buffer();
                }
                if (had_eof)
                {
                    goto not_proc;
                }
                if (*tp == '(')
                {
                    paren_count++;
                }
                if (*tp == ')')
                {
                    paren_count--;
                }
                /* Can't occur in parameter list; this way we don't search the
                 * whole file in the case of unbalanced parens.  */
                if (*tp == ';')
                {
                    goto not_proc;
                }
            }
            if (paren_count == 0)
            {
                parser_state_tos->procname     = token;
                parser_state_tos->procname_end = token_end;
                while (isspace(*tp))
                {
                    tp++;
                }
                if ((*tp == '_') && (in_prog + in_prog_size - tp >= 13) && !strncmp(tp, "__attribute__", 13))
                {
                    /* Found an __attribute__ after a function declaration */
                    /* Must be a declaration */
                }
                else
                {
                    /**
                     * If the next char is ';' or ',' or '(' we have a function
                     * declaration, not a definition.
                     *
                     * I've added '=' to this list to keep from breaking
                     * a non-valid C macro from libc.  -jla
                     */
                    if (*tp != ';' && *tp != ',' && *tp != '(' && *tp != '=')
                    {
                        parser_state_tos->in_parameter_declaration = 1;
                    }
                }
            }
        }
        else if ((*buf_ptr == ':') && (*(buf_ptr + 1) == ':') && (parser_state_tos->tos <= 1) &&
                 (parser_state_tos->ind_level == 0) && (parser_state_tos->paren_depth == 0))
        {
            parser_state_tos->classname     = token;
            parser_state_tos->classname_end = token_end;
        }
        /**
         * The following hack attempts to guess whether or not the
         * current token is in fact a declaration keyword -- one that
         * has been typedef'd
         */
        else if ((((*buf_ptr == '*') && (buf_ptr[1] != '=')) || isalpha(*buf_ptr) || (*buf_ptr == '_')) &&
                 !parser_state_tos->p_l_follow && !parser_state_tos->block_init &&
                 ((parser_state_tos->last_token == rparen) || (parser_state_tos->last_token == semicolon) ||
                  (parser_state_tos->last_token == rbrace) || (parser_state_tos->last_token == decl) ||
                  (parser_state_tos->last_token == lbrace) || (parser_state_tos->last_token == start_token)))
        {
            parser_state_tos->its_a_keyword = true;
            parser_state_tos->last_u_d      = true;
            last_code                       = decl;
            if (parser_state_tos->last_token == cpp_operator)
            {
                return overloaded;
            }
            return decl;
        }
        else
        {
            /* what ? */
        }
    /* Escape from loop checking for procedure name in if statement above. */
    not_proc:
        last_code = ident;
        if (parser_state_tos->last_token == cpp_operator)
        {
            return overloaded;
        }
        /* the ident is not in the list */
        return (ident);
    }
    /* end of procesing for alpanum character */
    /* Scan a non-alphanumeric token */
    /* If it is not a one character token, token_end will get changed later.  */
    token_end = buf_ptr + 1;
    /**
     * THIS MAY KILL YOU!!!
     *
     * Note that it may be possible for this to kill us--if `fill_buffer'
     * at any time switches `buf_ptr' to the other input buffer, `token'
     * and `token_end' will point to different storage areas!!!
     */
    if (++buf_ptr >= buf_end)
    {
        fill_buffer();
    }
    /* If it is a backslash new-line, just eat the backslash */
    if ((*token == '\\') && (buf_ptr[0] == EOL))
    {
        token = buf_ptr;
        if (++buf_ptr >= buf_end)
        {
            fill_buffer();
        }
    }
    switch (*token)
    {
        case '\0' :
            code = code_eof;
            break;

        case EOL :
            parser_state_tos->matching_brace_on_same_line = -1;
            unary_delim                                   = parser_state_tos->last_u_d;
            parser_state_tos->last_nl                     = true;
            code                                          = newline;
            break;

        /* Handle gettext strings. */
        case '_' :
            if (!settings.gettext_strings || buf_ptr[0] != '(' || buf_ptr[1] != '"')
            {
                token_end = buf_ptr;
                code      = ident;
                break;
            }
            qchar = buf_ptr[1];
            buf_ptr++;
            buf_ptr++;
            goto handle_string;

        /* Handle gettext noop strings. */
        case 'N' :
            if (!settings.gettext_strings || buf_ptr[0] != '_' || buf_ptr[1] != '(' || buf_ptr[2] != '"')
            {
                token_end = buf_ptr;
                code      = ident;
                break;
            }
            qchar = buf_ptr[2];
            buf_ptr++;
            buf_ptr++;
            buf_ptr++;
            goto handle_string;

            /* Handle wide strings and chars. */
        case 'L' :
            if (buf_ptr[0] != '"' && buf_ptr[0] != '\'')
            {
                token_end = buf_ptr;
                code      = ident;
                break;
            }
            qchar = buf_ptr[0];
            buf_ptr++;
            goto handle_string;

        case '\'' : /* start of quoted character */
        case '"' :  /* start of string */
            qchar = *token;

        handle_string:
            /* Find out how big the literal is so we can set token_end.  */
            /* Invariant:  before loop test buf_ptr points to the next
             * character that we have not yet checked. */
            while ((*buf_ptr != qchar) && (*buf_ptr != 0)) /* && *buf_ptr != EOL) */
            {
                if (*buf_ptr == EOL)
                {
                    ++line_no;
                }
                if (*buf_ptr == '\\')
                {
                    buf_ptr++;
                    if (buf_ptr >= buf_end)
                    {
                        fill_buffer();
                    }

                    if (*buf_ptr == EOL)
                    {
                        ++line_no;
                    }

                    if (*buf_ptr == 0)
                    {
                        break;
                    }
                }

                buf_ptr++;

                if (buf_ptr >= buf_end)
                {
                    fill_buffer();
                }
            }

            if (*buf_ptr == EOL || *buf_ptr == 0)
            {
                WARNING((qchar == '\'' ? "Unterminated character constant" : "Unterminated string constant"),
                        NULL, NULL);
            }
            else
            {
                /* Advance over end quote char.  */
                buf_ptr++;

                if (buf_ptr >= buf_end)
                {
                    fill_buffer();
                }
            }

            if (settings.gettext_strings && (token[0] == '_' || (token[0] == 'N' && token[1] == '_')))
            {
                /* In the gettext situation, the string ends with ") */
                if (*buf_ptr != ')')
                {
                    WARNING("Unterminated string constant", NULL, NULL);
                }
                else
                {
                    /* Advance over closing paren.  */
                    buf_ptr++;
                    if (buf_ptr >= buf_end)
                    {
                        fill_buffer();
                    }
                }
            }
            token_end = buf_ptr;
            code      = ident;
            break;

        case '(' :
            l_enum      = false;
            unary_delim = true;
            code        = lparen;
            break;

        case '[' :
            if (parser_state_tos->in_or_st)
            {
                parser_state_tos->in_or_st++;
            }

            unary_delim = true;
            code        = lparen;
            break;

        case ')' :
            l_enum = false;
            code   = rparen;
            break;

        case ']' :
            if (parser_state_tos->in_or_st > 1)
            {
                parser_state_tos->in_or_st--;
            }

            code = rparen;
            break;

        case '#' :
            unary_delim = parser_state_tos->last_u_d;
            code        = preesc;

            /* Make spaces between '#' and the directive be part of
             * the token if user specified "-lps" */
            while (*buf_ptr == ' ' && buf_ptr < buf_end)
            {
                buf_ptr++;
            }

            if (settings.leave_preproc_space)
            {
                token_end = buf_ptr;
            }
            break;

        case '?' :
            unary_delim = true;
            code        = question;
            break;

        case ':' :
            /* Deal with C++ class::method */

            if (*buf_ptr == ':')
            {
                code = doublecolon;
                buf_ptr++;
                token_end = buf_ptr;
                break;
            }

            code        = colon;
            unary_delim = true;
            if (squest && *e_com != ' ')
            {
                if (e_code == s_code)
                {
                    parser_state_tos->want_blank = false;
                }

                else
                {
                    parser_state_tos->want_blank = true;
                }
            }
            break;

        case ';' :
            l_enum      = false;
            unary_delim = true;
            code        = semicolon;
            break;

        case '{' :
            if (parser_state_tos->matching_brace_on_same_line < 0)
            {
                parser_state_tos->matching_brace_on_same_line = 1;
            }
            else
            {
                parser_state_tos->matching_brace_on_same_line++;
            }

            if (l_enum)
            {
                /* Keep all variables in the same column:
                 *   ONE,
                 *   TWO, etc
                 * instead of
                 *   ONE,
                 *     TWO,
                 * Use a special code for `block_init' however, because we still
                 * want to do the line breaks when `settings.braces_on_struct_decl_line'
                 * is not set.
                 */
                parser_state_tos->block_init       = 2;
                parser_state_tos->block_init_level = 0;
                l_enum                             = false;
            }

            unary_delim = true;
            code        = lbrace;
            break;

        case '}' :
            parser_state_tos->matching_brace_on_same_line--;
            l_enum      = false;
            unary_delim = true;
            code        = rbrace;
            break;

        case 014 :                            /* a form feed */
            unary_delim               = parser_state_tos->last_u_d;
            parser_state_tos->last_nl = true; /* remember this so we can set
                                                 'parser_state_tos->col_1' right */
            code = form_feed;
            break;

        case ',' :
            unary_delim = true;
            code        = comma;
            break;

        case '.' :
            if ((buf_ptr[0] == '.') && (buf_ptr[1] == '.'))
            {
                /* '...' */

                if ((buf_ptr += 2) >= buf_end)
                {
                    fill_buffer();
                }

                unary_delim = true;
                token_end   = buf_ptr;

                if (parser_state_tos->in_decl)
                {
                    /* '...' in a declaration */
                    code = decl;
                }
                else
                {
                    code = binary_op;
                }
            }
            else
            {
                unary_delim = false;
                code        = struct_delim;

                if (*buf_ptr == '*') /* object .* pointer-to-member */
                {
                    ++buf_ptr;
                    token_end = buf_ptr;
                }
            }
            break;

        case '-' :
        case '+' : /* check for -, +, --, ++ */
            code        = (parser_state_tos->last_u_d ? unary_op : binary_op);
            unary_delim = true;

            if (*buf_ptr == token[0])
            {
                /* check for doubled character */
                buf_ptr++;
                /* buffer overflow will be checked at end of loop */
                if (last_code == ident || last_code == rparen)
                {
                    code = (parser_state_tos->last_u_d ? unary_op : postop);
                    /* check for following ++ or -- */
                    unary_delim = false;
                }
            }
            else if (*buf_ptr == '=')
            {
                /* check for operator += */
                buf_ptr++;
            }
            else if (*buf_ptr == '>')
            {
                /* check for operator -> */
                buf_ptr++;
                code = struct_delim;
                /* check for operator ->* */

                if (*buf_ptr == '*')
                {
                    buf_ptr++;
                }
            }
            else
            {
                /* what ? */
            }

            token_end = buf_ptr;
            break; /* buffer overflow will be checked at end of
                      switch */

        case '=' :
            if (parser_state_tos->in_or_st && (parser_state_tos->last_token != cpp_operator))
            {
                parser_state_tos->block_init       = 1;
                parser_state_tos->block_init_level = 0;
            }

            if (*buf_ptr == '=') /* == */
            {
                buf_ptr++;
            }
            else if ((*buf_ptr == '-') || (*buf_ptr == '+') || (*buf_ptr == '*') || (*buf_ptr == '&'))
            {
                /* Something like x=-1, which can mean x -= 1 ("old style" in K&R1)
                 * or x = -1 (ANSI).  Note that this is only an ambiguity if the
                 * character can also be a unary operator.  If not, just produce
                 * output code that produces a syntax error (the theory being that
                 * people want to detect and eliminate old style assignments but
                 * they don't want indent to silently change the meaning of their
                 * code).  */
                tmpchar[0] = *buf_ptr;
                tmpchar[1] = '\0';
                WARNING("old style assignment ambiguity in \"=%s\". "
                          "Assuming \"= %s\"\n",
                        tmpchar, tmpchar);
            }
            else
            {
                /* what ? */
            }

            code        = binary_op;
            unary_delim = true;
            token_end   = buf_ptr;
            break;
            /* can drop thru!!! */

        case '>' :
        case '<' :
        case '!' :
            /* ops like <, <<, <=, !=, <<=, etc */
            /* This will of course scan sequences like "<=>", "!=>", "<<>", etc. as
             * one token, but I don't think that will cause any harm.  */
            /* in C++ mode also scan <?[=], >?[=] GNU C++ operators
             * maybe some flag to them ? */

            while (*buf_ptr == '>' || *buf_ptr == '<' || *buf_ptr == '=' || (settings.c_plus_plus && *buf_ptr == '?'))
            {
                if (++buf_ptr >= buf_end)
                {
                    fill_buffer();
                }

                if (*buf_ptr == '=')
                {
                    if (++buf_ptr >= buf_end)
                    {
                        fill_buffer();
                    }
                }
            }

            code        = (parser_state_tos->last_u_d ? unary_op : binary_op);
            unary_delim = true;
            token_end   = buf_ptr;
            break;

        default :
            if (token[0] == '/' && (*buf_ptr == '*' || *buf_ptr == '/'))
            {
                /* A C or C++ comment */

                if (*buf_ptr == '*')
                {
                    code = comment;
                }
                else
                {
                    code = cplus_comment;
                }

                if (++buf_ptr >= buf_end)
                {
                    fill_buffer();
                }

                if (code == comment)
                {
                    /* Threat comments of type / *UPPERCASE* / not as comments */
                    char *p = buf_ptr;

                    while (isupper(*p++))
                    {
                        /* There is always at least one
                         * newline in the buffer; so no
                         * need to check for buf_end. */
                    }

                    if (p < buf_end && p[-1] == '*' && *p == '/')
                    {
                        buf_ptr                      = p + 1;
                        code                         = ident;
                        parser_state_tos->want_blank = true;
                    }
                }

                unary_delim = parser_state_tos->last_u_d;
            }
            else if (parser_state_tos->last_token == cpp_operator)
            {
                /* For C++ overloaded operators. */
                code      = overloaded;
                last_code = overloaded;
            }
            else
            {
                while (*(buf_ptr - 1) == *buf_ptr || *buf_ptr == '=')
                {
                    /* handle ||, &&, etc, and also things as in int *****i */
                    if (++buf_ptr >= buf_end)
                    {
                        fill_buffer();
                    }
                }
                code        = (parser_state_tos->last_u_d ? unary_op : binary_op);
                unary_delim = true;
            }
            token_end = buf_ptr;
    }
    /* end of switch */
    if (code != newline)
    {
        l_struct  = false;
        last_code = code;
    }
    if (buf_ptr >= buf_end)
    {
        fill_buffer();
    }
    parser_state_tos->last_u_d = unary_delim;
    if (parser_state_tos->last_token == cpp_operator)
    {
        return overloaded;
    }
    return (code);
}

/**
 * Add the given keyword to the keyword table, using val as the keyword type
 */
extern void
addkey(char *key, rwcodes_t val)
{
    templ_t *p;
    /* Check to see whether key is a reserved word or not. */
    if ((settings.c_plus_plus && is_reserved_cc(key, strlen(key)) != 0) ||
        (!settings.c_plus_plus && is_reserved(key, strlen(key)) != 0))
    {}
    else
    {
        if (user_specials == 0)
        {
            user_specials     = xmalloc(5 * sizeof(templ_t));
            user_specials_max = 5;
            user_specials_idx = 0;
        }
        else if (user_specials_idx == user_specials_max)
        {
            user_specials_max += 5;
            user_specials = xrealloc(user_specials, user_specials_max * sizeof(templ_t));
        }
        else
        {
            /* what ? */
        }
        p         = &user_specials[user_specials_idx++];
        p->rwd    = key;
        p->rwcode = val;
    }
}

extern void
cleanup_user_specials(void)
{
    if (user_specials)
    {
        while (--user_specials_idx > 0)
        {
            xfree(user_specials[user_specials_idx].rwd);
        }
        xfree(user_specials[0].rwd);
        xfree(user_specials);
    }
}
