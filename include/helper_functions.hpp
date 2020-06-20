#include <iostream>
#include <stdexcept>

int string_to_int(std::string input_string)
{
    int output_int = 0;
    try
    {
        output_int = std::stoi(input_string);
    }
    catch (const std::invalid_argument& ia)
    {
        std::cerr << "Invalid input string: " << input_string << ", " << ia.what() << std::endl;
    }
    catch (const std::out_of_range& oor)
    {
        std::cerr << "Cannot convert string to int. Value out of range: " << input_string << ", " << oor.what() << std::endl;
    }
    return output_int;
}