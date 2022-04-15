#ifndef MYEX_H_
#define MYEX_H_

class Mystring {
 public:
  // Constuctors & Destructors
  Mystring(const char* str);
  Mystring(const Mystring &rhs);
  Mystring(Mystring &&rhs);
  ~Mystring();

  // Overloaded Operators
  void operator=(const Mystring &rhs);
  void operator=(Mystring &&rhs);

  // Class Public Methods
  void displayStr();

 private:
  char* str;
};
#endif // MYEX_H_