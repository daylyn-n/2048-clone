#include "../include/Move.hpp"
#include "../include/Board.hpp"
void moves:: moveLine(std::array<int, 4>& line, MoveResult &res);

moves::MoveResult moves::apply(Board& board, Directions dir)
{
    MoveResult result;
    result.moved = false;
    result.scoreGained = 0;
    
    switch(dir)
    {
        case Directions::UP:
            // process each column
            for(std::size_t c {}; c < 4; c++)
            {
                std::array<int, 4> line;
                
                // get the column from top to bottom
                for(std::size_t r {}; r < 4;r ++)
                {
                    line[r] = board.get(r, c);
                }

                moveLine(line, result);

                for(std::size_t r {}; r < 4; r++)
                {
                    board.set(r, c, line[r]);
                }

            }
            break;
        case Directions::DOWN:
            // TODO:  Apply downward movement logic
            for(std::size_t c { }; c < 4; c++)
            {
                std::array<int, 4> line;
             
                // get the column from bottom up
                for(int r{ 3 }, i {}; r >= 0; --r, ++i)
                {
                    line[i] = board.get(static_cast<std::size_t>(r) , c);
                
                }

                moveLine(line, result);
                for(int r{3},  i{}; r >= 0; --r, ++i)
                {
                    board.set(static_cast<std::size_t>(r), c, line[i]);
                  
                }

            }
            break;
        case Directions::LEFT:
            // TODO: Apply leftward movement logic
             for(std::size_t r {}; r < 4; r++)
            {
                std::array<int, 4> line;
                
                // get the row from left ot right
                for(std::size_t c {}; c < 4;c ++)
                {
                    line[c] = board.get(r, c);
                }

                moveLine(line, result);

                for(std::size_t c {}; c < 4; c++)
                {
                    board.set(r, c, line[c]);
                }

            }
            break;
        case Directions::RIGHT:
            // TODO: Apply rightward movement logic
             for(std::size_t r { }; r < 4; r++)
            {
                std::array<int, 4> line;
             
                // get the row from right to left
                for(int c{ 3 }, i {}; c >= 0; --c, ++i)
                {
                    line[i] = board.get(static_cast<std::size_t>(r) , c);
                
                }

                moveLine(line, result);
                for(int c{3},  i{}; c >= 0; --c, ++i)
                {
                    board.set(static_cast<std::size_t>(r), c, line[i]);
                  
                }

            }
            break;
    }
    
    return result;
}
// [2 0 0 0]       [4 0 0 0]
// [0 0 0 0] --->
// [0 0 0 0] --->
// [2 0 0 0]
void moves::moveLine(std::array<int, 4>& line, MoveResult &res)
{
    std::array<int, 4> temp { {0, 0, 0, 0} };
    
    int pending { };
    int tempIndex { };
    for(int i { }; i < 4; i++)
    {
        int cur { line[i] };
        // skip if we see a zero, as we dont need to merge them
        if(cur == 0) continue;
        
        // holds a non-zero tile
        if(pending == 0)
            pending = cur;
       
        // if pending is equal to our current tile, we merge them in our result, and then increment our write
        else if(pending == cur)
        {
            temp[tempIndex++] = pending * 2;
            res.scoreGained += pending * 2;
            pending = 0;

        }
        // if pending is a non-zero tile but doesnt equal to cur we just move pending 
        else 
        {
            temp[tempIndex++] = pending;
            pending = cur;
        }
    }
    if(pending != 0) temp[tempIndex] = pending;
    line = temp;
}