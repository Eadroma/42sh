# 42sh

[![Build Status](https://travis-ci.com/Eadroma/42sh.svg?branch=main)](https://travis-ci.com/github/Eadroma/42sh) | [![Codacy Badge](https://api.codacy.com/project/badge/Grade/ce23e0d0d8e54462aa4dc15b04f61041)](https://app.codacy.com/gh/Eadroma/42sh?utm_source=github.com&utm_medium=referral&utm_content=Eadroma/42sh&utm_campaign=Badge_Grade)

## Overview

An interactive shell built as part of the EPITECH curriculum (`B-PSU-210-PAR-2-2-42sh`). It replicates the core functionality of traditional UNIX shells like `sh`, `bash`, and `tcsh`. 

This shell contains a comprehensive set of features tailored for interactive use, standard streams manipulation, process control, and advanced parsing.

## Features

- **Built-in commands:**
  - `cd`: Change directory.
  - `echo`: Display lines of text.
  - `env`, `setenv`, `unsetenv`: Environment variable management.
  - `alias`: Create and manage command aliases.
  - `history`: Command history viewing and management.
  - `exit`: Terminate the shell.

- **Command Execution & Flow Control:**
  - **Pipes (`|`)**: Route output of one command to the input of another.
  - **Logical operators (`&&`, `||`)**: Conditional execution based on exit status.
  - **Semicolons (`;`)**: Sequential command execution.

- **Redirections:**
  - Output: `>` (overwrite) and `>>` (append).
  - Input: `<` (read from file) and `<<` (here-document).

## Prerequisites

To compile and run `42sh`, you will need:
- `gcc` compiler
- `make`
- `ncurses` library (`libncurses-dev` or `libncurses5-dev` on Debian/Ubuntu systems).

## Compilation

The project comes with a standard Makefile. It builds an internal library `libmy` before compiling the main executable.

Run the following inside the root directory to build the project:

```bash
make
```

Available build targets:
- `make` / `make all`: Compile the executable.
- `make clean`: Remove object files (`*.o`).
- `make fclean`: Remove object files and the final executable.
- `make re`: Force a complete recompilation (equivalent to `make fclean` followed by `make`).
- `make vg`: Build with `-g3` debugger symbols enabled for use with Valgrind.
- `make tests`: Run tests script (`./test/tests.sh`).

## Usage

Start the interactive shell by running the compiled binary:

```bash
./42sh
```

You can also request a summary using the `-h` flag (Help mode):

```bash
./42sh -h
```

## Project Structure

```text
.
├── include/       # Header files
├── lib/           # Custom standard library implementation (libmy)
├── src/           # Source code for the shell implementation
│   ├── args/        # Argument parsing and linked list management
│   ├── builtins/    # Implementation of built-in commands (echo, cd, env...)
│   ├── delimitors/  # Handlers for pipes, logical operators, redirections...
│   ├── display/     # Prompt rendering logic
│   ├── exec/        # Native command execution loop
│   ├── free/        # Memory management and garbage collection helpers
│   ├── init/        # Core shell structure initialization
│   └── parsing/     # Interactive query parsing and syntax analysis
└── tests/         # Unit and integration tests
```

## Contributing

Created in 2020 by Victoire Rabeau and contributors for the Epitech "42sh" project.
