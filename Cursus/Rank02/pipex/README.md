# 42-pipex
Pipex is a project from 42 school that simulates the behavior of the shell pipeline command `|` by redirecting the output of one command as input to another command. The project implements two bonuses: `here_doc` command and multiple commands.

## Usage
The pipex command takes four arguments:

```bash
./pipex input_cmd command1 command2 output_file
```

- `input_cmd`: a command that produces an output that will be used as input by the first command
- `command1`: the first command that will receive the output from input_cmd
- `command2`: the second command that will receive the output from command1
- `output_file`: the file that will receive the output from `command2`

## Examples

```bash
./pipex infile "ls -l" "grep test" outfile
```

This command takes the output of `infile` as input to `ls -l`, and then takes the output of `ls -l` as input to `grep test`. The output of `grep test` is then redirected to `outfile`.

```bash
./pipex here_doc LIMITER "grep test" "wc -l" outfile
```

This command takes the input from the here_doc command as input to `grep test`, and then takes the output of `grep test` as input to `wc -l`. The output of `wc -l` is then redirected to `outfile`.

## Build

To build the program, simply run `make` command in the root directory. This will build the executable `pipex`.

## Conclusion

Pipex is a useful program for simulating the behavior of the shell pipeline command. It allows users to redirect the output of one command as input to another command, and provides a useful tool for processing data in a pipeline. The implementation of `here_doc` command and multiple commands makes the program even more powerful and flexible.