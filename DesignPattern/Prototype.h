#pragma once

/*
*   ԭ��ģʽ
*/

#include <iostream>

class Prototype {
  public:
    Prototype();
    ~Prototype();
    virtual Prototype* clone() = 0;
    virtual void operation() = 0;
};

class ConcretePrototypeA : public Prototype {
  public:
    Prototype* clone() override {
        //Ĭ�ϵĿ���������ǳ����������û��ָ�룬�˴�û��Ӱ��
        return new ConcretePrototypeA(*this);
    }
    void operation() override {
        std::cout << "ConcretePrototypeA operation" << std::endl;
    }
};

class ConcretePrototypeB : public Prototype {
  public:
    Prototype* clone() override {
        //Ĭ�ϵĿ���������ǳ����������û��ָ�룬�˴�û��Ӱ��
        return new ConcretePrototypeB(*this);
    }
    void operation() override {
        std::cout << "ConcretePrototypeB operation" << std::endl;
    }
};

inline int test_prototype() {
    std::cout << "New Prototype" << std::endl;
    Prototype* cb = new ConcretePrototypeB;
    Prototype* cb_copy = cb->clone();
    std::cout << "Delete Prototype" << std::endl;
    delete cb;
    cb = nullptr;
    cb_copy->operation();
    delete cb_copy;
    cb_copy = nullptr;
    return 0;
}

