class Mystring {
public:
  void displayStr();
  Mystring(const char* str);
  ~Mystring();
  Mystring(Mystring &&rhs);
  Mystring(const Mystring &rhs);
  void operator=(const Mystring &rhs);
  void operator=(Mystring &&rhs);
private:
  char* str;

};