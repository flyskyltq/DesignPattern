#pragma once
/*
*   组合模式
*/

#include <iostream>
#include <set>

//Component
class Component {
  public:
    virtual void operation() {};
    virtual void add(Component* comp) {}
};
class Composite : public Component {
  public:
    void operation() override {
        std::cout << "Composite{" << std::endl;

        for (auto* comp : comps_) {
            comp->operation();
        }

        std::cout << "}" << std::endl;
    }
    void add(Component* comp) override {
        comps_.insert(comp);
    }
    ~Composite() {
        for (auto* comp : comps_) {
            if (comp) {
                delete comp;
                comp = nullptr;
            }
        }

        comps_.clear();
    }
  private:
    std::set<Component*> comps_;
};

class Leaf : public Component {
  public:
    void operation() override {
        std::cout << "Leaf Operation" << std::endl;
    }
};

inline int test_composite() {
    Component* root = new Composite;
    Component* leaf1 = new Leaf;
    Component* leaf2 = new Leaf;
    Component* compsite = new Composite;
    Component* cleaf1 = new Leaf;
    Component* cleaf2 = new Leaf;
    compsite->add(cleaf1);
    compsite->add(cleaf2);
    root->add(leaf1);
    root->add(leaf2);
    root->add(compsite);
    root->operation();

    if (root) {
        delete root;
        root = nullptr;
    }

    return 0;
}

