#include <iostream>
#include <vector>
using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> entered(rooms.size());
    visitRooms(rooms, 0, entered);
    entered[0] = true;

    int num = 0;
    for (auto n : entered) {
        if (n) {
            num++;
        }
    }

    return num == rooms.size();
}

void visitRooms(vector<vector<int>>& rooms, int room, vector<bool>& entered) {
    if (entered[room]) {
        return;
    }

    entered[room] = true;
    for (int i = 0; i < rooms[room].size(); i++) {
        visitRooms(rooms, rooms[room][i], entered);
    }

    return;
}