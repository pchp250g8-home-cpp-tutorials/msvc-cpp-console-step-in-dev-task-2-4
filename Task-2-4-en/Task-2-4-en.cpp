// Task-2-4-en.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main(int argc, char* argv[])
{
    unsigned int max_len = 0; // Maximum length of a sequence where each wave is longer than the previous one
    unsigned int current_len = 0; // Current length of a sequence where each wave is longer than the previous one
    unsigned int prev_wave = 0; // Previous value in the input data sequence
    bool b_done = false; // Flag to control the loop execution
    // Setting the Russian locale for the Windows 11 terminal
    system("chcp 65001 >nul"); // Method 1: Execute an external command.
    setlocale(LC_ALL, "russian.65001"); // Method 2: Call a library function.
    std::locale rus_locale = std::locale("russian.65001"); // Method 3: Create a locale-type variable.
    std::cout.imbue(std::locale::global(rus_locale)); // Method 3: Set the terminal encoding (locale).
    // Data input
    std::cout << "Enter weather station data (0 to end input).\r\n";
    while (!b_done)  // Start of the loop
    {
        unsigned int wave; // Variable for data
        std::cin >> wave; // Input a new data value
        b_done = (wave == 0); // Loop termination condition: inputting 0
        if (current_len == 0)
        {
            current_len = 1; // Initialize length counter to 1
        }
        else if (wave > prev_wave) // If the current wave is longer than the previous one
        {
            current_len += 1; // Increment the sequence length counter
        }
        else
        {
            if (current_len > max_len)  // Otherwise, calculate
            {
                max_len = current_len; // the maximum sequence length
            }
            // Reset length counter to 1
            // and reset the counter for the current segment length
            current_len = 1;   
        }
        prev_wave = wave; // Replace the previous value with the new one
    }
    // Maximum length of a segment where each wave is longer than the preceding one
    // Final answer
    if (current_len > max_len)
    {
        max_len = current_len;
    }
    std::cout << "Maximum segment length: " << max_len;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
