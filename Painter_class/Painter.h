#ifndef Painter_h
#define Painter_h

class fclass {
    public:
        fclass();
        void setup();
        void spiral();
        void two();
        void three();
    private:
        static void forwardstep1();
        static void backwardstep1();
        static void forwardstep2();
        static void backwardstep2();
};

extern fclass Painter;

#endif
