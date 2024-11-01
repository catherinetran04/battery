# Battery Simulation Project

This project simulates and analyzes battery voltage and percentage based on input data. It includes scripts for compiling, running tests, and processing battery-related calculations.

## Files Overview

### Source Files

- **batt_main.c**: Main source file that executes battery voltage and percentage calculations.
- **batt_update.c**: Contains functions for updating battery state.
- **batt.h**: Header file defining battery-related functions and constants.

### Test Files

- **test_batt_update.c**: Contains unit tests for the functions in `batt_update.c`.
- **test_batt_update.org**: Original version of the test file for comparison.

### Input Files

- **input.txt**: Contains data values used for testing the battery simulation in different configurations&#8203;:contentReference[oaicite:0]{index=0}.

### Scripts

- **batt_examples.sh**: Bash script that compiles the project and runs battery simulations with a set of voltage data. Each value in `data` is doubled and used to execute both voltage (`V`) and percentage (`P`) calculations using `batt_main`&#8203;:contentReference[oaicite:1]{index=1}.

### Build Files

- **Makefile**: Defines the build instructions for compiling the project.

## Usage

1. **Compilation**: To compile the main program and associated tests, run:
    ```bash
    make batt_main
    ```

2. **Running Simulations**: Use the `batt_examples.sh` script to simulate battery data calculations:
    ```bash
    ./batt_examples.sh
    ```

3. **Input Data**: The `input.txt` file can be used to feed different battery data for testing and simulation purposes.

## License

This project is provided under the MIT License. See the `LICENSE` file for more details.
