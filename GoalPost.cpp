#include "GoalPost.h"

GoalPost::GoalPost(int size)
{
    this->size = size;
}

int GoalPost::pop() //player id: 1, 2. if empty return 0
{
    if (post.size() == 0)
        return 0;
    int playerID = post[post.size() - 1];
    post.erase(post.begin() + post.size() - 1);
    return playerID;
}

bool GoalPost::push(int id)
{
    if(post.size() >= 0 || post.size() < 3)
    {
        post.push_back();
        return true;
    }
    else if(post.size() == 3)
    {
        return false;
    }

    return false;
}

vector<int> GoalPost::getPost() const 
{
    return post;
}