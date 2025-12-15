# ft_printf

*This project has been created as part of the 42 curriculum by smenard.*

## Description

ft_printf is a reimplementation of the standard C library function `printf()`. This project aims to deepen understanding of variadic functions in C and improve overall programming skills through the creation of a versatile and well-structured formatted output function.

The implementation handles multiple conversion specifiers and returns the total number of characters printed, mimicking the behavior of the original `printf()` function. The project is designed with modularity and extensibility in mind, allowing for future enhancements such as bonus flag support.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will generate the `libftprintf.a` static library file.

### Available Make Rules

```bash
make              # Compile the library (same as 'make all')
make all          # Compile the library
make clean        # Remove object files
make fclean       # Remove object files and the library
make re           # Recompile the entire library from scratch
```

## Additional Make Rules and Tests

### For 42 Students (Evaluators)

This project includes basic tests that cannot be submitted to the 42 intranet. **If you are evaluating from the 42 repository**, you can access the complete version with tests at: [github.com/SimardCodeTard/ft_printf](https://github.com/SimardCodeTard/ft_printf)

### For GitHub Users

If you cloned directly from GitHub, additional testing rules are available:

```bash
make tests        # Compile the test suite
make run-tests    # Compile and execute tests
make debug-tests  # Run tests with gdb debugger
make vg-tests     # Run tests with valgrind (leak detection)
```

**Valgrind flags used**: `--leak-check=full -s --show-leak-kinds=all`

### Test Coverage

The test suite verifies:
- All mandatory conversions (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%%`)
- Edge cases (NULL pointers, INT_MIN/MAX, empty strings)
- Return value accuracy
- Memory leak detection

### Usage

Include the header file in your C program:

```c
#include "ft_printf.h"
```

Compile your program with the library:

```bash
cc your_program.c -L. -lftprintf
```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "world");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

## Supported Conversions

- `%c`: Prints a single character
- `%s`: Prints a string
- `%p`: Prints a pointer address in hexadecimal format (with `0x` prefix)
- `%d`: Prints a decimal (base 10) number
- `%i`: Prints an integer in base 10
- `%u`: Prints an unsigned decimal (base 10) number
- `%x`: Prints a number in hexadecimal (base 16) lowercase
- `%X`: Prints a number in hexadecimal (base 16) uppercase
- `%%`: Prints a percent sign

## Project Structure

```
ft_printf/
├── headers/
│   ├── defines.h            # Macro definitions and constants
│   ├── ft_printf.h          # Main header with function prototypes
│   ├── includes.h           # System includes
│   └── lib.h                # Internal library header
├── src/
│   ├── ft_printf.c          # Main entry point and argument handling
│   ├── parse.c              # Format string parsing logic
│   ├── print.c              # Output functions for each conversion type
│   ├── utils.c              # String utilities (strlen, strchr, etc.)
│   └── mem_utils.c          # Memory management utilities
├── tests                    # Only found in the GitHub repository
│   ├── main.c               # Tests entry point
│   ├── tests.h              # Main tests header with prototype declarations and system includes
│   └── tests_mandatory.c    # Tests cases for the mandatory part of the project
├── Makefile                 # Build file using make
└── README.md                ☚ You are here !
```

## Algorithm and Data Structure

### Architecture Overview

The implementation follows a **modular, three-phase approach** designed for clarity and future extensibility:

1. **Main Loop** (`ft_printf.c`): Iterates through the format string
2. **Parsing Phase** (`parse.c`): Identifies and extracts conversion specifications
3. **Printing Phase** (`print.c`): Executes the appropriate output operation

### Key Data Structure: `t_arg`

The central data structure is `t_arg`, which encapsulates all information about a conversion specifier:

```c
typedef struct s_arg
{
    char    type;      // Conversion type (c, s, d, i, u, x, X, p, %)
    void    *value;    // Pointer to the argument value
} t_arg;
```

This structure provides flexibility for future enhancements, such as adding fields for flags, width, and precision without requiring significant refactoring.

### Implementation Details

#### 1. Main Loop Strategy

The `ft_printf()` function uses an **incremental parsing approach**:

- Writes literal characters directly until encountering a `%`
- Delegates conversion handling to `handle_arg()`
- Tracks total characters written for accurate return value

```c
// Simplified logic:
while (i < str_len)
{
    // Write literal text up to next '%'
    wrote_count += write(STDOUT_FILENO, str + i, ft_strlen_until(str + i, '%'));

    // Process conversion specifier
    if (str[i] == '%')
        wrote_count += handle_arg(str + i, ap, &i);
}
```

#### 2. Parsing Strategy

The `ft_parse_arg()` function uses **type-based memory allocation**:

- **32-bit types** (`c`, `d`, `i`, `u`, `x`, `X`): Allocates `sizeof(int32_t)`
- **64-bit types** (`s`, `p`): Allocates `sizeof(int64_t)` for pointers
- **Special cases**:
  - `%`: Duplicates the literal `"%"` string
  - Invalid specifiers: Returns `NULL` value

This approach ensures proper memory handling and type safety when extracting variadic arguments.

#### 3. Output Strategy

The `ft_print_arg()` function acts as a **dispatcher** that routes each conversion type to its appropriate handler:

- **Characters** (`c`, `%`): Direct single-byte write
- **Strings** (`s`): Handles NULL pointers with `"(null)"` output
- **Pointers** (`p`): Writes `"0x"` prefix, then handles NULL as `"(nil)"`
- **Signed integers** (`d`, `i`): Uses `ft_putnbr_base_signed()` for negative handling
- **Unsigned integers** (`u`, `x`, `X`): Uses `ft_putnbr_base()` with appropriate base

#### 4. Number Conversion Algorithm

The `ft_putnbr_base()` function uses **recursive digit extraction**:

```c
// Simplified logic:
if (num >= base_len)
{
    ft_putnbr_base(num / base_len, base);  // Recurse for higher digits
    write(STDOUT_FILENO, &base[num % base_len], 1);  // Write current digit
}
```

This approach naturally handles:
- Variable bases (decimal: "0123456789", hexadecimal: "0123456789abcdef")
- Leading zeros elimination
- Correct digit ordering without temporary buffers

For signed numbers, `ft_putnbr_base_signed()` handles the sign separately before calling the unsigned version with the absolute value.

### Design Decisions

**Separation of concerns**: Each module has a clear responsibility:
- `ft_printf.c`: Orchestration and character counting
- `parse.c`: Argument extraction and type identification
- `print.c`: All output operations
- `utils.c`: String manipulation helpers
- `mem_utils.c`: Memory allocation utilities

**Extensibility**: The structure is designed to easily accommodate bonus features:
- The parsing phase can be extended to detect flags (-, 0, ., #, +, space)
- The `t_arg` structure can be augmented with flag fields
- The printing functions can incorporate flag-based formatting logic

**Memory management**: Dynamic allocation for argument values ensures flexibility but requires careful cleanup:
- Each `handle_arg()` call frees the allocated `arg.value` after printing
- `ft_calloc()` ensures zero-initialized memory for predictable behavior

**Error handling**:
- NULL pointer handling for strings and pointers follows standard printf behavior
- Write errors propagate through return values for caller awareness

## Undefined Behavior and Edge Cases

### Unsupported Conversions

Only `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%%` are supported. Other conversions produce undefined behavior:

```c
ft_printf("%f", 3.14);      // ❌ Floating-point not supported
ft_printf("%ld", 123456L);  // ❌ Modifiers not supported
ft_printf("%5d", 42);       // ❌ Field width not supported (mandatory)
```

### Argument Mismatch

**Insufficient arguments** → Undefined behavior (may crash):
```c
ft_printf("%d %s", 42);  // ❌ Missing string argument
```

**Excess arguments** → Safe but ignored:
```c
ft_printf("%d", 42, 100);  // ✓ Extra arguments ignored
```

### Type Mismatch

Passing wrong argument types causes undefined behavior:
```c
ft_printf("%s", 42);        // ❌ Segmentation fault likely
ft_printf("%d", "string");  // ❌ Garbage output
```

### NULL Pointer Handling

**Handled gracefully**:
- `%s` with NULL → outputs `(null)`
- `%p` with NULL → outputs `(nil)`

**Not handled**:
- Other conversions with NULL cause crashes

### Best Practices

1. Match argument types to conversion specifiers
2. Ensure argument count matches specifiers
3. Use only supported conversions
4. Only pass NULL for `%s` and `%p`

## Resources

### Documentation
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html): Official documentation for printf behavior
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic): Variadic functions in C (va_start, va_arg, va_end)
- [42 Norm](https://github.com/42School/norminette): Coding standard for 42 projects

### Tutorials and Articles
- [Understanding printf](https://www.cprogramming.com/tutorial/printf-format-strings.html): Comprehensive guide to printf format strings
- [Variadic Functions in C](https://www.geeksforgeeks.org/variadic-functions-in-c/): Tutorial on variadic argument handling
- [Hexadecimal Number System](https://www.electronics-tutorials.ws/binary/bin_3.html): Understanding base-16 representation

### AI Usage

AI assistance (Claude) was used **exclusively for writing this README file**. The AI helped with:
- Structuring the documentation according to project requirements
- Articulating technical explanations of the algorithm and data structures
- Formatting and organizing sections for clarity
- Ensuring completeness of the required README sections

**All code implementation** (`ft_printf.c`, `parse.c`, `print.c`, `utils.c`, `mem_utils.c`) was developed manually without AI assistance, through:
- Analysis of the standard library printf behavior
- Manual testing and debugging
- Peer learning and code reviews
- Self-directed research of documentation

This approach ensured genuine learning of variadic functions, format parsing, base conversion algorithms, and low-level I/O operations while leveraging AI appropriately for documentation tasks.
