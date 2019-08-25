// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0/?ref=self

#include <iostream>
#include <vector>
#define MIN(a, b) (a>b)?b:a
#define MAX(a, b) (a>b)?a:b

using namespace std;


struct Node{
    int value;
    int position;
    int visited;
};

int compare (const void * a, const void * b)
{
    // for descending order
    return -1 * ( (*(Node*)a).value - (*(Node*)b).value );
}


int main(){
    int t, n;
    cin >> t;
    while (t--)
    {
        int area = 0;
        cin >> n;
        Node *A = new(nothrow) Node[n];
        Node *nodes = new(nothrow) Node[n];
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;

            A[i].position = i;
            A[i].value = temp;
            A[i].visited = 0;

            nodes[i].position = i;
            nodes[i].value = temp;
            nodes[i].visited = 0;
        }
        qsort(nodes, n, sizeof(Node), compare);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << nodes[i].value << " : " << nodes[i].position << endl;
        // }

        Node *leftend, *rightend;
        A[nodes[0].position].visited = 1;
        A[nodes[1].position].visited = 1;

        if (nodes[0].position < nodes[1].position)
        {
            rightend = &(A[nodes[1].position]);
            leftend = &(A[nodes[0].position]);
        }
        else
        {
            rightend = &(A[nodes[0].position]);
            leftend = &(A[nodes[1].position]);
        }

        // cout << "Working between: (" << leftend->position << ") : " << leftend->value << "  --   (" << rightend->position << ") : "<< rightend->value << endl;
        area += (rightend->position - leftend->position - 1) * A[nodes[1].position].value;
        for (int i = leftend->position+1; i < rightend->position; i++)
        {
            area -= A[i].value;
            A[i].visited = 1;
        }

        for (int j = 0; j < n; j++)
        {
            if (A[nodes[j].position].visited == 0)
            {
                A[nodes[j].position].visited = 1;
                if (nodes[j].position < leftend->position)
                {

                    area += (leftend->position - nodes[j].position -1) * nodes[j].value;
                    for (int i = nodes[j].position+1; i < leftend->position; i++)
                    {
                        if (A[i].visited == 0)
                        {
                            area -= A[i].value;
                            A[i].visited = 1;
                        }
                        else{
                            cout << "This is not supposed to happen, leftend overflow to visited side" << endl;
                            break;
                        }
                    }
                    leftend = &(A[nodes[j].position]);
                    // cout << "Working between: (" << leftend->position << ") : " << leftend->value << "  --   (" << rightend->position << ") : "<< rightend->value << endl;

                }
                else
                {
                    area += (nodes[j].position - rightend->position -1) * nodes[j].value;
                    for (int i = rightend->position+1; i < nodes[j].position; i++)
                    {
                        if (A[i].visited == 0)
                        {
                            area -= A[i].value;
                            A[i].visited = 1;
                        }
                        else{
                            cout << "This is not supposed to happen, rightend overflow to visited side" << endl;
                            break;
                        }
                    }
                    rightend = &(A[nodes[j].position]);
                    // cout << "Working between: (" << leftend->position << ") : " << leftend->value << "  --   (" << rightend->position << ") : "<< rightend->value << endl;
                }
            }
        }


        cout << area << endl;
        delete[] nodes;
        delete[] A;
    }
    return 0;
}