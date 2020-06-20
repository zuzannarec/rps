#include <iostream>

#include "helper_functions.hpp"
#include "rps.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Please provide on input number of games to play." << std::endl;
        return 1;
    }
    int games_count = string_to_int(argv[1]);

    std::string user_symbol_str;
    int game_no = 1;
    while (games_count)
    {
        std::cout << "GAME " << std::to_string(game_no) << ". Provide one of three numbers: 1 (rock), 2 (paper) or 3 (scissors)." << std::endl;
        std::cin >> user_symbol_str;
        int user_symbol = string_to_int(user_symbol_str);
        auto status = rps_play(user_symbol);
        if (status == 0)
        {
            --games_count;
            ++game_no;
        }
        std::cout << std::endl;
    }
    return 0;
}