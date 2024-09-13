# GUI Calculator Application README

![Calculator Demo](/Calculator/guicalculator/calculator_demo.gif)

## Overview
This project is a simple Calculator application with a graphical user interface (GUI) designed using QML. The logic behind the calculator, such as handling operations and operand management, is implemented in C++. The application utilizes Qt to connect the C++ backend with the QML frontend, particularly using Q_PROPERTY for updating and displaying data in the text fields, as well as signals and slots for communication between different components of the application.

## Features

### Graphical User Interface (GUI):
- Built with QML for an intuitive and user-friendly interface.
- Includes buttons for digits 0-9, basic arithmetic operations: Addition (+), Subtraction (-), Multiplication (*), and Division (/).
- AC (All Clear) button to reset the operands (num1, num2) and the operator.
- Decimal point (.) button for inputting floating-point numbers.

### Backend Logic in C++:
- `SetOperands` class manages input operands (`num1`, `num2`).
- `SetOperation` class manages selected operations.
- `ExecuteOperations` class handles performing calculations between `num1` and `num2`.
- `DisplayManager` class updates the display with the correct values.

### Qt Integration:
- `Q_PROPERTY` is used to bind C++ properties to the QML front end, allowing real-time updates of values displayed in text fields.
- Signals and Slots mechanism is employed for seamless communication between various classes and to propagate changes in operands, operations, and results throughout the application.
- `Q_INVOKABLE` All buttons are connected to C++ methods using the Q_INVOKABLE keyword, allowing them to be called directly from QML.

## Key Functionalities
- **Basic Arithmetic Operations**: The application supports addition, subtraction, multiplication, and division of two numbers.
- **Floating-point Support**: Input numbers can include a decimal point for performing calculations with floating-point precision.
- **Clear Functionality**: The AC button resets the current values of `num1`, `num2`, and the operator, providing a fresh start for the user.
- **Result Display**: The result of each arithmetic operation is displayed prominently, updating immediately after the `=` button is pressed.

## Additional Features
- **Intermediate Result Handling**: The calculator not only computes results when the = button is pressed but also updates the display with the result when any arithmetic operator is pressed after entering the second operand. In this case, the calculator stores the result and displays it in the extraOutput field as num1 with the new operator, waiting for num2.
- **Edit Last Operand**: If num2 has been entered, the calculator allows you to use the DEL button to return to num1, edit this number and the operator, and then return to entering num2.
- **Trailing Zero Removal**: The calculator automatically removes any unnecessary trailing zeros from the result. For example, when adding 7.0 + 5, it will display 12 instead of 12.0.

## Project Structure
The project consists of the following main components:
- **SetOperands (C++)**: Manages the input digits and handles whether the current number being edited is `num1` or `num2`.
- **SetOperation (C++)**: Handles saving and updating the current arithmetic operation (e.g., +, -, *, /).
- **ExecuteOperations (C++)**: Performs the actual calculation based on `num1`, `num2`, and the selected operation.
- **DisplayManager (C++)**: Responsible for displaying the current numbers and operation on the calculator's screen.

The backend communicates with the frontend via signals and slots to ensure data synchronization between the QML interface and C++ logic.

## Platforms
The application is built for the following platforms:
- **macOS**
- **Android**

The source files are available for download in the `builds` folder.

## Running the Application
1. Install Qt (with QML and C++ support).
2. Open the project in Qt Creator.
3. Build and run the project.
4. The calculator's GUI will open, allowing you to perform basic arithmetic operations.
