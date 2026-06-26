#include <iostream>
using namespace std;


class StackBase {
public:
    virtual void push(int val) = 0;  
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;
};


class Stack : public StackBase {
private:
    int arr[5];    
    int topIndex;    
    int size;

public:
 
    Stack() {
        size = 5;
        topIndex = -1;  
    }

    void push(int val) {
        if (topIndex == size - 1) {
            cout << "Stack is Full! Cannot push " << val << endl;
            return;
        }
        topIndex++;
        arr[topIndex] = val;
        cout << val << " pushed to stack." << endl;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack is Empty! Cannot pop." << endl;
            return;
        }
        cout << arr[topIndex] << " popped from stack." << endl;
        topIndex--;
    }


    void top() {
        if (topIndex == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Top element is: " << arr[topIndex] << endl;
    }


    void isEmpty() {
        if (topIndex == -1) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Stack is Not Empty." << endl;
        }
    }

    void isFull() {
        if (topIndex == size - 1) {
            cout << "Stack is Full!" << endl;
        } else {
            cout << "Stack is Not Full." << endl;
        }
    }


    void display() {
        if (topIndex == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack s;
    int choice, val;

    do {
        cout << "\n1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. isEmpty" << endl;
        cout << "5. isFull" << endl;
        cout << "6. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.top();
                break;
            case 4:
                s.isEmpty();
                break;
            case 5:
                s.isFull();
                break;
            case 6:
                s.display();
                break;
            case 0:
                cout << "Exit!" << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}