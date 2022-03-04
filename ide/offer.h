//
// Created by xxy on 2022/2/25.
//

#ifndef IDE_OFFER_H
#define IDE_OFFER_H
#include <stack>
using namespace std;
/**09
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
class CQueue {
public:
    stack<int> head;
    stack<int> tail;
    int size;
    CQueue() {
        size = 0;
    }

    void appendTail(int value) {
        tail.push(value);
        size++;
    }

    int deleteHead() {
        if (size == 0) {
            return -1;
        }
        if (head.size() == 0) {
            while (tail.size() > 0) {
                head.push(tail.top());
                tail.pop();
            }
        }
        int h = head.top();
        head.pop();
        size--;
        return h;
    }
};
/** 30: min push pop should be O(1)
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    int num;
    stack<int> org;
    stack<int> order;
    MinStack() {
        num = 0;
    }

    void push(int x) {
        org.push(x);
        if (num == 0 || x <= min()) {
            order.push(x);
        }
        num++;
    }

    void pop() {
        if (num == 0) {
            return;
        }
        int n = org.top();
        org.pop();
        if (n == min()) {
            order.pop();
        }
        num--;
    }

    int top() {
        if (num == 0) {
            return -1;
        }
        return org.top();
    }

    int min() {
        if (num == 0) {
            return -1;
        }
        return order.top();
    }
};
#endif //IDE_OFFER_H
