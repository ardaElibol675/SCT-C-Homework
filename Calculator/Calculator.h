class Calculator {

    private:
    float n1, n2;

    public:
    Calculator(float x, float y):
        n1(x), n2(y) {}
    Calculator(float x):
        n1(x) {}
    
    void addition();
    void subtraction();
    void multiplication();
    void division();
    void square();
    void exponentiation();
    void modulus();

};
