#pragma once

#include <vector>

class GoalPost {
public:
    GoalPost(int size);
    int pop(); //player id: 1, 2. if empty return 0
    bool push(int id);
    int * getPost() const;
private:
    std::vector<int> post;
};