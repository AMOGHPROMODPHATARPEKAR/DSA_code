#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> winnerOfKConsecutiveGames(vector<int>& potential, int k) {
    int n = potential.size();
    queue<int> q; // Queue to store participants
    vector<int> consecutiveWins(n, 0); // Array to store consecutive wins for each participant

    // Initialize the queue with participants
    for (int i = 0; i < n; ++i) {
        q.push(i);
    }

    // Simulate the tournament process
    while (!q.empty()) {
        int p1 = q.front(); // Front participant
        q.pop();
        int p2 = q.front(); // Next participant from the queue
        q.pop();

        // Compare potentials of p1 and p2
        if (potential[p1] > potential[p2]) {
            consecutiveWins[p1]++;
            if (consecutiveWins[p1] == k) {
                return {p1 + 1, potential[p1]}; // Return the index (1-based) and potential of the winner
            }
            q.push(p1); // Winner goes to the front of the queue
            q.push(p2); // Loser goes to the end of the queue
        } else {
            consecutiveWins[p2]++;
            if (consecutiveWins[p2] == k) {
                return {p2 + 1, potential[p2]}; // Return the index (1-based) and potential of the winner
            }
            q.push(p2); // Winner goes to the front of the queue
            q.push(p1); // Loser goes to the end of the queue
        }
    }

    return {-1, -1}; // No winner found
}

int main() {
    // Example input
    vector<int> potential = {3, 2, 1, 4};
    int k = 2;

    // Find the winner of k consecutive games
    pair<int, int> winner = winnerOfKConsecutiveGames(potential, k);

    if (winner.first != -1) {
        cout << "Winner of " << k << " consecutive games: Participant " << winner.first << " with potential " << winner.second << endl;
    } else {
        cout << "No winner found for " << k << " consecutive games." << endl;
    }

    return 0;
}
