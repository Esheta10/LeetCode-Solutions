class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(), asteroids.end());

        for(int &m:asteroids){

            if(m > mass){ // agar asteroid[i] ka mass, planet ke mass se zyada ho, planet is destroyed
                return false;
            } else if(mass >= 1e5){
                return true; // if mass of planet crosses the constraint size,planet ko koi bhi destroy nahi kar sakta
            }

            mass += m; // asteroid ke mass ko add karo planet mein agar chota hai
        }
        return true;
    }
};