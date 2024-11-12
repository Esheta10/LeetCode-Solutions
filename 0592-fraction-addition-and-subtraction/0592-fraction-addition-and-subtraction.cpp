//Approach-1 (Simple simulation)
//T.C : O(n), n = length of expression
//S.C : O(1)
class Solution {
public:
    string fractionAddition(string expression) {
        int nume=0;
        int deno=1;

        int i=0;
        int n=expression.length();

        while(i<n)
        {
            int currNume=0;
            int currDeno=0;

            bool isNeg = (expression[i]=='-');
            if(expression[i]=='-'|| expression[i]=='+')
            {
                i++;
            }
            //Build the currNume
            while(i<n && isdigit(expression[i]))
            {
                int val=expression[i]-'0';
                currNume = (currNume*10) + val;
                i++;
            }
            i++;//numerator / denominator //skipiing the divisrio character '/'

            if(isNeg==true)
                currNume *= -1;

            //build the currentDeno
            while(i<n && isdigit(expression[i]))
            {
                int val=expression[i]-'0';
                currDeno = (currDeno*10) + val;
                i++;
            }
            nume = nume*currDeno + deno*currNume;
            deno = deno*currDeno;
        }
        
        //num
        //deno
        //-3 / 6 //GCD : 3
         int GCD = abs(__gcd(nume, deno)); //3
        
        nume/=GCD;//-1
        deno/=GCD;//2

        return to_string(nume) + "/" + to_string(deno);
    }
};