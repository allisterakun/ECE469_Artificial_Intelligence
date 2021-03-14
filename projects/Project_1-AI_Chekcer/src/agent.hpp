#ifndef AGENT_HPP
#define AGENT_HPP

#include "Game.hpp"

namespace Game {

    class checker;

    class agent {
    public:
        agent(): game(nullptr), isAI(false), moveTime(0), timeLimit(0), maxDepthReached(0) {};

        agent(checker* game, bool isAI, double timeLimit) : game(game), isAI(isAI), moveTime(0), timeLimit(timeLimit), maxDepthReached(0) {};

        move play(board &Board);

        move alpha_beta_search(board &Board);
        int score_board(board &Board);

        int getMaxDepth();
        void setMoveTime(double moveTime);
        double getMoveTime();

    private:
        friend class checker;
        checker *game;
        std::vector <move> moveList;

        double timeLimit;
        double moveTime;

        bool isAI;
        int maxDepthReached;
    };
}



#endif //AGENT_HPP
