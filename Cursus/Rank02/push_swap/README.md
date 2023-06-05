# Push_swap

Push_swap is a sorting algorithm project at 42 school. The goal of the project is to sort a stack of numbers using a limited set of operations.

## Installation

1. Clone the repository:

```
git clone https://github.com/rphlr/42-push_swap.git
```

2. Change to the project directory:

```
cd push_swap
```

3. Compile the project:

```
make
```

## Usage

To run the program, use the following command:

```
./push_swap [numbers]
```

Replace `[numbers]` with the numbers you want to sort. Separate the numbers with spaces.

For example, to sort the numbers 3, 1, and 4, you would run:

```
./push_swap 3 1 4
```

The program will output a list of instructions to sort the stack.

### Available Commands

- `help` or `h`: Display the available make commands.
- `make run [numbers]` or `make r [numbers]`: Runs the program.
- `make view` or `make v`: Launches the visualizer.
- `make test` or `make t`: Runs the program multiple times for testing purposes.
- `make check [numbers]` or `make c [numbers]`: Checks if the sorting is correct.
- `bonus`: Compile the bonus program.

### Makefile Commands

The following commands are available in the Makefile:

- `make`: Compiles the project.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Rebuilds the project.

Note: Some bonus features are not yet implemented.
