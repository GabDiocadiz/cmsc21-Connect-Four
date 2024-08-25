#include "leaderboard.hpp"

// LeaderboardEntry* Leaderboard::userLocation(string username) {
//     LeaderboardEntry* location =
//     list<LeaderboardEntry>::iterator it;
//     for (it = entries.begin(); it != entries.end(); ++it) {
//         if (it->name() == username)
//             return it;
//     }
//     return NULL;
// }

Leaderboard::Leaderboard() {
    entries = list<LeaderboardEntry>();

    fstream file;
    file.open(LEADERBOARD_FILENAME, ios::in);

    // Read existing entries
    if (file.is_open()) {
        // Temp store of entry members
        string user;
        string score;

        // Parse file
        string line;
        while (getline(file, line)) {
            stringstream s(line);

            getline(s, user, ',');
            getline(s, score, ',');

            update(user, stoi(score));
        }

        file.close();
    }
}

void Leaderboard::saveLeaderboard() {
    // delete old file
    remove(LEADERBOARD_FILENAME);

    // create new file
    fstream file;

    // open file
    file.open(LEADERBOARD_FILENAME, ios::out);

    // add entries
    if (file.is_open()) {
        list<LeaderboardEntry>::iterator it;
        for (it = entries.begin(); it != entries.end(); ++it) {
            file << it->name() << "," << it->score() << endl;
        }
    }

    file.close();
}

void Leaderboard::insert(LeaderboardEntry entry) {
    if (entries.empty()) {
        entries.push_back(entry);
        return;
    }

    list<LeaderboardEntry>::iterator it;
    for (it = entries.begin(); it != entries.end(); ++it) {
        if (entry.score() > it->score())
            break;
    }

    entries.insert(it, entry);
}

void Leaderboard::update(string username, int points) {
    std::cout << "updating " << username << std::endl;

    // if user exists, update existing entry, remove and re-insert
    list<LeaderboardEntry>::iterator it;
    for (it = entries.begin(); it != entries.end(); ++it) {
        if (it->name() == username) {
            it->addPoints(points);
            if (prev(it, 1)->score() < it->score()) {
                LeaderboardEntry tmp = *it;
                entries.erase(it);
                insert(tmp);
            }
            return;
        }
    }

    // if new, make new entry and insert
    insert(LeaderboardEntry(username, points));
}

int Leaderboard::getSize() {
    return entries.size();
}