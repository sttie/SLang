## What is this?

SLang is the result of my interest in the theory of formal languages. This is just a training project to gain experience in C++ development and to create a perfect programming language someday.

## Usage

You can use the compiled file SLang and pass to it a name of a file with your SLang code:
```./Slang main.sl```

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

## TODO:
1. Real numbers, arrays and strings' indexation support.

2. Implementation of error recovery in the parser in panic mode.
