#include "../include/prototypes.h"

/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -D -c -l -p -t -T -g -j1 -o -K rwd -L ANSI-C -N is_reserved_cc -H hash_cc indent-cc.gperf  */
/* Computed positions: -k'1,3' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) &&        \
      (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) &&         \
      ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) &&         \
      ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) &&         \
      ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) &&         \
      ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) &&         \
      ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) &&         \
      ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) &&        \
      ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) &&  \
      ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) && \
      ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) && \
      ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#    error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif

#define TOTAL_KEYWORDS  48
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 9
#define MIN_HASH_VALUE  3
#define MAX_HASH_VALUE  57
/* maximum key range = 55, duplicates = 0 */

#if defined(__GNUC__) && !defined(__clang__)
__inline
#else
#    ifdef __cplusplus
inline
#    endif
#endif
    static unsigned int
    hash_cc(const char *str, size_t len)
{
    static unsigned char asso_values[] = {
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 10,
        58, 10, 28, 11, 25, 15, 25, 5,  30, 1,  58, 58, 5,  37, 22, 12, 34, 58, 2,  3,  0,  18, 34, 27, 58, 58, 25, 58, 58, 58, 58, 58,
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58,
        58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58, 58};
    unsigned int hval = len;
    switch (hval)
    {
        default :
            hval += asso_values[(unsigned char)str[2]];
        /*FALLTHROUGH*/
        case 2 :
        case 1 :
            hval += asso_values[(unsigned char)str[0]];
            break;
    }
    return hval;
}

templ_t *
is_reserved_cc(const char *str, size_t len)
{
    static unsigned char lengthtable[] = {2, 3, 5, 6, 4, 6, 6, 6, 5, 6, 8, 5, 9, 4, 6, 5, 6, 4, 6, 5, 4, 5, 2, 7,
                                          8, 3, 4, 6, 5, 6, 8, 6, 4, 5, 4, 6, 7, 5, 7, 4, 8, 6, 8, 5, 6, 6, 3, 7};
    /* clang-format off */
    static templ_t      wordlist[]    = {
#line 29 "indent-cc.gperf"
        {(char *)"if",    rw_sp_paren,},
#line 10 "indent-cc.gperf"
        {(char *)"int",        rw_decl,},
#line 39 "indent-cc.gperf"
        {(char *)"throw",      rw_return,},
#line 28 "indent-cc.gperf"
        {(char *)"return",      rw_return,},
#line 27 "indent-cc.gperf"
        {(char *)"goto",       rw_break,},
#line 3 "indent-cc.gperf"
        {(char *)"switch",      rw_switch,},
#line 6 "indent-cc.gperf"
        {(char *)"struct", rw_struct_like,},
#line 41 "indent-cc.gperf"
        {(char *)"inline",        rw_decl,},
#line 48 "indent-cc.gperf"
        {(char *)"sigof",      rw_sizeof,},
#line 19 "indent-cc.gperf"
        {(char *)"signed",        rw_decl,},
#line 20 "indent-cc.gperf"
        {(char *)"",        rw_decl,},
#line 35 "indent-cc.gperf"
        {(char *)"catch",    rw_sp_paren,},
#line 44 "indent-cc.gperf"
        {(char *)"signature", rw_struct_like,},
#line 4 "indent-cc.gperf"
        {(char *)"case",        rw_case,},
#line 21 "indent-cc.gperf"
        {(char *)"static",        rw_decl,},
#line 16 "indent-cc.gperf"
        {(char *)"short",        rw_decl,},
#line 23 "indent-cc.gperf"
        {(char *)"extern",        rw_decl,},
#line 32 "indent-cc.gperf"
        {(char *)"else",     rw_sp_else,},
#line 22 "indent-cc.gperf"
        {(char *)"global",        rw_decl,},
#line 7 "indent-cc.gperf"
        {(char *)"union", rw_struct_like,},
#line 11 "indent-cc.gperf"
        {(char *)"char",        rw_decl,},
#line 36 "indent-cc.gperf"
        {(char *)"class", rw_struct_like,},
#line 33 "indent-cc.gperf"
        {(char *)"do",   rw_sp_nparen,},
#line 46 "indent-cc.gperf"
        {(char *)"classof",      rw_sizeof,},
#line 18 "indent-cc.gperf"
        {(char *)"unsigned",        rw_decl,},
#line 31 "indent-cc.gperf"
        {(char *)"for",    rw_sp_paren,},
#line 15 "indent-cc.gperf"
        {(char *)"long",        rw_decl,},
#line 40 "indent-cc.gperf"
        {(char *)"friend",        rw_decl,},
#line 30 "indent-cc.gperf"
        {(char *)"while",    rw_sp_paren,},
#line 34 "indent-cc.gperf"
        {(char *)"sizeof",      rw_sizeof,},
#line 50 "indent-cc.gperf"
        {(char *)"operator",    rw_operator,},
#line 37 "indent-cc.gperf"
        {(char *)"delete",      rw_return,},
#line 8 "indent-cc.gperf"
        {(char *)"enum",        rw_enum,},
#line 12 "indent-cc.gperf"
        {(char *)"const",        rw_decl,},
#line 24 "indent-cc.gperf"
        {(char *)"void",        rw_decl,},
#line 45 "indent-cc.gperf"
        {(char *)"typeof",      rw_sizeof,},
#line 17 "indent-cc.gperf"
        {(char *)"typedef",        rw_decl,},
#line 13 "indent-cc.gperf"
        {(char *)"float",        rw_decl,},
#line 43 "indent-cc.gperf"
        {(char *)"virtual",        rw_decl,},
#line 49 "indent-cc.gperf"
        {(char *)"bool",        rw_decl,},
#line 42 "indent-cc.gperf"
        {(char *)"template",        rw_decl,},
#line 47 "indent-cc.gperf"
        {(char *)"headof",      rw_sizeof,},
#line 25 "indent-cc.gperf"
        {(char *)"volatile",        rw_decl,},
#line 5 "indent-cc.gperf"
        {(char *)"break",       rw_break,},
#line 14 "indent-cc.gperf"
        {(char *)"double",        rw_decl,},
#line 26 "indent-cc.gperf"
        {(char *)"va_dcl",        rw_decl,},
#line 38 "indent-cc.gperf"
        {(char *)"new",      rw_return,},
#line 9 "indent-cc.gperf"
        {(char *)"default",        rw_case,}
    };
    /* clang-format on */
    static signed char lookup[] = {-1, -1, -1, 0,  1,  -1, -1, 2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14,
                                   15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
                                   35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, -1, 46, -1, -1, -1, -1, 47};
    if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
        unsigned int key = hash_cc(str, len);
        if (key <= MAX_HASH_VALUE)
        {
            int idx = lookup[key];
            if (idx >= 0)
            {
                if (len == lengthtable[idx])
                {
                    const char *s = wordlist[idx].rwd;
                    if (*str == *s && !memcmp(str + 1, s + 1, len - 1))
                    {
                        return &wordlist[idx];
                    }
                }
            }
        }
    }
    return 0;
}
