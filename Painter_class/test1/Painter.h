#ifndef Painter_h
#define Painter_h

class fclass {
    public:
        fclass();
        void setup();
        void spiral();
        void grid();
        void lat_lines();
        void lon_lines();
    private:
        static void forwardstep1();
        static void backwardstep1();
        static void forwardstep2();
        static void backwardstep2();
        int Wheel(byte WheelPos);
};

extern fclass Painter;

#endif
