class MedianFinder {
public:
    priority_queue<int> smaller_;
    priority_queue<int, vector<int>, greater<int>> bigger_;
    MedianFinder() {

        
        
    }
    
    void addNum(int num) {

        smaller_.push(num);

        if (!smaller_.empty() && !bigger_.empty() && smaller_.top() > bigger_.top())
        {
            bigger_.push(smaller_.top());
            smaller_.pop();
        }

        if (smaller_.size() > bigger_.size()+1)
        {
            bigger_.push(smaller_.top());
            smaller_.pop();
        }

        if (bigger_.size() > smaller_.size()+1)
        {
            smaller_.push(bigger_.top());
            bigger_.pop();
        }
        
    }
    
    double findMedian() {

        if (smaller_.size() > bigger_.size())
        {
            return smaller_.top();
        }

        if (bigger_.size() > smaller_.size())
        {
            return bigger_.top();
        }

        return (smaller_.top()+bigger_.top())/2.0;
        
    }
};
