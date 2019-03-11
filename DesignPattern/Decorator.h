#pragma once

/*
*   в╟йндёй╫
*/

#include <iostream>

//VisualComponent
class VisualComponent {
  public:
    virtual void draw() = 0;
};

//TextView
class TextView : public VisualComponent {
  public:
    void draw() override {
        std::cout << "TextView Draw." << std::endl;
    }
};

//Decorator
class Decorator : public VisualComponent {
  public:
    Decorator(VisualComponent* vc)
        : vc_(vc) {
    }
    void draw() override {
        vc_->draw();
    }
  private:
    VisualComponent* vc_;
};

//ScrollDecorator
class ScrollDecorator : public Decorator {
  public:
    ScrollDecorator(VisualComponent* vc)
        : Decorator(vc) {
    }
    void scroll() {
        std::cout << "Scroll" << std::endl;
    }
    void draw() override {
        Decorator::draw();
        scroll();
    }
};

//BorderDecorator
class BorderDecorator : public Decorator {
  public:
    BorderDecorator(VisualComponent* vc)
        : Decorator(vc) {
    }
    void drawBorder() {
        std::cout << "Draw Border" << std::endl;
    }
    void draw() override {
        Decorator::draw();
        drawBorder();
    }
};

#define Delete_ptr(ptr) \
    if(ptr){    \
        delete ptr; \
        ptr = nullptr;  \
    }

inline int test_decorator() {
    VisualComponent* text_view = new TextView;
    VisualComponent* scroll_text_view = new ScrollDecorator(text_view);
    VisualComponent* border_scroll_text_view = new BorderDecorator(scroll_text_view);
    border_scroll_text_view->draw();
    Delete_ptr(text_view);
    Delete_ptr(scroll_text_view);
    Delete_ptr(border_scroll_text_view);
    return 0;
}

