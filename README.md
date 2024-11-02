
# Battery Management System (BMS) Simulation Project

## Project Overview

The Battery Management System (BMS) Simulation Project models the behavior of a battery under varying conditions. It provides tools to simulate voltage and capacity changes, and functions for testing and monitoring. It includes automated testing scripts and validation methods to ensure memory safety and code efficiency.

## Project Structure

- **Makefile**: Automates the build process.
- **Source Code Files**:
  - `batt_main.c`: Main application file that calculates and outputs voltage and battery percentage.
  - `batt_update.c`: Updates the battery’s state based on input data.
  - `batt_sim.c`: Contains battery simulation logic.
- **Header File**:
  - `batt.h`: Defines structs and function prototypes used across the project.
- **Test Files**:
  - `test_batt_update.c`: Test suite for verifying `batt_update` functionality.
  - `testy`: Automated testing script for use with `valgrind` (Linux) or an alternative memory-checking tool.
- **Utility Scripts**:
  - `batt_examples.sh`: Runs `batt_main` with predefined voltage and percentage values for demonstration and testing purposes.
- **Input Data**:
  - `input.txt`: Provides sample battery data for testing purposes.

## Requirements

1. **Compiler**: `gcc` 
2. **Make**: To build the project.
3. **Valgrind** (for Linux) : Used for memory debugging and validation during tests.

## Installation

1. **Install Valgrind or Alternative**:
   - **Linux**: Install Valgrind with `sudo apt-get install valgrind`.
   - **macOS**: Use AddressSanitizer by adding `-fsanitize=address` to `CFLAGS` in the Makefile.

## Usage

### Compilation

Run `make` in the project directory to compile all components:
```bash
make
```

This command compiles `batt_main`, `test_batt_update`, and any required object files. Use additional targets for specific tasks:
- `make all`: Builds all components.
- `make batt_main`: Compiles only the main BMS program.
- `make test_batt_update`: Compiles the test suite for `batt_update`.
- `make clean`: Removes compiled files and executables.
- `make zip`: Creates a zipped package of project files.

### Running the Program

#### `batt_main`
 Battery meter simulator main program and supporting functions. Read voltage sensor value and mode (volts or percent) from the command
 line and show the results of running functions from batt_update on the screen.

#### Example:
```bash
./batt_main 3800 V      # Simulate a voltage reading of 3800mV
./batt_main 50 P        # Simulate a battery at 50% capacity
```

### Running Tests

The `testy` script and `test_batt_update` binary automate testing. Run tests with:
```bash
make test-prob1
```

> **Note**: For memory safety testing on macOS, use AddressSanitizer instead of Valgrind by adding `-fsanitize=address` to `CFLAGS` in the Makefile.

## Scripted Testing

`batt_examples.sh` automates `batt_main` execution across a set of voltage and percentage values:
```bash
./batt_examples.sh
```

**Output**:
This script will display results for each test, showing battery behavior at different voltage levels and percentages.

Example output:
```plaintext
==========Voltage FOR 7800==========
> ./batt_main 7800 V
[output here]

==========Percent FOR 7800==========
> ./batt_main 7800 P
[output here]
...
```

## Sample Data Format

The `input.txt` file supplies sample data for tests, formatted to represent various scenarios for the battery’s behavior. Example:
```plaintext
Tran1126
1   43   42
1   1   20
10   13   24   10
racrac  0   3   6
129   36
...
```

This data can be modified for custom simulations to test battery performance across different metrics.
