#include <unordered_map>

#include "rps.hpp"

const std::unordered_map<int, std::string> allowed_symbols = { { 1, "rock"}, {2, "paper"}, {3, "scissors"} };

bool validate_user_symbol(int user_symbol)
{
    if (allowed_symbols.count(user_symbol) != 1)
    {
        std::cout << "User symbol: " << std::to_string(user_symbol) << " not allowed. Try again." << std::endl;
        return false;
    }
    return true;
}

int rps_play(int user_symbol)
{
    if (!validate_user_symbol(user_symbol))
    {
        return 1;
    }

    std::unordered_map<int, std::string> game_symbols;
    auto computer_symbol = rand() % 3 + 1;
    std::cout << "User displays " << allowed_symbols.at(user_symbol) << "." << std::endl;
    std::cout << "Computer displays " << allowed_symbols.at(computer_symbol) << "." << std::endl;
    game_symbols = { {user_symbol, "User"}, {computer_symbol, "Computer"} };

    if (computer_symbol == user_symbol)
    {
        std::cout << "Dead-heat. Try again." << std::endl;
        return 1;
    }

    if (game_symbols.count(1) == 1 && game_symbols.count(2) == 1)
    {
        std::cout << game_symbols[2] << " wins!" << std::endl;
        return 0;
    }
    else if (game_symbols.count(1) == 1 && game_symbols.count(3) == 1)
    {
        std::cout << game_symbols[1] << " wins!" << std::endl;
        return 0;
    }
    else if (game_symbols.count(2) == 1 && game_symbols.count(3) == 1)
    {
        std::cout << game_symbols[3] << " wins!" << std::endl;
        return 0;
    }
    return 0;
}
