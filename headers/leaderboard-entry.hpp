#include <string>

using namespace std;

class LeaderboardEntry {
    private:
        string username;
        int points;
        // int rank;
    public:
        LeaderboardEntry(string, int);
        // void setRank(int);
        string name();
        int score();

        void addPoints(int);
        // int getRank();
};