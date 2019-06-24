#include <iostream>

using namespace std;

struct ElementStack{
    ElementStack* next;
    char value;
};

void addElement(ElementStack*& end, char ch){
    end->value = ch;
    end->next = new ElementStack;
    end = end->next;
}

ElementStack* createStack(){
    return new ElementStack;
}

void deletePrevLastElem(ElementStack* begin, ElementStack* end){
    while(begin->next->next->next != end){
        begin = begin->next;
    }
    ElementStack* del = begin->next;
    begin->next = begin->next->next;
    delete del;
}

void clear(ElementStack*& begin, ElementStack* end){
    while(begin != end){
        ElementStack* del = begin;
        begin = begin->next;
        delete del;
    }
}

int main()
{
    ElementStack* begin = createStack();
    ElementStack* end = begin;


    const int N = 5;
    char inputChar;
    for(int i(0); i < N; i++)
    {
        cin >> inputChar;
        addElement(end, inputChar);
    }
    ElementStack* beg = begin;
    for(auto beg(begin); beg != end; beg = beg->next){
        cout << beg->value;
        if(beg->next != end){
            cout << " -> ";
        }
    }
    cout << endl;
    deletePrevLastElem(begin, end);
    for(auto beg(begin); beg != end; beg = beg->next){
        cout << beg->value;
        if(beg->next != end){
            cout << " -> ";
        }
    }
    cout << endl;
    clear(begin, end);
    return 0;
}
