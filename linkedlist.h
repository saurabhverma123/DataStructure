#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
#include "graph.h"
template <typename T>
struct node {

    T data;
    node* next;
};

class LinkedList
{
   node<int> * head;
public:
    LinkedList();

    void printData(){
        node<int> *start=head;
        while(start!=nullptr)
        {
            cout<<start->data <<endl;
            start=start->next;
        }
        cout << "----";
    }

    node<int> * findMiddle(){
        node<int> *fast = head;
        node<int> *slow= head;
        while (fast)
        {

            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    void swapNode(int v1, int v2)
    {
        node<int> *cur1 = head;
        node<int> *cur2 = head;
        node<int> *prev1{nullptr};
        node<int> *prev2{nullptr};
        if (v1==v2)
            return ;

        while(cur1 && cur1->data !=v1)
        {
            prev1=cur1;
            cur1=cur1->next;
        }

        while(cur2 && cur2->data !=v2)
        {
            prev2=cur2;
            cur2=cur2->next;
        }

        if (!(cur1 || cur2))
            return;

        if (prev1)
        {
            prev1->next = cur2;
        }
        else
        {
            // head node cur1
            head = cur2;
        }
        if (prev2)
        {
            prev2->next = cur1;
        }
        else
        {
            // head node cur2
            head = cur1;
        }
        node<int> * temp = cur1->next;
        cur1->next = cur2->next;
        cur2->next = temp;
    }

    void addNode(int idata){
        node<int> *start=head;
        if (!start)
        {
            start = new node<int>;
            start->data = idata;
            start->next = nullptr;
            head=start;
        }
        else
        {
            for (;start->next != nullptr ;start=start->next);
            node<int> *newNode=new node<int>;
            newNode->data = idata;
            newNode->next=nullptr;
            start->next=newNode;

        }
    }

    bool has_cycle(){
        node<int> * fast{head};
            node<int> * slow{head};
            bool retVal{false};
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (fast == slow){
                    retVal = true;
                    break;
                }
            }
            return retVal;
    }

};

#endif // LINKEDLIST_H
