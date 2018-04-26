## Interpreter for Monty ByteCode files
> Monty ByteCode contains opcodes specific to Monty. This is an interpreter for
> these special opcodes: `push`, `pall`, `pint`, `pop`, `swap`, `swap`, `add`, `nop`

### Description of repo contents:
* bytecode folder ----- holds Monty ByteCode files
* monty.h ------------- holds all function prototypes for interpreter
* main.c -------------- entry into program

### How to Compile
Usage: ./monty [filename]
```
$ git clone https://github.com/MelissaN/monty
$ cd monty
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ ./monty bytecodes/000.m
```

### Environment
* Language: C (version C89)
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)
---
### Authors
Melissa Ng [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/MelissaNg__)
Leon Cheung [![M](https://upload.wikimedia.org/wikipedia/fr/thumb/c/c8/Twitter_Bird.svg/30px-Twitter_Bird.svg.png)](https://twitter.com/HiddenJem245)
