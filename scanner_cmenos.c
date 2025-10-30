#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TOKEN_LEN 40

/* ---------------------------------------------------------
 * Definição dos tipos de token da linguagem C-
 * --------------------------------------------------------- */
typedef enum {
    /* Palavras reservadas */
    IF, ELSE, INT, RETURN, VOID, WHILE,

    /* Identificadores e números */
    ID, NUM,

    /* Operadores */
    PLUS, MINUS, TIMES, OVER,
    LT, LE, GT, GE, EQ, NE,
    ASSIGN,

    /* Símbolos especiais */
    SEMI, COMMA, LPAREN, RPAREN,
    LBRACK, RBRACK, LBRACE, RBRACE,

    /* Outros */
    ENDFILE, ERROR
} TokenType;

/* ---------------------------------------------------------
 * Palavras-chave da linguagem C-
 * --------------------------------------------------------- */
char *reservedWords[] = {
    "if", "else", "int", "return", "void", "while"
};

/* ---------------------------------------------------------
 * Retorna se o lexema é palavra-chave ou identificador
 * --------------------------------------------------------- */
TokenType reservedLookup(const char *s) {
    for (int i = 0; i < 6; i++)
        if (!strcmp(s, reservedWords[i])) return (TokenType)i;
    return ID;
}

/* ---------------------------------------------------------
 * Função que retorna o próximo token lido
 * --------------------------------------------------------- */
TokenType getToken(FILE *source, char *tokenString) {
    int tokenStringIndex = 0;
    int c;

    /* Ignorar espaços, tabs e quebras de linha */
    while ((c = fgetc(source)) != EOF && isspace(c));

    if (c == EOF)
        return ENDFILE;

    /* Identificador ou palavra-chave */
    if (isalpha(c)) {
        do {
            tokenString[tokenStringIndex++] = c;
            c = fgetc(source);
        } while (isalnum(c));
        ungetc(c, source);
        tokenString[tokenStringIndex] = '\0';
        return reservedLookup(tokenString);
    }

    /* Número */
    else if (isdigit(c)) {
        do {
            tokenString[tokenStringIndex++] = c;
            c = fgetc(source);
        } while (isdigit(c));
        ungetc(c, source);
        tokenString[tokenStringIndex] = '\0';
        return NUM;
    }

    /* Comentários e operadores */
    else {
        tokenString[tokenStringIndex++] = c;
        tokenString[tokenStringIndex] = '\0';

        switch (c) {
            case '+': return PLUS;
            case '-': return MINUS;
            case '*': return TIMES;
            case '/': {
                c = fgetc(source);
                if (c == '/') { // comentário de linha
                    while ((c = fgetc(source)) != EOF && c != '\n');
                    return getToken(source, tokenString);
                } else if (c == '*') { // comentário de bloco
                    int prev = 0;
                    while ((c = fgetc(source)) != EOF) {
                        if (prev == '*' && c == '/') break;
                        prev = c;
                    }
                    return getToken(source, tokenString);
                } else {
                    ungetc(c, source);
                    return OVER;
                }
            }
            case '<':
                c = fgetc(source);
                if (c == '=') { strcpy(tokenString, "<="); return LE; }
                else { ungetc(c, source); return LT; }
            case '>':
                c = fgetc(source);
                if (c == '=') { strcpy(tokenString, ">="); return GE; }
                else { ungetc(c, source); return GT; }
            case '=':
                c = fgetc(source);
                if (c == '=') { strcpy(tokenString, "=="); return EQ; }
                else { ungetc(c, source); return ASSIGN; }
            case '!':
                c = fgetc(source);
                if (c == '=') { strcpy(tokenString, "!="); return NE; }
                else return ERROR;
            case ';': return SEMI;
            case ',': return COMMA;
            case '(': return LPAREN;
            case ')': return RPAREN;
            case '[': return LBRACK;
            case ']': return RBRACK;
            case '{': return LBRACE;
            case '}': return RBRACE;
            default:  return ERROR;
        }
    }
}

/* ---------------------------------------------------------
 * Retorna o nome textual do token
 * --------------------------------------------------------- */
char *tokenTypeName(TokenType t) {
    switch (t) {
        case IF: return "IF";
        case ELSE: return "ELSE";
        case INT: return "INT";
        case RETURN: return "RETURN";
        case VOID: return "VOID";
        case WHILE: return "WHILE";
        case ID: return "IDENTIFIER";
        case NUM: return "NUMBER";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case TIMES: return "TIMES";
        case OVER: return "DIVIDE";
        case LT: return "LESS";
        case LE: return "LESS_EQUAL";
        case GT: return "GREATER";
        case GE: return "GREATER_EQUAL";
        case EQ: return "EQUAL";
        case NE: return "NOT_EQUAL";
        case ASSIGN: return "ASSIGN";
        case SEMI: return "SEMICOLON";
        case COMMA: return "COMMA";
        case LPAREN: return "LEFT_PAREN";
        case RPAREN: return "RIGHT_PAREN";
        case LBRACK: return "LEFT_BRACKET";
        case RBRACK: return "RIGHT_BRACKET";
        case LBRACE: return "LEFT_BRACE";
        case RBRACE: return "RIGHT_BRACE";
        case ENDFILE: return "EOF";
        default: return "ERROR";
    }
}

/* ---------------------------------------------------------
 * Programa principal
 * --------------------------------------------------------- */
int main() {
    FILE *source = fopen("codigo.cminus", "r");
    if (!source) {
        printf("Erro: não foi possível abrir o arquivo 'codigo.cminus'.\n");
        return 1;
    }

    char tokenString[MAX_TOKEN_LEN];
    TokenType token;

    printf("===== Sistema de Varredura para C- =====\n\n");

    do {
        token = getToken(source, tokenString);
        printf("Tipo de Marca: %-15s | Cadeia: %s\n",
               tokenTypeName(token), tokenString);
    } while (token != ENDFILE);

    fclose(source);
    printf("\n===== Fim da Analise Lexica =====\n");
    return 0;
}
