Description of the Program: This program was created to understand the signal-slot mechanism in Qt and ensure proper organization of code across header and implementation files. It was not intended to be a large-scale project using QML for GUI or involving complex logic for web page opening.
Program Description: The program prompts the user to input text and transmits this text for processing using Qt's signals and slots. Here's how it works:
1. Class and Signal Declarations:
    * In the header file UserInteractor.h, the class UserInteractor is declared with the signal phraseTyped.
    * In the header file Firefox.h, the slot browse is declared.
    * In the header file InternetExplorer.h, the slot browseRequested is declared.
2. Implementation of Classes and Functions:
    * In the file UserInteractor.cpp, the function getInput() is implemented, which prompts the user for text input. If the entered string is not empty, the signal phraseTyped is emitted with the entered text as a parameter.
    * In the file InternetExplorer.cpp, the function browseRequested() is implemented. It starts a QTimer with a 5-second interval to call the browse() function.
    * In the file InternetExplorer.cpp, the function browse() is implemented. It outputs the message "Internet explorer is not responding..." to the console.
3. Connection of Signals and Slots:
    * In the file main.cpp, objects UserInteractor, Firefox, and InternetExplorer are created.
    * Using QObject::connect(), the signal phraseTyped of the object interactor is connected to the slot browse of the object firefox.
    * Using QObject::connect(), the signal phraseTyped of the object interactor is connected to the slot browseRequested of the object internetExplorer.
4. Interaction with the User:
    * Upon starting the program, the user is prompted with "Type in your search phrase:" to enter text for searching.
    * After entering text, the program waits for the user to press Enter.
    * Upon pressing Enter, the program outputs the search results through Firefox:
        * It displays "Displaying results for [entered text]:".
        * Subsequently, it outputs the search results in the format:
            * Result 1
            * Result 2
            * Result 3
    * After 5 seconds from displaying the results in the browse function of Firefox, the program outputs "Internet explorer is not responding..." using the browse function in InternetExplorer.
