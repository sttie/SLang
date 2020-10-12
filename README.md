## Usage

You can use the compiled file SLang and pass a filename with your SLang code to it:
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
Real numbers, arrays and strings' indexation support.
Implementation of error recovery in the parser in panic mode.
