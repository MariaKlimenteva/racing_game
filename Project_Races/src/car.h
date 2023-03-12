
#define K 0.01
#define ACCURACY 0.00001

bool is_zero(double var);
bool is_equal(double var1, double var2);
int sign (double var);




class car_t {
    private:
        unsigned color_;
        double x_;
        double y_;
        double direction_;
        double speed_;
        double max_speed_;
        double turning_radius_;
        double acceleration_;
    /*
        FORWARD BUTTON
        BACKWARD BUTTON
        LEFT BUTTON
        RIGHT BUTTON
        BREAK BUTTON
    */
        int timer_;
        

    public:
        car_t();
        car_t(unsigned color, double max_speed, double turning_radius, double acceleration);
        car_t(unsigned color, double x, double y, double direction_, double max_speed, double turning_radius, double acceleration);
        void init(unsigned color, double x, double y, double direction_, double max_speed, double turning_radius, double acceleration);
        void init(unsigned color, double max_speed, double turning_radius, double acceleration);
        bool is_valid();
        void set_color(unsigned color);
        void set_coordinates(double x, double y, double direction);
        void print();
        double get_x();
        double get_y();
        void move();
};