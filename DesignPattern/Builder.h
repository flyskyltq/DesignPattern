#pragma once
/*
*   建造者模式
*/
#include <iostream>

class Builder {
  public:
    Builder();
    ~Builder();
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildLeftArm() = 0;
    virtual void buildRightArm() = 0;
    virtual void buildLeftLeg() = 0;
    virtual void buildRightLeg() = 0;
};

#define  STD_OUT_INFO std::cout << typeid(*this).name() << " " << __FUNCTION__ << std::endl;

class FastBuilder : public Builder {
  public:
    void buildHead() override {
        STD_OUT_INFO
    }
    void buildBody() override {
        STD_OUT_INFO
    }
    void buildLeftArm() override {
        STD_OUT_INFO
    }
    void buildRightArm() override {
        STD_OUT_INFO
    }
    void buildLeftLeg() override {
        STD_OUT_INFO
    }
    void buildRightLeg() override {
        STD_OUT_INFO
    }
};

class ThinBuilder : public Builder {
  public:
    void buildHead() override {
        STD_OUT_INFO
    }
    void buildBody() override {
        STD_OUT_INFO
    }
    void buildLeftArm() override {
        STD_OUT_INFO
    }
    void buildRightArm() override {
        STD_OUT_INFO
    }
    void buildLeftLeg() override {
        STD_OUT_INFO
    }
    void buildRightLeg() override {
        STD_OUT_INFO
    }
};


class Director {
  public:
    Director(Builder* builder)
        : builder_(builder) {
    }
    void create() {
        builder_->buildHead();
        builder_->buildBody();
        builder_->buildLeftArm();
        builder_->buildRightArm();
        builder_->buildLeftLeg();
        builder_->buildRightLeg();
    }
  private:
    Builder* builder_;
};

inline int test_builder() {
    std::cout << "Build Fat" << std::endl;
    Builder* fat = new FastBuilder;
    Builder* thin = new ThinBuilder;
    Director* director = new Director(fat);
    director->create();
    std::cout << "Build Thin" << std::endl;
    Director* director2 = new Director(thin);
    director2->create();
    return 0;
}
