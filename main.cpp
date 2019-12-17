#include <iostream>
#include "LinkedList.h"
using namespace std;
template <class T>
void printList(LinkedList<T>& list){
    for ( LinkedList<int>::Iterator iterator = list.begin(); iterator != list.end(); iterator++)
    {
        cout << *iterator << " ";
    }

    cout << endl;
}
int main() {
    LinkedList<int> list;
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "----------- original list -----------" << endl;
    printList(list);

    cout << "-------- list after delete 4 --------" << endl;
    list.remove(4);
    printList(list);

    cout << "-------- list search 3 index --------" << endl;
    cout <<list.search(3)<<endl;


    return 0;
}