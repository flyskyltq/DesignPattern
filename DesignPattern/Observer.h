#pragma once

/*
*   观察者模式
*/

#include <list>
#include <iostream>


class Subject;
class Observer {
  public:
    virtual void update(Subject* sub) = 0;
  private:
};

class ObserverA : public Observer {
  public:
    void update(Subject* sub) override;
};

class ObserverB : public Observer {
  public:
    void update(Subject* sub) override;
};

class Subject {
  public:
    Subject(std::string str)
        : state_(str) {
    }
    void attach(Observer* obj) {
        observers_.push_back(obj);
    }
    void detach(Observer* obj) {
        observers_.remove(obj);
    }
    virtual void notify() {
        for (auto* obj : observers_) {
            obj->update(this);
        }
    }
    virtual std::string getStates() {
        return state_;
    }
  protected:
    std::list<Observer*> observers_;
    std::string state_;
};

class SubjectA : public Subject {
  public:
    SubjectA(std::string state) : Subject(state) {
    }
    void notify() override {
        std::cout << "SubjectA Notify" << std::endl;
        Subject::notify();
    }
};

class SubjectB : public Subject {
  public:
    SubjectB(std::string state) : Subject(state) {
    }
    void notify() override {
        std::cout << "SubjectB Notify" << std::endl;
        Subject::notify();
    }
};


inline int test_observer() {
    Subject* sa = new SubjectA("subject a");
    Subject* sb = new SubjectB("subject b");
    Observer* oa = new ObserverA();
    ObserverB* ob = new ObserverB;
    sa->attach(oa);
    sa->attach(ob);
    sa->notify();
    sb->attach(oa);
    sb->attach(ob);
    sb->notify();
    // delete ...
    return 0;
}
