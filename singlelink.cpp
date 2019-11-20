#include "singlelink.h"
#include<stdexcept>
using std::out_of_range;
#include <iostream>
using std::ostream;

void SingleLink::append_back(int dat){
    Node *a = new Node(dat);
    if(tail_ != nullptr){
        tail_->next_  = a;
        tail_=a;
    }else{
        head_=a;
        tail_=a;
    }
}

ostream& operator<<(ostream &out, SingleLink & s){
    for(auto i = s.head_; i !=nullptr;i = i->next_){
        out << i->data_<<" ";
    }
    return out;
}

bool SingleLink::del(int val){
    Node *previous,*current;
    previous = current = head_;
    bool found = false;
    if(head_->data_== val){
        head_ = head_->next_;
        found = true;
    }else{
        while(current !=nullptr) {
           if(current->data_ == val){
                previous->next_ = current->next_;
                found = true;
            } 
            previous = current;
            current = current->next_;
        }
    }
    return found;
}
/*
Node& SingleLink::operator[](size_t index){
    
}
*/
int main() {
    SingleLink s;
    s.append_back(3);
    s.append_back(4);
    std::cout << "Two Items: " << s << std::endl;
    s.~SingleLink();
    //delete s.head_;
    //delete s.tail_;
    SingleLink s2(10);
    s2.append_back(3);
    s2.append_back(4);
    std::cout << "Three Items: " << s2 << std::endl;
    //delete s.head_;
    //delete s.tail_;
    
    s2.del(3);
    std::cout << "Removed 3: " << s2 << std::endl;
    s2.~SingleLink();
    /*
    SingleLink s3(56);
    s3.append_back(73);
    s3.append_back(345);
    s3.append_back(1);
    s3.append_back(15);
    std::cout << "Indexing 0: " << s3[0].data_ << std::endl;
    std::cout << "Indexing 1: " << s3[1].data_ << std::endl;
    std::cout << "Indexing 2: " << s3[2].data_ << std::endl;
    std::cout << "Indexing 3: " << s3[3].data_ << std::endl;
    std::cout << "Indexing 4: " << s3[4].data_ << std::endl;
    */
    
    
    
    
}