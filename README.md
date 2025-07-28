# Pipex

This project is an implementation of the `pipex` program, a common assignment at 42 schools. The goal is to replicate the behavior of the shell pipe (`|`) operator, allowing the output of one command to be used as the input for another. This project demonstrates understanding of process creation, management, and inter-process communication using pipes in a Unix-like environment.

## Features

- **Shell Pipe Simulation**: Emulates the functionality of `< infile cmd1 | cmd2 > outfile`.
- **`here_doc` Support**: Handles input redirection from a "here document," simulating `<< LIMITER cmd1 | cmd2 >> outfile`.
- **Dynamic Command Path Handling**: Locates and executes system commands using the `PATH` environment variable.
- **Robust Error Handling**: Gracefully manages errors such as invalid files, command not found, and system call failures.
- **Process Management**: Uses `fork()` to create child processes and `execve()` to run commands, ensuring the main program waits for their completion.

## How It Works

The program's logic is centered around creating a pipe and forking the main process to create two child processes.

1.  **Argument Parsing**: The program first parses the command-line arguments to identify the input file, output file, and the commands to be executed. It also checks for the optional `here_doc` argument.

2.  **File Handling**:
    - In the standard case, it opens the specified input file for reading and the output file for writing (creating it if it doesn't exist, or truncating it if it does).
    - For `here_doc`, it reads from standard input until a specified `LIMITER` string is found, storing the input in a temporary file. This temporary file then serves as the input for the first command. The output file is opened in append mode.

3.  **Piping and Process Creation**:
    - A pipe is created using the `pipe()` system call. This creates a pair of file descriptors: one for reading and one for writing.
    - The program then forks, creating the first child process.

4.  **Command Execution**:
    - **First Child Process**:
        - Redirects its standard input (`stdin`) to read from the input file (or the `here_doc` temporary file).
        - Redirects its standard output (`stdout`) to write to the write-end of the pipe.
        - Closes unused file descriptors.
        - Executes the first command using `execve()`. The output of this command now goes into the pipe.
    - **Second Child Process**:
        - Redirects its standard input (`stdin`) to read from the read-end of the pipe.
        - Redirects its standard output (`stdout`) to the output file.
        - Closes unused file descriptors.
        - Executes the second command using `execve()`. This command now reads the output of the first command from the pipe.

5.  **Parent Process**:
    - The parent process closes both ends of the pipe and waits for both child processes to terminate using `waitpid()`.
    - It then performs cleanup (e.g., deleting the `here_doc` temporary file) and exits with the status code of the final command.

## How to Compile and Run

The project includes a `Makefile` for easy compilation.

### Compilation

-   To compile the project, run:
    ```bash
    make
    ```
-   This will create the `pipex` executable.

### Cleaning

-   To remove the compiled object files:
    ```bash
    make clean
    ```
-   To remove the object files and the `pipex` executable:
    ```bash
    make fclean
    ```
-   To re-compile the project from scratch:
    ```bash
    make re
    ```

### Usage

The program is run from the command line with the following syntax:

**Standard Usage:**

```bash
./pipex <infile> <"cmd1"> <"cmd2"> <outfile>
```

**Example:**

This command will take the content of `infile`, count the lines (`wc -l`), and write the result to `outfile`.

```bash
./pipex infile "ls -l" "wc -l" outfile
```

**Here-doc Usage:**

```bash
./pipex here_doc <LIMITER> <"cmd1"> <"cmd2"> <outfile>
```

**Example:**

This command will read input from the terminal until `EOF` is entered, use `grep` to find lines containing "a", count the words (`wc -w`), and append the result to `outfile`.

```bash
./pipex here_doc EOF "grep a" "wc -w" outfile
```
