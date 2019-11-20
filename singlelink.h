#pragma once

#include<iostream>
using std::ostream; using std::cout; using std::endl;

struct Node{
public:
    int data_;
    Node *next_;

    
    Node() : data_( 0 ), next_(nullptr) {};
    Node(int d) : data_(d), next_(nullptr) {};
};

class SingleLink{
private:
    Node *head_;
    Node *tail_;
  
public:
  void append_back(int);

  friend ostream& operator<<(ostream &out, SingleLink & s);
  bool del(int val);
  //Node& operator[](size_t index);
  
  // Rule of three stuff
  SingleLink(){
      head_=nullptr;
      tail_=nullptr;
  }
  SingleLink(int dat){
      Node *a = new Node(dat);
      head_=a;
      tail_=a;
  }
  SingleLink(const SingleLink &);
  SingleLink& operator=(SingleLink);
  
};

  