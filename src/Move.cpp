#include "../include/Move.hpp"
void moveLine(Board& board);

moves::MoveResult moves::apply(Board& board, Directions dir)
{
    MoveResult result;
    result.moved = false;
    result.scoreGained = 0;
    
    switch(dir)
    {
        case Directions::UP:
            // TODO: Apply upward movement logic
            break;
        case Directions::DOWN:
            // TODO:  Apply downward movement logic
            break;
        case Directions::LEFT:
            // TODO: Apply leftward movement logic
            break;
        case Directions::RIGHT:
            // TODO: Apply rightward movement logic
            break;
    }
    
    return result;
}