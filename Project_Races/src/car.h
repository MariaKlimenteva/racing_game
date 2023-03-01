


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

    public:
        car_t();
        bool is_valid();
        void set_color(unsigned color);
        void set_coordinates(double x, double y, double direction);
        void print();
        double get_x();
        double get_y();
}