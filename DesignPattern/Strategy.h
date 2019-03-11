#pragma once
/*
*   策略模式
*/

#include <iostream>

class Strategy {
  public:
    Strategy();
    ~Strategy();
    virtual void algorithm() = 0;   //不同策略有不同的算法
};

class StrategyA : public Strategy {
  public:
    void algorithm() override {
        std::cout << "StrategyA Algorithm" << std::endl;
    }
};

class StrategyB : public Strategy {
  public:
    void algorithm() override {
        std::cout << "StrategyB Algorithm" << std::endl;
    }
};

class Context {
  public:
    Context(Strategy* strategy)
        : strategy_(strategy) {
    }
    void doAlgorithm() {
        strategy_->algorithm();
    }
  private:
    Strategy* strategy_;
};

inline int test_strategy() {
    Strategy* sa = new StrategyA;
    Context* context = new Context(sa);
    context->doAlgorithm();

    if (sa) {
        delete sa;
        sa = nullptr;
    }

    if (context) {
        delete context;
        context = nullptr;
    }

    return 0;
}
