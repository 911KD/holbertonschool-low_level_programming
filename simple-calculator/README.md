# Simple Calculator

A small menu-driven calculator written in C.

## Usage
1) Add  2) Subtract  3) Multiply  4) Divide  0) Quit

## Number type
The calculator uses **decimal numbers (`double`)** for all operations.
- Inputs `A` and `B` can be integers or decimals (e.g. `10`, `2.5`, `-3`).
- Results are printed without useless trailing zeros:
  `10 + 25` gives `35`, `10 / 4` gives `2.5`.

## Errors
- A menu number that does not exist prints `Invalid choice`.
- A non-number for `A` or `B` prints `Invalid input`.
- Dividing by zero prints `Error: division by zero`.
