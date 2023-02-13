#ifndef STRING_H
#define STRING_H


class String
{
private:
    char *sbuf;
    int length;
public:
    /*initialization a empty string*/
    String();

    /*initialization with a string*/
    String(char *s);

    virtual ~String();

    void Show();
};

#endif // STRING_H
