#include <iostream>
using namespace std;
#define max 5
int queue[max];
int front = -1,rear = -1;

bool isempty(){
    return (front == -1 || front > rear);
}

bool isfull(){
    return rear == max-1;
}

void enqueue(int x){
    if(isfull()){
        cout<<"queue overflow"<<endl;
        return;
    }
    if(front == -1) front = 0;
    rear++;
    queue[rear] = x;
}

void dequeue(){
    if(isempty()){
        cout<<"Queue underflow"<<endl;
        return;
    }
    front++;
    if(front > rear) front = rear = -1;
}

void peek(){
    if(isempty()){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<queue[front]<<endl;
}

void display(){
    if(isempty()){
        cout<<"queue is empty"<<endl;
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout<<queue[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
    int choice, val;
    while (true) {
        cout << "\n--- Normal Queue Menu ---\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Remove)\n";
        cout << "3. Peek (Front Element)\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
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