class AuthenticationManager {
public:
    int ttl;
    unordered_map<string, int> mp;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        mp[tokenId] = currentTime + ttl;
    }

    void renew(string tokenId, int currentTime) {
        if (mp.find(tokenId) != mp.end()) {
            if (mp[tokenId] > currentTime) {
                mp[tokenId] = currentTime + ttl;
            }
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int count = 0;

        for (auto it : mp) {
            if (it.second > currentTime) {
                count++;
            }
        }

        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */