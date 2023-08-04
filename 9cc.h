#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// parse.c
//

// Tokenizer

typedef enum {
    TK_RESERVED,
    TK_NUM,
    TK_EOF,
} TokenKind;

typedef struct Token Token;
struct Token {
    TokenKind kind; // Token kind
    Token *next; // Next token
    int val; // If kind is TK_NUM, its value
    char *str; // Token string
    int len; // Token length
};

void error(char *fmt, ...);
Token *tokenize();

// Parser
typedef enum {
    ND_ADD, // +
    ND_SUB, // -
    ND_MUL, // *
    ND_DIV, // /
    ND_EQ, // ==
    ND_NE, // !=
    ND_LT, // <
    ND_LE, // <=
    ND_NUM, // Integer
} NodeKind;

// AST node type
typedef struct Node Node;
struct Node {
    NodeKind kind; // Node kind
    Node *lhs;     // Left-hand side
    Node *rhs;     // Right-hand side
    int val;       // Used if kind == ND_NUM
};

Node *expr();
Node *equality();
Node *relational();
Node *add();
Node *mul();
Node *unary();
Node *primary();

//
// codegen.c
//

void codegen(Node *node);