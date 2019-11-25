#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool Stack = true;
bool Queue = true;
bool PriorityQueue = true;

int main()
{
    int operaciones, a, b;
    while(cin>>operaciones){
        stack<int> pila;
        queue<int> cola;
        priority_queue<int> pCola;

        for (int i = 0; i < operaciones; ++i) {
            cin>>a>>b;
            if(a == 1){
                pila.push(b);
                cola.push(b);
                pCola.push(b);
            }
            else {
                if(pila.empty()) {
                    Stack = false;
                    Queue = false;
                    PriorityQueue = false;
                    continue;
                }
                if(Stack) {
                    Stack = pila.top() == b;
                    pila.pop();
                }
                if(Queue) {
                    Queue = cola.front() == b;
                    cola.pop();
                }
                if(PriorityQueue) {
                    PriorityQueue = pCola.top() == b;
                    pCola.pop();
                }
            }
        }

        if(!Stack && !Queue && !PriorityQueue) cout << "impossible"<<endl;
        else if(Stack && !Queue && !PriorityQueue) cout << "stack"<<endl;
        else if(!Stack && Queue && !PriorityQueue) cout << "queue"<<endl;
        else if(!Stack && !Queue && PriorityQueue) cout << "priority queue"<<endl;
        else cout << "not sure"<<endl;
        Stack = Queue = PriorityQueue = true;

    }
}
