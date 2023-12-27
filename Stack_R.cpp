#include <iostream>
#include <windows.h>
#define N 4
using namespace std;
struct Ball
{
    string colour;
    int number;
    bool skinType; // 1 - смугляста 2 - суцільна 
};

struct Stack
{
    Ball array[N];
    int top = -1;
    void push(Ball ball)
    {
        if (top == N - 1)
        {
            cout << "Стек переповнен!" << endl;
            return;
        }
        array[++top] = ball;
    }
    bool empty()
    {
        return (top == -1);
    }
    Ball pop()
    {
        if (empty())
        {
            cout << "Стек пустий!" << endl;
        }
        else
        {
            Ball temp = array[top--];
            return temp;
        }
    }
    Ball getTop()
    {
        return array[top];
    }
};
void print(Stack stack)
{
    while (!stack.empty())
    {
        Ball del = stack.pop();
        cout << del.colour << " " << del.number << " " << del.skinType << endl;
    }
}
int main()
{
    SetConsoleOutputCP(1251);
    Stack billiardPocket;
    Ball ball1 = { "червоний",2,true };
    Ball ball2 = { "зелений",3,false };
    Ball ball3 = { "чорний",7,false };

    cout << "“Забити” 3 різні кулі:" << endl;
    billiardPocket.push(ball1);
    billiardPocket.push(ball2);
    billiardPocket.push(ball3);
    print(billiardPocket);

    cout << "\nЗабрати верхню кулю:" << endl;
    billiardPocket.pop();
    print(billiardPocket);

    cout << "\n“Забити” 3 різні кулі:" << endl;
    Ball ball4 = { "жовтий",4,true };
    Ball ball5 = { "зелений",5,false };
    Ball ball6 = { "сірий",6,false };
    billiardPocket.push(ball4);
    billiardPocket.push(ball5);
    billiardPocket.push(ball6);
    print(billiardPocket);

    cout << "\nЗабрати 2 верхні кулю:" << endl;
    Ball del1 = billiardPocket.pop();
    Ball del2 = billiardPocket.pop();
    print(billiardPocket);

    cout << billiardPocket.getTop().number << endl;

    cout << "\nБільша за номером куля повертається в лузу:" << endl;
    if (del1.number > del2.number)
    {
        billiardPocket.push(del1);
    }
    else
    {
        billiardPocket.push(del2);
    }
    print(billiardPocket);
    cout << "\nЗабрати з лузи 5 куль:" << endl;
    for (int i = 1; i <= 10; i++)
    {
        billiardPocket.pop();
    }
    print(billiardPocket);
    return 0;
}