#include "leaderboard-entry.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

#define LEADERBOARD_FILENAME "leaderboard.csv"

class Leaderboard {
    private:
        void insert(LeaderboardEntry);

    public:
        Leaderboard();
        void saveLeaderboard();

        list<LeaderboardEntry> entries;
        
        void update(string, int);
        int getSize();
};