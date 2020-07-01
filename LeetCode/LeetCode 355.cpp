/*************************************************************************
	> File Name: aaa.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月13日 星期一 18时33分48秒
 ************************************************************************/

int global_Time = 0;//发表推文的时间 全局的
//推文类
class Tweet {
public:
    int id;
    int time;
    Tweet *next;
    
    Tweet(int id) {
        this->id = id;
        this->time = global_Time++;
        next = nullptr;
    }
};

//用户类
class User {
public:
    int id;
    Tweet *tweet; //该用户发送的推文 是个链表
    unordered_set<int> follows; //该用户关注的用户

    User(int id) {
        this->id = id;
        tweet = nullptr;
    }

    void follow(int followeeId) {
        //不能关注自己
        if (followeeId == id) return;
        follows.insert(followeeId);
    }

    void unfollow(int followeeId) {
        //没有关注 或者 不能取关自己
        if (!follows.count(followeeId) || followeeId == id) return;
        follows.erase(followeeId);
    }

    void post(int tweetId) {
        Tweet *newTweet = new Tweet(tweetId);
        //链表 采用头插法 新发表插在前面
        newTweet->next = tweet;
        //新的链表
        tweet = newTweet;
    }
};

class Twitter {    
private:
    unordered_map<int, User*> user_map;  //所有的用户
    
    bool contain(int id) {
        return user_map.find(id) != user_map.end();
    }
    
public:
    Twitter() {
        user_map.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        if (!contain(userId)) {
            user_map[userId] = new User(userId);
        }
        //用户 发表 推文  面向对象
        user_map[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        //用户不存在
        if (!contain(userId)) return {};

        struct cmp {
            bool operator()(const Tweet *a, const Tweet *b) {
                return a->time < b->time;
            }
        };
        //构造大顶堆 时间最大的排在最上面
        priority_queue<Tweet*, vector<Tweet*>, cmp> q;

        //自己的推文链表
        if (user_map[userId]->tweet) {
            q.push(user_map[userId]->tweet);
        }
        //关注的推文链表
        for (int followeeId : user_map[userId]->follows) {
            if (!contain(followeeId)) {
                continue;
            }
            Tweet *head = user_map[followeeId]->tweet;
            if (head == nullptr) continue;
            q.push(head);
        }
        vector<int> rs;
        while (!q.empty()) {
            Tweet *t = q.top(); 
            q.pop();
            rs.push_back(t->id);
            if (rs.size() == 10) return rs;
            if (t->next) {
                q.push(t->next);
            }
        }
        return rs;
    }
    
    // 用户followerId 关注 用户followeeId.
    void follow(int followerId, int followeeId) {
        if (!contain(followerId)) {
            user_map[followerId] = new User(followerId);
        }
        //面向对象
        user_map[followerId]->follow(followeeId);
    }
    
    // 用户followerId 取关 用户followeeId.
    void unfollow(int followerId, int followeeId) {
        if (!contain(followerId)) return;
        //面向对象
        user_map[followerId]->unfollow(followeeId);
    }
};
