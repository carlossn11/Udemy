class Mystring {
public:
  void displayStr();
  Mystring(const char* str);
  ~Mystring();
  Mystring(Mystring &&rhs);
  Mystring(const Mystring &rhs);
private:
  char* str;

};