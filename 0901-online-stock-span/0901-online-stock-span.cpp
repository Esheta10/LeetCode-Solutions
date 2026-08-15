class StockSpanner {
public:
    stack<int> prices; // for storing the price values
    stack<int> spans; // for storing the spans
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int currentSpan = 1; // span for current day is 1 

        // when stack is empty or ya pichle din ka span is  <= current day ka span
        // add pichle din ka span to current day's span
        while(!prices.empty() && prices.top() <= price){

            currentSpan += spans.top();

            prices.pop(); // pop the previous day's price
            spans.pop(); // pop the previous day's span
        }

        prices.push(price); // add new price
        spans.push(currentSpan); // add new calculated span

        return currentSpan;
    }       
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */