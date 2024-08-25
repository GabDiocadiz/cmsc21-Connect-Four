#include "leaderboard-entry.hpp"

LeaderboardEntry::LeaderboardEntry(string _name, int _score) {
    username = _name;
    points = _score;
    // rank = -1;
}

string LeaderboardEntry::name() {
    return username;
}

int LeaderboardEntry::score() {
    return points;
}

void LeaderboardEntry::addPoints(int pointsToAdd) {
    points += pointsToAdd;
}

// int LeaderboardEntry::getRank() {
//     return rank;
// }

// void LeaderboardEntry::setRank(int r) {
//     rank = r;
// }