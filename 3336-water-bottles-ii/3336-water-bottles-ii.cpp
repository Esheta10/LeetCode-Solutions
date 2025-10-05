//Approach-1 Simple Simulation
//T.C : O(root(numBottles))
//S.C : O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;

        int drank = numBottles;

        while(empty >= numExchange) {
            empty -= numExchange;

            drank++;

            empty++;

            numExchange++;
        }

        return drank;
    }
};
