/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
 
//为什么你总是说别人很好，却没有说过我很好。
//我也做了很多啊，为什么你却不说我的好。

class MiniTwitter {
public:
    map<int, vector<int>> user_friend;
    map<int, vector<Tweet>> user_tweet;
    vector<Tweet> all_tweet;
    MiniTwitter() {
        // do intialization if necessary
    }

    /*
     * @param user_id: An integer
     * @param tweet_text: a string
     * @return: a tweet
     */
     Tweet postTweet(int user_id, string &tweet_text) {
         Tweet tweet = Tweet::create(user_id, tweet_text);
         user_tweet[user_id].push_back(tweet);
         all_tweet.push_back(tweet);
         return tweet;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new feeds recently and sort by timeline
     */
    vector<Tweet> getNewsFeed(int user_id) {
        auto i  = all_tweet.end() - 1;
        auto start = all_tweet.begin();
        vector<Tweet> result;
        int need_length = 10;
        while(need_length && i >= start){
            if(find(user_friend[user_id].begin(),user_friend[user_id].end(), i->user_id) != user_friend[user_id].end()
              || i->user_id == user_id){ // find methon return
                result.push_back(*i);
                need_length--;
            }
            i--;
        }
        return result;
    }

    /*
     * @param user_id: An integer
     * @return: a list of 10 new posts recently and sort by timeline
     */
    vector<Tweet> getTimeline(int user_id) {
        auto start = user_tweet[user_id].begin();
        vector<Tweet> result;
        int need_length = 10;
        for(auto i = user_tweet[user_id].end() -1; i>=start && need_length; i--){
            result.push_back(*i);
        }
        return result;
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void follow(int from_user_id, int to_user_id) {
        user_friend[from_user_id].push_back(to_user_id);
    }

    /*
     * @param from_user_id: An integer
     * @param to_user_id: An integer
     * @return: nothing
     */
    void unfollow(int from_user_id, int to_user_id) {
        auto end = user_friend[from_user_id].end();
        // vector delete obj element
        for(auto i = user_friend[from_user_id].begin(); i!= end; i++){ 
            if(*i == to_user_id){
                user_friend[from_user_id].erase(i);
                return ;
            }
        }
    }
};