#include <iostream>
using namespace std;
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

bool isempty(){
    return(front == -1);
}

bool isfull(){
    return ((rear+1) % MAX == front);
}

void enqueue(int x){
    if(isfull()){
        cout<<"overflow"<<endl;
        return;
    }
    if(isempty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    queue[rear] = x;
}

void dequeue(){
    if(isempty()){
        cout<<"queue underflow"<<endl;
        return;
    }
    if(front==rear) front = rear = -1;
    else front = (front+1) % MAX;
}

void peek(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<queue[front]<<endl;
}

void display(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return;
    }
    int i = front;
    while (1)
    {
        cout<<queue[i]<<" ";
        if(i== rear) break;
        i = (i+1) % MAX;
    }
    cout<<endl;
}

int main() {
    int x, val;
    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> x;

        switch (x) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isempty()) cout << "Queue is Empty\n";
                else cout << "Queue is NOT Empty\n";
                break;
            case 6:
                if (isfull()) cout << "Queue is Full\n";
                else cout << "Queue is NOT Full\n";
                break;
            case 7:
                return 0; 
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}