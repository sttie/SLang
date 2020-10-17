## What is this?

SLang is the result of my interest in the theory of formal languages. This is just a training project to gain experience in C++ development and to create a perfect programming language someday.

## Usage

You can use the executable file SLang and pass to it a name of a file with your SLang code:
```./Slang main.sl```

## Grammar

```
statements  := (statement | NEWLINE)* | e
statement   := func_or_simple | print_stmt | if_statement
	       | while_statement | return_statement | input_statement

func_or_simple := func_declaration | assignment_expr | expr

print_stmt      := "print" args
input_statement := "input" id

if_statement    := "if" "(" expr ")" NEWLINE*
                   "{" statements "}"

                   ("elif" "(" expr ")" NEWLINE*
                     "{" statements "}")*

                   [else "{" statements "}"]

while_statement := "while" "(" expr ")" NEWLINE*
                    "{" statements "}"

func_declaration := type id "(" func_parameters ")" NEWLINE*
                            "{" statements "}"
func_parameters := (type id ("," type id)*)*

return_statement := "return" expr

args := expr | ("," expr)*
assignment_expr := (type)? id "=" expr


expr         := logical_expr ("and" logical_expr)*
logical_expr := logical_term (("or" | "not") logical term)*
logical_term := compare_term (comparison compare_term)*
compare_term := add_term (("+" | "-") add_term)*
add_term     := mult_term (("*" | "/") mult_term)*

mult_term    := "(" expr ")"
                 | ("-" | "not") mult_term
                 | number
                 | id
                 | func_call
                 | literal
                 | "true"
                 | "false"

func_call       := id "(" args ")"
literal         := \"<any sequence of symbols>\"
comparison      := ">" | "<" | ">=" | "<=" | "==" | "!="
logic_operation := "and" | "or" | "not"
```

## Avaliable types

Only int, bool and string variables are available for now (look at the TODO list).

## Builtin functions

```toInt(v)``` - cast v to int

```toBool(v)``` - cast v to bool

```toString(v)``` - cast v to string

```at(str, i)``` - get the i-th symbol of the "str" string

## Examples of code
**example1.sl**
```
string get_hello() {
    string hello_str = "Hello"
    return hello_str
}

string get_world() {
    string world_str = "world"
    return world_str
}

print get_hello() + ", " + get_world() + "!"
```

**Output:**
```Hello, world!```


**example2.sl**
```
void print_true() {
    int i = 0
    while (i < 10) {
        if (i == 5) {
            print "middle: i =", i, "(but it is still the best language)"
        }
        else {
            print "the best language in the world (potentially)"
        }
        i = i + 1
    }
}

print_true()
```

**Output:**
```
the best language in the world (potentially) 
the best language in the world (potentially) 
the best language in the world (potentially) 
the best language in the world (potentially) 
the best language in the world (potentially) 
middle: i = 5 (but it is still the best language) 
the best language in the world (potentially) 
the best language in the world (potentially) 
the best language in the world (potentially) 
the best language in the world (potentially) 
the best language in the world (potentially)
```

**example3.sl**
```
int sum(int a, int b) {
    return a + b
}

string a = ""
string b = ""

print "Enter the first number:"
input a
print "Enter the second number:"
input b

print sum(toInt(a), toInt(b))
```

**Input:**
```
Enter the first number: 
42
Enter the second number: 
100
```

**Output:**
```
142
```

## TODO:
1. Real numbers and arrays support.

2. Implementation of error recovery in the parser in panic mode.

3. Reference types
