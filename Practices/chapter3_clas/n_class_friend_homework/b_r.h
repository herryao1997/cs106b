#ifndef B_R_H
#define B_R_H

class Book;

class Ruler{
private:
    int weight;
public:
    void setWeight(int rw);
    friend int totalWeight(Ruler &r, Book &b);
};

class Book{
private:
    int weight;
public:
    void setWeight(int bw);
    friend int totalWeight(Ruler &r, Book &b);
};

int totalWeight(Ruler &r, Book &b);

#endif // B_R_H
