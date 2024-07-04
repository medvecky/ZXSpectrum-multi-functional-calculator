# ZXSpectrum-multi-functional-calculator

A multi-functional, text-based RPN (Reverse Polish Notation) calculator designed specifically for the ZX Spectrum. This project brings a robust set of mathematical capabilities to the iconic ZX Spectrum, leveraging its unique architecture to deliver a fast, efficient, and user-friendly calculator experience

## Description

The calculator supports the following operations:

| Mnemonic  | Description                                                   |
| ----------| --------------------------                                    |
| +         | addition                                                      |
| -         | subtraction                                                   |
| /         | division                                                      |
| *         | multiplication                                                |
| ↑         | power                                                         |
|           |                                                               |
| fabs      | absolute value of a number                                    |
| fatn      | arctangent in radians                                         |
| fcos      | cosine in radians                                             |
| fmul10    | multiply by 10                                                |
| fdiv10    | divide by 10                                                  |
| fexp      | exponential function                                          |
| fint      | get the integer part of a number                              |
| flog      | natural logarithm with the basis e                            |
| fneg      | change number sign                                            |
| fsin      | sine in radians                                               |
| fsqr      | square root                                                   |
| ftan      | tangent in radians                                            |
| fsgn      | gives autonomous of the algebraic sign the number (-1; 0; 1)  |
|           |                                                               |
| ss        | print the content of the stack                                |
| sc        | clear the stack                                               |
| spop      | pop the first value of the stack                              |
| sdupe     | duplicate the top element of the stack                        |
| sswap     | swap the top two elements of the stack                        |
|           |                                                               |
| hs        | show the content of the history                               |
| hel       | execute the last history entry                                |
| hc        | clear the history                                             |
| hdl       | delete the last entry from the history                        |
| hen       | execute the nth record from the history                       |
| hee       | edit an entry in the history and execute after editing        |

Additionally, it accommodates floating-point numbers up to nine digits in both decimal (e.g., 3.14) and scientific (e.g., 8.9e-5) notations.

## App development setup

### Prerequisites

- Installed [z88dk](https://github.com/z88dk/z88dk)

### Build binary app

- Clone the project:

```bash
git clone https://github.com/medvecky/ZXSpectrum-multi-functional-calculator.git
```

- Navigate to the project directory.
- Execute the following command:

```bash
make install
```

The calculator binary, named calc.tap (calc.com for CP/M), is located in the /bin directory.

By modifying the Makefile, the app can be built as a ZX Spectrum TAP file or a CP/M COM file.

## Operating Manual

The calculator can optionally be run using the [ZEsarUX](https://github.com/chernandezba/zesarux) emulator.

RPN expressions should be entered with a single space separating tokens, including operators and operands.

### Simple Operations in RPN Format

#### Two operand operations

```bash
# 9 * 4
9 4 * <return>
# 9 + 4
9 4 + <return>
# 9 / 4 
9 4 / <return>
# 9 ^ 4
9 4 ↑ <return>
```

#### One operand operations

```bash
# cos( 3.14159265359 )
3.14159265359 fcos <return>
# √( 2 )
2 fsqr <return>
```

### Complex Operations in RPN Format

```bash
#√( 2 * 300.51 / 9.8 )
300.51 2 * 9.8 / fsqr
```

### History operations

The calculator stores the last five operations entered.

- To view the history, use the ``` hs ``` command.
- To execute the most recent command from the history, use the ``` hel ``` command.
- To execute a specific command from the history, use the ``` hen ``` command. After entering ``` hen ```, the calculator displays the history and waits for you to enter the number of the entry you wish to execute.
- To modify and execute commands from the history, use the ``` hee ``` command.

After entering the ``` hee ``` command, the actions from the history will be displayed on the screen. Navigate through the list using the cursor keys. Press the **RETURN**  key to send the selected record for execution. To ensure correct display, use the ``` hee ``` command before each call to edit the history.
