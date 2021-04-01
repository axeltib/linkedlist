#include <iostream>
#include <stdlib.h>
#include <time.h>

// List containing integers
class LinkedList {
    private:  // define important variables and pointers
    struct node {
        int data;
        node* next;
    };
    int size;
    node *head, *tail;  // first respectively last pointer

    // returns the value of the specified index
    node *getNodePtr(int n) {
        node *temp = head;
        for (int i = 0; i < n; i++) {
            temp = temp->next;
        }
        return temp;

    }

    int partition(int low, int high) {
        int pivot = getValue(high);
        int i = low - 1;
        for (int j = low; j <= high; j++) {
            // if current value is smaller than pivot, swap
            if (getValue(j) < pivot) {
                i++;
                swap(i, j);
            }
        }
        swap(i+1, high);
        return i + 1;
    }

    // Swaps the position of two elements
    void swap(int i, int j) {
        node *temp1 = getNodePtr(i);
        node *temp2 = getNodePtr(j);
        int temp;
        temp = temp1->data;
        temp1->data = temp2->data;
        temp2->data = temp;
    }

    // returns a random integer given a range
    int getRandInt(int low, int high) {
        if (high < low) {
            std::cout << "High bound has to be higher than lower!" << '\n';
            return 0;
        }
        // initialise random seed
        srand (time(NULL));
        return rand()%(high-low) + low;
    }

    public: // herer goes the functions
    LinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    // Adds a new integer at the end of the list
    void push(int n) {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        size++;

        if(head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    // prints the list in order
    void printList() {
        node *temp = head;
        std::cout << "[";
        while (temp != NULL) {
            if (temp->next != NULL) {
                std::cout << temp->data << ", ";
            }
            else {
                std::cout << temp->data << "]" << std::endl;
            }
            temp = temp->next;
        }
    }

    // returns the value of the specified index
    int getValue(int n) {
        node *temp = head;
        int endCondition;
        if (n < 0) {
            endCondition = size + n;
        }
        else {
            endCondition = n;
        }
        for (int i = 0; i < endCondition; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // returns the number of elements in the list
    int getSize() {
        return size;
    }

    void randomize() {
        for (int i = 0; i <  9 * size; i++) {
            swap(getRandInt(0, size), getRandInt(0, size));
        }
    }

    // sorts the list using quicksort
    void quickSort(int low = 0, int high = -1) {
        // fo the first call of the method
        if (high == -1) {
            high = size-1;
        }

        if (low < high)
        {
            int pi = partition(low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

};


int main() {
    LinkedList list;
    for (int i = 10; i > 0; i--) {
        list.push(i);
    }
    list.randomize();
    list.printList();
    return 0;
}
