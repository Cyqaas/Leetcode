class MyQueue
{
private:
    stack<int> input, output;

    // helper method to ensure there is always something in the output stack
    void fulfill()
    {
        // iterate through the whole input stack
        while (!input.empty())
        {
            // push most recent of input stack onto output stack to simulate FIFO
            output.push(input.top());
            input.pop();
        }
    }

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        // push the new element only into the input stack
        input.push(x);
    }

    int pop()
    {
        // before popping the first element, ensure there is something in the output stack
        if (output.empty())
            fulfill();

        int first = output.top();
        output.pop();
        return first;
    }

    int peek()
    {
        // before returning the first element, ensure there is something in the output stack
        if (output.empty())
            fulfill();

        return output.top();
    }

    bool empty()
    {
        // return true iff both stacks are empty, otherwise, return false
        return input.empty() && output.empty();
    }
};
