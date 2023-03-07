#include <iostream>
#include <string.h>
using namespace std;
/* Global declarations */
/* Variables */
int charClass;
char lexeme[1000];
char nextChar;
int lexLen;
int token;
int nextToken;
FILE *in_fp, *fopen();
FILE *out_fp, *fopenout();
/* Function declarations */
void addChar();
void getChar();
void getNonBlank();
int lex();
/* Character classes */
#define LETTER 93
#define DIGIT 94
#define UNKNOWN 99
// #define EOF 97
/* Token codes */
#define INT_LIT 95
#define IDENT 96

#define ADD 40
#define ADDI 41
#define AND 42
#define ANDI 43
#define OR 44
#define ORI 45
#define SUB 46
#define SLL 47
#define SLT 48
#define SRA 49
#define SRL 50
#define XOR 51
#define LB 52
#define LH 53
#define LW 54
#define JAL 55
#define JALR 56
#define SB 57
#define SW 58
#define SH 59
#define BEQ 60
#define BNE 61
#define BGE 62
#define BLT 63
#define AUIPC 64
#define LUI 65

#define ST0 10
#define ST1 11
#define ST2 12
#define ST3 13
#define ST4 14
#define ST5 15
#define ST6 16
#define ST7 17
#define ST8 18
#define ST9 19
#define ST10 20
#define ST11 21
#define ST12 22
#define ST13 23
#define ST14 24
#define ST15 25
#define ST16 26
#define ST17 27
#define ST18 28
#define ST19 29
#define ST20 30
#define ST21 31
#define ST22 32
#define ST23 33
#define ST24 34
#define ST25 35
#define ST26 36
#define ST27 37
#define ST28 38
#define ST29 39
#define ST30 40
#define ST31 41

#define COMMA_OP 70
#define LEFT_PAREN 71
#define RIGHT_PAREN 72
/******************************************************/
/* main driver */
main()
{
    out_fp = fopen("tokens.txt", "w");
    /* Open the input data file and process its contents */
    if ((in_fp = fopen("front.txt", "r")) == NULL)
        printf("ERROR - cannot open front.in \n");
    else
    {
        getChar();
        do
        {
            lex();
        } while (nextToken != EOF);
    }
}

/*****************************************************/
/* lookup - a function to lookup operators and parentheses
and return the token */
int lookup(char ch)
{
    switch (ch)
    {
    case '(':
        addChar();
        nextToken = LEFT_PAREN;
        break;
    case ')':
        addChar();
        nextToken = RIGHT_PAREN;
        break;
    default:
        addChar();
        nextToken = EOF;
        break;
    }
    return nextToken;
}
/*****************************************************/
/* addChar - a function to add nextChar to lexeme */
void addChar()
{
    if (lexLen <= 98)
    {
        lexeme[lexLen++] = nextChar;
        lexeme[lexLen] = 0;
    }
    else
        printf("Error - lexeme is too long \n");
}
/*****************************************************/
/* getChar - a function to get the next character of
input and determine its character class */
void getChar()
{
    if ((nextChar = getc(in_fp)) != EOF)
    {
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    }
    else
        charClass = EOF;
}

void identifyIns()
{
    if (lexeme[0] == 'a')
    {
        if (lexeme[1] == 'd')
        {
            if (lexeme[2] == 'd')
            {
                if (lexeme[3] == 'i')
                {
                    cout << "addi hia" << endl;
                    nextToken = ADDI;
                }
                else 
                {
                    cout << "add hai " << endl;
                    nextToken = ADD;
                }
            }
        }
        else if (lexeme[1] == 'n')
        {
            if (lexeme[2] == 'd')
            {
                if (lexeme[3] == 'i')
                {
                    cout << "andi hia" << endl;
                    nextToken = ANDI;
                }
                else 
                {
                    cout << "and hai " << endl;
                    nextToken = AND;
                }
            }
        }
        else if(lexeme[1]=='u'){
            if(lexeme[2]=='i'){
                if(lexeme[3]=='p'){
                    if(lexeme[4]=='c'){
                        cout<<"auipc hai"<<endl;
                        nextToken = AUIPC;
                    }
                }
            }
        }
    }

    else if (lexeme[0] == 'o')
    {
        if (lexeme[1] == 'r')
        {
            if (lexeme[2] == 'i')
            {
                cout << "ori hia" << endl;
                nextToken = ORI;
            }
            else 
            {
                cout << "or hai " << endl;
                nextToken = OR;
            }
        }
    }

    else if (lexeme[0] == 'x')
    {
        if (lexeme[1] == 'o')
        {
            if (lexeme[2] == 'r')
            {
                cout << "xor hia" << endl;
                nextToken = XOR;
            }

        }
    }

    else if (lexeme[0] == 's')
    {
        if (lexeme[1] == 'l')
        {
            if (lexeme[2] == 'l')
            {
                cout << "sll hia" << endl;
                nextToken = SLL;
            }
            else if (lexeme[2] == 't')
            {
                cout << "slt hai " << endl;
                nextToken = SLT;
            }
        }
        else if (lexeme[1] == 'r')
        {
            if (lexeme[2] == 'a')
            {
                cout << "sra hia" << endl;
                nextToken = SRA;
            }
            else if (lexeme[2] == 'l')
            {
                cout << "srl hai " << endl;
                nextToken = SRL;
            }
        }
        else if (lexeme[1] == 'u')
        {
            if (lexeme[2] == 'b')
            {
                cout << "sub hia" << endl;
                nextToken = SUB;
            }
        }
        else if (lexeme[1] == 'b')
        {
            cout<<"sb hai"<<endl;
            nextToken = SB;
        }
        else if (lexeme[1] == 'w')
        {
            cout<<"sw hai"<<endl;
            nextToken = SW;
        }
        else if (lexeme[1] == 'h')
        {
            cout<<"sh hai"<<endl;
            nextToken = SH;
        }
    }
    else if (lexeme[0] == 'b')
    {
        if (lexeme[1] == 'e')
        {
            if (lexeme[2] == 'q')
            {
                cout << "beq hia" << endl;
                nextToken = BEQ;
            }
        }
        else if (lexeme[1] == 'n')
        {
            if (lexeme[2] == 'e')
            {
                cout << "bne hia" << endl;
                nextToken = BNE;
            }
        }
        else if (lexeme[1] == 'g')
        {
            if (lexeme[2] == 'e')
            {
                cout << "bge hia" << endl;
                nextToken = BGE;
            }
        }
        else if (lexeme[1] == 'l')
        {
            if (lexeme[2] == 't')
            {
                cout << "blt hia" << endl;
                nextToken = BLT;
            }
        }
    }
    else if (lexeme[0] == 'l')
    {
        if (lexeme[1] == 'b')
        {
            cout<<"lb hai"<<endl;
            nextToken = LB;
        }
        else if (lexeme[1] == 'w')
        {
            cout<<"lw hai"<<endl;
            nextToken = LW;
        }
        else if (lexeme[1] == 'h')
        {
            cout<<"lh hai"<<endl;
            nextToken = LH;
        }
        else if (lexeme[1] == 'u')
        {
            if (lexeme[2] == 'i')
            {
                cout << "lui hia" << endl;
                nextToken = LUI;
            }
        }
    }
    if (lexeme[0] == 'j')
    {
        if (lexeme[1] == 'a')
        {
            if (lexeme[2] == 'l')
            {
                if (lexeme[3] == 'r')
                {
                    cout << "jalr hia" << endl;
                    nextToken = JALR;
                }
                else 
                {
                    cout << "jal hai " << endl;
                    nextToken = JAL;
                }
            }
        }
    }
    else if(lexeme[0]=='x'){
        if(lexeme[1]=='o'){
            if(lexeme[2]=='r'){
                cout << "xor hai " << endl;
                nextToken = XOR;
            }
        }
        else if(lexeme[1]=='0'){
            nextToken = ST0;
        }
        else if(lexeme[1]=='1'){
            
            if(lexeme[2]=='0'){
                nextToken = ST10;
            }
            else if(lexeme[2]=='1'){
                nextToken = ST11;
            }
            else if(lexeme[2]=='2'){
                nextToken = ST12;
            }
            else if(lexeme[2]=='3'){
                nextToken = ST13;
            }
            else if(lexeme[2]=='4'){
                nextToken = ST14;
            }
            else if(lexeme[2]=='5'){
                nextToken = ST15;
            }
            else if(lexeme[2]=='6'){
                nextToken = ST16;
            }
            else if(lexeme[2]=='7'){
                nextToken = ST17;
            }
            else if(lexeme[2]=='8'){
                nextToken = ST18;
            }
            else if(lexeme[2]=='9'){
                nextToken = ST19;
            }
            else{
                nextToken = ST1;
            }
        }
        else if(lexeme[1]=='2'){
            if(lexeme[2]=='0'){
                nextToken = ST20;
            }
            else if(lexeme[2]=='1'){
                nextToken = ST21;
            }
            else if(lexeme[2]=='2'){
                nextToken = ST22;
            }
            else if(lexeme[2]=='3'){
                nextToken = ST23;
            }
            else if(lexeme[2]=='4'){
                nextToken = ST24;
            }
            else if(lexeme[2]=='5'){
                nextToken = ST25;
            }
            else if(lexeme[2]=='6'){
                nextToken = ST26;
            }
            else if(lexeme[2]=='7'){
                nextToken = ST27;
            }
            else if(lexeme[2]=='8'){
                nextToken = ST28;
            }
            else if(lexeme[2]=='9'){
                nextToken = ST29;
            }
            else{
                nextToken = ST2;
            }
        }
        else if(lexeme[1]=='3'){
            if(lexeme[2]=='0'){
                nextToken = ST30;
            }
            else if(lexeme[2]=='1'){
                nextToken = ST31;
            }
            else{
                nextToken = ST3;
            }            
        }
        else if(lexeme[1]=='4'){
            nextToken = ST4;
        }
        else if(lexeme[1]=='5'){
            nextToken = ST5;
        }
        else if(lexeme[1]=='6'){
            nextToken = ST6;
        }
        else if(lexeme[1]=='7'){
            nextToken = ST7;
        }
        else if(lexeme[1]=='8'){
            nextToken = ST8;
        }
        else if(lexeme[1]=='9'){
            nextToken = ST9;
        }
        
    }

    
}

/*****************************************************/
/* getNonBlank - a function to call getChar until it
returns a non-whitespace character */
void getNonBlank()
{
    while (isspace(nextChar)|| nextChar==',')
        getChar();
}
/***************************************************** /
    /* lex - a simple lexical analyzer for arithmetic
    expressions */
int lex()
{
    lexLen = 0;
    getNonBlank();
    switch (charClass)
    {
        /* Parse identifiers */
    case LETTER:
        addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        identifyIns();
        break;
    /* Parse integer literals */
    case DIGIT:
        addChar();
        getChar();
        while (charClass == DIGIT)
        {
            addChar();
            getChar();
        }
        nextToken = INT_LIT;
        break;
    /* Parentheses and operators */
    case UNKNOWN:
        lookup(nextChar);
        getChar();
        break;
    /* EOF */
    case EOF:
        nextToken = EOF;
        lexeme[0] = 'E';
        lexeme[1] = 'O';
        lexeme[2] = 'F';
        lexeme[3] = 0;
        break;
    } /* End of switch */
    // out_fp = fopen("tokens.txt", "w");
    fprintf(out_fp, "%d", nextToken);
    printf("Next token is: %d, Next lexeme is %s\n", nextToken, lexeme);
    // cout<<"Next lex is"<<lexeme;
    return nextToken;
} /* End of function lex */