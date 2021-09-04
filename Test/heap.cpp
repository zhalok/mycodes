#include <iostream>
#define sz 100000
using namespace std;

struct Heap
{
    int heap[sz], cnt;
    Heap()
    {
        cnt = 0;
    }
    void insertIntoHeap(int x);
    int deleteRootHeap();
    void printHeap()
    {
        for (int i = 1; i <= cnt; i++)
            cout << heap[i] << " \n"[i == cnt];
        return;
    }
};

void Heap::insertIntoHeap(int x)
{
    heap[++cnt] = x;
    int child = cnt;
    int par = child / 2;
    while (par > 0)
    {
        if (heap[par] < heap[child])
            swap(heap[par], heap[child]);
        else
            return;
        child = par;
        par = par / 2;
    }
}

int Heap::deleteRootHeap()
{
    if (cnt == 0)
    {
        cout << "Underflow!\n";
        return -1;
    }
    int ret, ind = 1, lc, rc, mx;
    swap(heap[ind], heap[cnt]);
    ret = heap[cnt--];
    lc = ind * 2;
    rc = (ind * 2) + 1;

    while (lc <= cnt)
    {
        if (rc <= cnt)
            mx = max(heap[lc], heap[rc]);
        else
            mx = heap[lc];
        if (mx > heap[ind])
        {
            if (heap[lc] == mx)
            {

                swap(heap[lc], heap[ind]);
                ind = lc;
            }
            else
            {
                swap(heap[rc], heap[ind]);
                ind = rc;
            }
        }
        else
            return ret;
        lc = ind * 2;
        rc = (ind * 2) + 1;
    }
    return ret;
}

void HeapSort(int arr[], int n)
{
    Heap hp;
    for (int i = 0; i < n; i++)
    {
        hp.insertIntoHeap(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = hp.deleteRootHeap();
    }
    return;
}

int main()
{
    int n, arr[sz];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    HeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " \n"[i == n - 1];
    }

    return 0;
}